const int TEMP=0; //init analog pin 0
const int GRN=10; //init green on 10
const int RED=11; //init red on 11
const int BLU=9; //init blue on 9

const int LOWER_BOUND=148;
const int UPPER_BOUND=158;

int val = 0; //variable to hold analog reading

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GRN, OUTPUT);
  pinMode(BLU, OUTPUT);
}

void loop() {
  val = analogRead(TEMP);
  
  //LED is Blue
  if (val < LOWER_BOUND) {
    digitalWrite(BLU, HIGH);
    digitalWrite(GRN, LOW);
    digitalWrite(RED, LOW);
  }
  
  else if (val > UPPER_BOUND) {
    digitalWrite(RED, HIGH);
    digitalWrite(GRN, LOW);
    digitalWrite(BLU, LOW);
  }
  
  else {
    digitalWrite(GRN, HIGH);
    digitalWrite(BLU, LOW);
    digitalWrite(RED, LOW);
  }
  
  
}