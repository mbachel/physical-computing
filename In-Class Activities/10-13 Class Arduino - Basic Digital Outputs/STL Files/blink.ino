const int LED=9; //init pin 9 as LED

void setup() {
  pinMode(LED, OUTPUT); //put it in output mode
}

void loop() {
  //for loop, start at 100, build up by 100 until 1000, then reset
  for (int i=100; i<=1000; i=i+100) {
    digitalWrite(LED, HIGH); //turn it to high
    delay(i); //delay of i
    digitalWrite(LED, LOW); //turn it to low
    delay(i); //delay of i
  }
  
  //separator
  digitalWrite(LED, HIGH);
  delay(2000);
  digitalWrite(LED, LOW);
  delay(1000);
  
  //reveresed for loop
  for (int i=1000; i>=100; i=i-100) {
    digitalWrite(LED, HIGH);
    delay(i);
    digitalWrite(LED, LOW);
    delay(i);
  }
  
  //separator
  digitalWrite(LED, HIGH);
  delay(2000);
  digitalWrite(LED, LOW);
  delay(1000);
}