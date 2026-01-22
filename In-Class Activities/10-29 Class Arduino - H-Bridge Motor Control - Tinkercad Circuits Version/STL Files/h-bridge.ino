//H-bridge Motor Control
const int EN=9;   //Half Bridge 1 Enable
const int MC1=3;  //Motor Control 1
const int MC2=2;  //Motor Control 2
const int POT=0;  //POT on Analog Pin 0

int val = 0;      //for storing the reading from the POT
int velocity = 0; //For storing the desired velocity (from 0-255)

void setup()
{
    pinMode(EN, OUTPUT);
    pinMode(MC1, OUTPUT);
    pinMode(MC2, OUTPUT);
    brake(); //Initialize with motor stopped
  	Serial.begin(9600);
}

void loop()
{
    val = analogRead(POT);
 
    //go forward
    if (val > 562)
    {
        velocity = map(val, 563, 1023, 0, 255);
        forward(velocity);
    }
 
    //go backward
    else if (val < 462)
    {
        velocity = map(val, 461, 0, 0, 255);
        reverse(velocity);
    }
 
    //brake
    else
    {
        brake();
    }
  	Serial.print("Potentiometer: ");
  	Serial.print(val);
  	Serial.print(" <=> ");
  	Serial.print("Motor output: ");
  	Serial.println(velocity);
  	delay(500); //stop lag, enable higher values
}

//Motor goes forward at given rate (from 0-255)
void forward (int rate)
{
    analogWrite(EN, 0);
    digitalWrite(MC1, HIGH);
    digitalWrite(MC2, LOW);
    analogWrite(EN, rate);
}

//Motor goes backward at given rate (from 0-255)
void reverse (int rate)
{
    analogWrite(EN, 0);
    digitalWrite(MC1, LOW);
    digitalWrite(MC2, HIGH);
    analogWrite(EN, rate);
}

//Stops motor
void brake ()
{
    analogWrite(EN, 0);
    digitalWrite(MC1, LOW);
    digitalWrite(MC2, LOW);
    analogWrite(EN, 255);
}