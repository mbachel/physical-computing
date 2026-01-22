const int LED=9;        // Define LED for Pin 9
void setup()
{
 pinMode (LED, OUTPUT); // Set the LED pin as an output
}

void loop()
{
 for (int i=100; i<=1000; i=i+100)
 {
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

 //reverse loop
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