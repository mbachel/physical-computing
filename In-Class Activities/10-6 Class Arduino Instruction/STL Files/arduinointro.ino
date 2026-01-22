int led_red = 0; //red LED to pin 0
int led_yellow = 1; //yellow LED to pin 1
int led_green = 2; //green LED to pin 2

void setup() {
  //initialize and turn each pin into outputs
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);
}
void loop() {
  //turn green LED on, others off
  digitalWrite(led_red, LOW);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_green, HIGH);
  delay(4000); //wait 4 seconds
  
  //blink green 3 times, 100ms of delay between
  digitalWrite(led_green, LOW);
  delay(100);
  digitalWrite(led_green, HIGH);
  delay(100);
  digitalWrite(led_green, LOW);
  delay(100);
  digitalWrite(led_green, HIGH);
  delay(100);
  digitalWrite(led_green, LOW);
  delay(100);
  digitalWrite(led_green, HIGH);
  delay(100);
  
  
  //turn yellow LED on, others off
  digitalWrite(led_red, LOW);
  digitalWrite(led_yellow, HIGH);
  digitalWrite(led_green, LOW);
  delay(1500); //wait 1.5 seconds
  
  //blink yellow 3 times, 100ms of delay between
  digitalWrite(led_yellow, LOW);
  delay(100);
  digitalWrite(led_yellow, HIGH);
  delay(100);
  digitalWrite(led_yellow, LOW);
  delay(100);
  digitalWrite(led_yellow, HIGH);
  delay(100);
  digitalWrite(led_yellow, LOW);
  delay(100);
  digitalWrite(led_yellow, HIGH);
  delay(100);
  
  //turn red LED on, others off
  digitalWrite(led_red, HIGH);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_green, LOW);
  delay(5000); //wait 5 seconds
  
  //blink red 3 times, 100ms of delay between
  digitalWrite(led_red, LOW);
  delay(100);
  digitalWrite(led_red, HIGH);
  delay(100);
  digitalWrite(led_red, LOW);
  delay(100);
  digitalWrite(led_red, HIGH);
  delay(100);
  digitalWrite(led_red, LOW);
  delay(100);
  digitalWrite(led_red, HIGH);
  delay(100);
}