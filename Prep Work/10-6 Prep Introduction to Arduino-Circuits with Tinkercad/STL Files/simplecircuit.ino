// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(300); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(300); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(300); // Wait for 1000 millisecond(s)
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(4000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1500);
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(300); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(300); // Wait for 1000 millisecond(s)
}