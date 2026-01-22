const int MOTOR=9; //init motor pin 9
const int POT=0;

int val=0;

void setup() {
  pinMode(MOTOR, OUTPUT); //set pin 9 to output
  Serial.begin(9600);
}

void loop() {
  val = analogRead(POT);
  Serial.println(val);
  val = map(val, 0, 1023, 0, 255);
  Serial.println(val);
  analogWrite(MOTOR, val);
  delay(500);
  
  /*
  //from 0 to 255
  for (int i=0; i<256; i++) {
    analogWrite(MOTOR, i); //give the motor that number
    delay(10); //delay by 10ms between each change
  }
  delay(2000); //2 second delay
  //from 255 to 0
  for (int i=255; i>=0; i--) {
    analogWrite(MOTOR, i); //give the motor that number
    delay(10); //delay by 10ms between each change
  }
  delay(2000); //2 second delay
  */
}