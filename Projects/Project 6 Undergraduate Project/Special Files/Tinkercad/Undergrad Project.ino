#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define PCF8574_DAY_ADDR  0x20 //address for day PCF8574
#define PCF8574_TASK_ADDR 0x21 //address for task PCF8574
#define BUTTON 8 //pin for button (digital input)
#define POT A0 //pin for potentiometer (analog input)

//hardcoded time/date/day info for tinkercad
//this will be changed for actual project
int month = 11, dayOfMonth = 23; //MM/DD, no YY
int hour = 7, minute = 30; // HH:MM, no SS
bool isPM = false; //AM/PM
int currentDayOfWeek = 2; //day of weekas in integer
//int is the pin of the PCF8574
//0 = Saturday (P0), 1 = Friday (P1), ... 6 = Sunday(P6)
//no P7, because only 7 days in the week. P7 is grounded in circuit

//bool array to hold which tasks are complete/incomplete
bool taskComplete[5] = {false, false, false, false, false};

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(BUTTON, INPUT_PULLUP); //button between pin 8 and GND
}

void loop() {
  //display date on LCD
  lcd.setCursor(0, 0); //first row
  lcd.print("Date: ");
  if (month < 10) lcd.print("0"); //if month not 2 digits, add leading 0
  lcd.print(month);
  lcd.print("/");
  if (dayOfMonth < 10) lcd.print("0"); //if day not 2 digits, add leading 0
  lcd.print(dayOfMonth);

  //display time on LCD
  lcd.setCursor(0, 1); //second row
  lcd.print("Time: ");
  int dispHour = hour % 12; //put hour on 12 hour clock
  if (dispHour == 0) dispHour = 12; //if it is hour 0, set to 12
  if (dispHour < 10) lcd.print("0"); //if hour not 2 digits, add leading 0
  lcd.print(dispHour);
  lcd.print(":");
  if (minute < 10) lcd.print("0"); //if minute not 2 digits, add leading 0
  lcd.print(minute);
  lcd.print(isPM ? " PM" : " AM"); //if it is pm, print pm, otherwise print am
  
  //read pot. value, map to 0-4 (1-5 tasks)
  int potValue = analogRead(POT);
  int selectedTask = map(potValue, 0, 1023, 0, 4);

  //display selected task in serial monitor
  //this will be moved to the LED array on the Arduino for project
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
  
  //configure byte for day
  byte dayByte = 0xFF; //set all bits to on as default
  //switch case for setting individual days
  switch (currentDayOfWeek) {
    case 0: dayByte &= ~(1 << 0); break; //Saturday
    case 1: dayByte &= ~(1 << 1); break; //Friday
    case 2: dayByte &= ~(1 << 2); break; //Thursday
    case 3: dayByte &= ~(1 << 3); break; //Wednesda
    case 4: dayByte &= ~(1 << 4); break; //Tuesday
    case 5: dayByte &= ~(1 << 5); break; //Monday
    case 6: dayByte &= ~(1 << 6); break; //Sunday
    // P7 remains HIGH (unused)
  }
  
  //transmit to day chip
  Wire.beginTransmission(PCF8574_DAY_ADDR);
  Wire.write(dayByte);
  Wire.endTransmission();

  //configure byte for tasks
  byte taskByte = 0xFF; //set all bits to on as default
  for (int i = 0; i < 5; i++) {
    if (taskComplete[i]) {
      taskByte &= ~(1 << i); //P0 = task 1, P1 = task 2, etc.
    }
  }
  //P5-P7 remains HIGH (unused)
  
  //transmit to tasks chip
  Wire.beginTransmission(PCF8574_TASK_ADDR);
  Wire.write(taskByte);
  Wire.endTransmission();

  delay(500);
}
