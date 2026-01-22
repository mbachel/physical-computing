const int LED_G=2; //green LED pin 2
const int LED_Y=1; //yellow LED pin 1
const int LED_R=0; //red LED pin 0

void setup() {
  pinMode(LED_G, OUTPUT);
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_R, OUTPUT);
}

void loop() {
  //turn green on, others off
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_G, HIGH);
  delay(4000); //delay 4s

  //blink green 3 times, 100ms delay for each
  digitalWrite(LED_G, LOW);
  delay(100);
  digitalWrite(LED_G, HIGH);
  delay(100);
  digitalWrite(LED_G, LOW);
  delay(100);
  digitalWrite(LED_G, HIGH);
  delay(100);
  digitalWrite(LED_G, LOW);
  delay(100);
  digitalWrite(LED_G, HIGH);
  delay(100);

  //turn yellow on, others off
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_Y, HIGH);
  digitalWrite(LED_G, LOW);
  delay(1500); //delay 1.5s

  //blink yellow 3 times, 100ms delay for each
  digitalWrite(LED_Y, LOW);
  delay(100);
  digitalWrite(LED_Y, HIGH);
  delay(100);
  digitalWrite(LED_Y, LOW);
  delay(100);
  digitalWrite(LED_Y, HIGH);
  delay(100);
  digitalWrite(LED_Y, LOW);
  delay(100);
  digitalWrite(LED_Y, HIGH);
  delay(100);

  //turn red on, others off
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_Y, LOW);
  digitalWrite(LED_G, LOW);
  delay(5000); //delay 4s

  //blink red 3 times, 100ms delay for each
  digitalWrite(LED_R, LOW);
  delay(100);
  digitalWrite(LED_R, HIGH);
  delay(100);
  digitalWrite(LED_R, LOW);
  delay(100);
  digitalWrite(LED_R, HIGH);
  delay(100);
  digitalWrite(LED_R, LOW);
  delay(100);
  digitalWrite(LED_R, HIGH);
  delay(100);
}