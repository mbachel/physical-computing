const int LED=9; //init LED on pin 9
const int BUTTON=2; //init BUTTON on pin 2

void setup() {
  pinMode(LED, OUTPUT); //output for pin 9
  pinMode(BUTTON, INPUT); //input for pin 2
}

void loop() {
  //if button is pressed
  if (digitalRead(BUTTON) == HIGH) {
    //write no light to LED
    digitalWrite(LED, LOW);
  }
  else { //if button is not pressed
    //write light to LED
    digitalWrite(LED, HIGH);
  }
}