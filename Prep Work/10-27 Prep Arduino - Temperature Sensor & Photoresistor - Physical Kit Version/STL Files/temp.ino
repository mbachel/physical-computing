// Temperature Alert!
const int BLED=9;      // Blue LED Cathode on Pin 9
const int GLED=10;     // Green LED Cathode on Pin 10
const int RLED=11;     // Red LED Cathode on Pin 11
const int TEMP=0;      // Temp Sensor is on pin A0

const int LOWER_BOUND=139; // Lower Threshold
const int UPPER_BOUND=147; // Upper Threshold

int val = 0;        // Variable to hold analog reading


void setup()
{
 pinMode (BLED, OUTPUT); // Set Blue LED as Output
 pinMode (GLED, OUTPUT); // Set Green LED as Output
 pinMode (RLED, OUTPUT); // Set Red LED as Output
 Serial.begin(9600);
}
  
void loop()
{
 val = analogRead(TEMP);
 Serial.println(val);

 // LED is Blue
 if (val < LOWER_BOUND)
 {
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, HIGH);
  Serial.println("Blue");
 }
 // LED is Red
 else if (val > UPPER_BOUND)
 {
  digitalWrite(RLED, HIGH);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, LOW);
  Serial.println("Red");
 }
 // LED is Green
 else
 {
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, HIGH);
  digitalWrite(BLED, LOW);
  Serial.println("Green");
 }
} 