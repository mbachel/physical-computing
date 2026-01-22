/*
Exploring Arduino, Second Edition
Code Listing 4-2: Adjustable Speed Control
https://www.exploringarduino.com/content2/ch4

Copyright 2019 Jeremy Blum ( https://www.jeremyblum.com )
Licensed under MIT ( https://github.com/sciguy14/Exploring-Arduino-2nd-Edition/blob/master/LICENSE.md )
*/

//Motor Speed Control with a Pot

const int MOTOR=9;  //Motor on Digital Pin 9
const int POT=0;    //POT on Analog Pin 0

int val = 0;
int temp = 0;

void setup()
{
    pinMode (MOTOR, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    val = analogRead(POT);
    temp = val;
    val = map(val, 0, 1023, 0, 255);
    analogWrite(MOTOR, val);
    Serial.print("Potentiometer: ");
    Serial.print(temp);
    Serial.print(" <=> Motor: ");
    Serial.println(val); // Use println on the last part to move to a new line
}