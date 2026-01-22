#include <Servo.h>

const int SERVO=9;
const int POT=0;

Servo myServo;
int val = 0;

void setup() {
  myServo.attach(SERVO);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(POT);
  Serial.print("Potentiometer: (");
  Serial.print(val);
  val = map(val, 0, 1023, 0, 179);
  Serial.print(") <=> Servo: (");
  Serial.print(val);
  Serial.println(")");
  myServo.write(val);
  delay(15);
}