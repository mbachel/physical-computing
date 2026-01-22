/*
Exploring Arduino, Second Edition
Code Listing 4-3: H-Bridge Potentiometer Speed Control
https://www.exploringarduino.com/content2/ch4

Copyright 2019 Jeremy Blum ( https://www.jeremyblum.com )
Licensed under MIT ( https://github.com/sciguy14/Exploring-Arduino-2nd-Edition/blob/master/LICENSE.md )
*/

//H-bridge Motor Control
const int EN=9;   //Half Bridge 1 Enable
const int MC1=3;  //Motor Control 1
const int MC2=2;  //Motor Control 2
const int POT=A0;  //POT on Analog Pin 0

int val = 0;      //for storing the reading from the POT
int velocity = 0; //For storing the desired velocity (from 0-255)

void setup()
{
    pinMode(EN, OUTPUT);
    pinMode(MC1, OUTPUT);
    pinMode(MC2, OUTPUT);
    Serial.begin(9600);
    brake(); //Initialize with motor stopped
}

void loop()
{
    val = analogRead(POT);
    Serial.print("Potentiometer: (");
    Serial.print(val);
    Serial.print(") <=> Motor: (");
    //go forward
    if (val > 562)
    {
        velocity = map(val, 563, 1023, 0, 255);
        forward(velocity);
        Serial.print(velocity);
    }
 
    //go backward
    else if (val < 462)
    {
        velocity = map(val, 461, 0, 0, 255);
        reverse(velocity);
        Serial.print(velocity);
    }
 
    //brake
    else
    {
        brake();
    }
    Serial.println(")");
    delay(15);
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