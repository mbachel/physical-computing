#include <Wire.h> //include wire library for I2C
#include <LiquidCrystal.h> //include LCD library

//init LCD on 2, 3, 4, 5, 6, 7
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define PCF8574_INPUT_ADDR  0x20 //input address for first I2C port expander
#define PCF8574_OUTPUT_ADDR 0x21 //output address for second I2C port expander

#define SWITCH 0
#define POT A0

void setup() {
  Serial.begin(9600); //start serial monitor for debugging
  Wire.begin(); //start I2C
  lcd.begin(16, 2); //init LCD for 16 columns and 2 rows
  lcd.clear(); //clear on startup
  pinMode(SWITCH, INPUT); //set SWITCH pin as digital input
}

void loop() {
  int switches = digitalRead(SWITCH); //read slide switch position (will be 0 or 1)
  //this will be used to determine what mode to be in: binary input or decimal input

  int potValue = analogRead(POT);

  //serial prints for debugging
  Serial.print("Slide switch (SWITCH): ");
  Serial.println(switches); //display switch position (0 or 1)
  Serial.print("Potentiometer (POT): ");
  Serial.println(potValue); //display potentiometer reading (0-1023)

  if (switches == 0) {
    //binary input mode
    binaryInputMode();
  } 
  else {
    //decimal input mode
    decimalInputMode(potValue);
  }
  delay(500); //delay before next loop
}

void binaryInputMode() {
  Serial.println("Binary Input Mode"); //debugging message
  Wire.requestFrom(PCF8574_INPUT_ADDR, 1); //request 1 byte input from first port expander

  //set default input value
  byte inputVal = 0x00;
  //if data is available, read it
  if (Wire.available()) {
    inputVal = Wire.read(); 
    Serial.print("Binary: ");
    Serial.println(inputVal);
  }
  
  //create buffer of 9 chars (8 bits + null terminator)
  char buf[9];
  //convert byte to binary string
  for (int i = 0; i < 8; i++) {
    //extract each bit, set '1' or '0' in reverse order for display
    buf[7-i] = (inputVal & (1 << i)) ? '1' : '0';
  }
  //add null terminator
  buf[8] = '\0';

  //print binary string to serial monitor for debugging
  Serial.print("Binary input: ");
  Serial.println(buf);

  //display decimal conversion on LCD
  lcd.setCursor(0, 0); //move cursor to first row
  lcd.print("Dec: ");
  lcd.print((int)inputVal);
  lcd.print("      "); //clear remaining characters

  //display ASCII conversion on LCD
  lcd.setCursor(0, 1); //move cursor to second row
  lcd.print("ASCII: ");
  char dispChar = (char)inputVal; //convert byte to char
  if (dispChar < 32 || dispChar > 126) lcd.print("N/A"); //if no ASCII conversion exists, print message
  else lcd.print(dispChar); //else, print the conversion
  lcd.print("      "); //clear remaining characters

  //turn on LEDs corresponding to input bits
  Wire.beginTransmission(PCF8574_OUTPUT_ADDR); //begin transmission to second port expander
  Wire.write(~inputVal); //write inverted byte to turn on LEDs
  Wire.endTransmission(); //stop transmitting
}

void decimalInputMode(int potValue) {
  Serial.println("Decimal Input Mode"); //debugging message

  //map potentiometer value (0-1023) to range 0-255
  byte decimalValue = map(potValue, 0, 1023, 0, 255);
  Serial.print("Mapped decimal value: ");
  Serial.println(decimalValue); //display mapped decimal value

  //display decimal conversion on LCD
  lcd.setCursor(0, 0); //move cursor to first row
  lcd.print("Dec: ");
  lcd.print((int)decimalValue);
  lcd.print("      "); //clear remaining characters

  //display ASCII conversion on LCD
  lcd.setCursor(0, 1); //move cursor to second row
  lcd.print("ASCII: ");
  char dispChar = (char)decimalValue; //convert decimal value to char
  if (dispChar < 32 || dispChar > 126) lcd.print("N/A"); //if no ASCII conversion exists, print message
  else lcd.print(dispChar); //else, print the conversion
  lcd.print("      "); //clear remaining characters

  //convert decimal value to binary string for binary output
  char buf[9];
  for (int i = 0; i < 8; i++) {
      buf[i] = (decimalValue & (0x80 >> i)) ? '1' : '0';
  }
  buf[8] = '\0';

  Serial.print("Binary output: ");
  Serial.println(buf); //display binary output

  //turn on LEDs corresponding to decimal value bits
  Wire.beginTransmission(PCF8574_OUTPUT_ADDR); //begin transmission to second port expander
  Wire.write(~decimalValue); //write inverted byte to turn on LEDs
  Wire.endTransmission(); //stop transmitting
}