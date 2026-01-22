#include <Wire.h>
#include <LiquidCrystal.h>
#include "Arduino_LED_Matrix.h"

#include "RTC.h"
#include <NTPClient.h>
#include <WiFiS3.h>
#include <WiFiUdp.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define PCF8574_DAY_ADDR  0x38 //PCF8574 address for days
#define PCF8574_TASK_ADDR 0x39 //address for tasks
#define BUTTON 8 //pin for button input to toggle task completion
#define POT A0 //pin for potentiometer input to select task
ArduinoLEDMatrix matrix;

//wifi setup
//instance wifi credentials for RTC
const char ssid[] = "WIFI_NAME";
const char pass[] = "WIFI_PASSWORD";

int wifiStatus = WL_IDLE_STATUS;
WiFiUDP Udp;
NTPClient timeClient(Udp);

//create number digits for LED matrix
const uint32_t digit1[] = {
		0xe002002,
		0x200200,
		0x200200f8,
		66
};

const uint32_t digit2[] = {
		0xf001001,
		0xf00800,
		0x800800f0,
		66
};

const uint32_t digit3[] = {
		0xf001001,
		0xf00100,
		0x100100f0,
		66
};

const uint32_t digit4[] = {
		0x9009009,
		0xf00100,
		0x10010010,
		66
};

const uint32_t digit5[] = {
		0xf008008,
		0xf00100,
		0x100100f0,
		66
};

//function for printing wifi status, may not need
void printWiFiStatus() {
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.print("Signal strength (RSSI): ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
}

//function to connect to wifi
void connectToWiFi() {
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");
        while (true); //if no wifi module, hang
    }

    String fv = WiFi.firmwareVersion();
    if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
        Serial.println("Please upgrade the firmware");
    }

    while (wifiStatus != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        wifiStatus = WiFi.begin(ssid, pass);
        delay(10000);
    }
}

//function to display task number on LED matrix
void displayTaskNumber(uint8_t n) {
  switch (n) {
    case 1:
      matrix.loadFrame(digit1);
      break;
    case 2:
      matrix.loadFrame(digit2);
      break;
    case 3:
      matrix.loadFrame(digit3);
      break;
    case 4:
      matrix.loadFrame(digit4);
      break;
    case 5:
      matrix.loadFrame(digit5);
      break;
    default: //clear matrix when invalid input
      {
        uint32_t clearFrame[3] = {0, 0, 0};
        matrix.loadFrame(clearFrame);
      }
      break;
  }
}


//bool array to hold which tasks are complete/incomplete
bool taskComplete[5] = {false, false, false, false, false};

void setup() {
    Serial.begin(9600); //serial for debugging
    while (!Serial); //wait for serial monitor to open

    //wifi setup
    connectToWiFi();
    RTC.begin();
    Serial.println("\nStarting connection to server...");
    timeClient.begin();
    timeClient.update();

    //get current date and time from NTP server and convert to UTC +5
    auto timeZoneOffsetHours = -5;
    auto unixTime = timeClient.getEpochTime() + (timeZoneOffsetHours * 3600);
    Serial.print("Unix time: ");
    Serial.println(unixTime);
    RTCTime timeToSet = RTCTime(unixTime);
    RTC.setTime(timeToSet); //set RTC time

    RTCTime currentTime;
    RTC.getTime(currentTime);
    Serial.println("The RTC time is set to: " + String(currentTime));

    pinMode(BUTTON, INPUT_PULLUP); //button with pull-up resistor
    Wire.begin(); //wire for I2C communication
    lcd.begin(16, 2); //begin and clear LCD
    lcd.clear();
    matrix.begin(); //begin LED matrix on arduino
}

void loop() {
    Serial.println("----------------------");
    //set current time from RTC
    RTCTime currentTime;
    RTC.getTime(currentTime);
    Serial.println("The RTC time is set to: " + String(currentTime));
    int month = (int)currentTime.getMonth() + 1;
    Serial.print("Month: ");
    Serial.println(month);
    int dayOfMonth = (int)currentTime.getDayOfMonth();
    Serial.print("Day: ");
    Serial.println(dayOfMonth);
    int hour_raw = (int)currentTime.getHour();
    int minute = (int)currentTime.getMinutes();
    bool isPM = (hour_raw >= 12);
    int dispHour = hour_raw % 12;
    if (dispHour == 0) dispHour = 12;
    Serial.print("Time: ");
    Serial.print(dispHour);
    Serial.print(":");
    Serial.print(minute);
    Serial.println(isPM ? " PM" : " AM");

    //lcd output
    lcd.setCursor(0, 0);
    lcd.print("Date: ");
    if (month < 10) lcd.print("0");
    lcd.print(month);
    lcd.print("/");
    if (dayOfMonth < 10) lcd.print("0");
    lcd.print(dayOfMonth);

    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    if (dispHour < 10) lcd.print("0");
    lcd.print(dispHour);
    lcd.print(":");
    if (minute < 10) lcd.print("0");
    lcd.print(minute);
    lcd.print(isPM ? " PM" : " AM");

    //get the day of the week (Monday = 1, Tuesday = 2 )
    int dayOfWeek = (int)currentTime.getDayOfWeek();
    //map to Saturday = 6 (P6), Friday = 5 (P5), ..., Sunday = 0 (P0)
    int mappedDay = 6 - dayOfWeek;

    //get potentiometer and map to task index (0-4)
    int potValue = analogRead(POT);
    int selectedTask = constrain(map(potValue, 0, 1023, 0, 4), 0, 4);
    
    //display selected task on LED array and on serial
    displayTaskNumber(selectedTask + 1);
    Serial.print("Selected Task: ");
    Serial.println(selectedTask + 1);

    //button debounce
    static bool last = HIGH; //INPUT_PULLUP, so off by default = HIGH
    bool current = digitalRead(BUTTON); //LOW when pressed
    if (last == HIGH && current == LOW) {
        //set the selected task to the opposite of what it currently is
        //this allows toggle functionality from button
        taskComplete[selectedTask] = !taskComplete[selectedTask];
        delay(200);
    }
    last = current; //reset state

    //day byte (active-low, mapped)
    byte dayByte = 0xFF; //all high (inactive)
    dayByte &= ~(1 << mappedDay); //set mapped day bit to low (active)
    Wire.beginTransmission(PCF8574_DAY_ADDR);
    Wire.write(dayByte); //transmit day byte to 0x38
    Wire.endTransmission();

    //task byte (active-low, P0=Task1 ... P4=Task5)
    byte taskByte = 0xFF;
    for (int i = 0; i < 5; i++) {
        if (taskComplete[i]) {
        taskByte &= ~(1 << i);
        }
    }
    
    //display tasks on the serial monitor
    Serial.print("Tasks: ");
    for (int i=0; i<5; i++) {
      Serial.print(taskComplete[i] ? "1" : "0");
    }
    Serial.print(" taskByte: ");
    Serial.println(taskByte, BIN);
    
    Wire.beginTransmission(PCF8574_TASK_ADDR);
    Wire.write(taskByte); // Active-low
    Wire.endTransmission();

    Serial.println("----------------------");
    delay(1000); //update every second for easier reading on serial monitor
}
