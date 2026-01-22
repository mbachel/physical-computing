#include "Arduino_LED_Matrix.h"   //Include the LED_Matrix library

// Create an instance of the ArduinoLEDMatrix class
ArduinoLEDMatrix matrix;  

void setup() {
  Serial.begin(115200);
  matrix.loadSequence(LEDMATRIX_ANIMATION_BUG);
  matrix.begin();
  matrix.play(true);
}

void loop() {
}
