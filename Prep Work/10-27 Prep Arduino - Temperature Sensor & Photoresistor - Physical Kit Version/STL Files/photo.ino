
// Automatic Night Light

const int WLED=9;        // White LED Anode on pin 9 (PWM)
const int LIGHT=0;       // Light Sensor on Analog Pin 0
const int MIN_LIGHT=200; // Minimum Expected light value
const int MAX_LIGHT=900; // Maximum Expected Light value
int val = 0;             // Variable to hold the analog reading

void setup()
{
 pinMode(WLED, OUTPUT);  // Set White LED pin as output
 Serial.begin(9600);
}

void loop()
{
 val = analogRead(LIGHT);                      // Read the light sensor
 Serial.println(val);
 val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0); // Map the light reading
 val = constrain(val, 0, 255);                 // Constrain light value
 Serial.println(val);
 analogWrite(WLED, val);                       // Control the White LED
}