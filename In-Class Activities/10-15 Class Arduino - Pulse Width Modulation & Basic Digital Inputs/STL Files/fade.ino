const int LED=9; //set variable for pin 9

void setup() {
  pinMode(LED, OUTPUT); //output mode for pin 9
}

void loop() {
  for (int i=0; i<256; i++) {
    analogWrite(LED, i);
    delay(10);
  } //slowly goes from 0 brightness up to 255 brightness
  //with 10ms delay
  
  for (int i = 255; i>=0; i--) {
    analogWrite(LED, i);
    delay(10);
  } //slowly goes from 255 brightness down to 0 brightness
  //with 10ms delay
  
  //second light fade
  for (int i=0; i<256; i++) {
    analogWrite(LED, i);
    delay(50);
  } //slowly goes from 0 brightness up to 255 brightness
  //with 10ms delay
  
  for (int i = 255; i>=0; i--) {
    analogWrite(LED, i);
    delay(50);
  } //slowly goes from 255 brightness down to 0 brightness
  //with 10ms delay
}