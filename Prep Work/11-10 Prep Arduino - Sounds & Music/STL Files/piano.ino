#define NOTE_C  262 //Hz
#define NOTE_D  294 //Hz
#define NOTE_E  330 //Hz
#define NOTE_G  392 //Hz
#define NOTE_A  440 //Hz

const int SPEAKER=9;   //Speaker on Pin 9

const int BUTTON_C=7;  //Button Pin
const int BUTTON_D=6;  //Button Pin
const int BUTTON_E=5;  //Button Pin
const int BUTTON_G=4;  //Button Pin
const int BUTTON_A=3;  //Button Pin


void setup()
{
  Serial.begin(9600);
 //No setup needed
 //Tone function sets outputs
}

void loop()
{
  bool a = digitalRead(BUTTON_A);
  bool c = digitalRead(BUTTON_C);
  bool d = digitalRead(BUTTON_D);
  bool e = digitalRead(BUTTON_E);
  bool g = digitalRead(BUTTON_G);

  if(!a && !c && !d && !e && !g){
    noTone(SPEAKER);
  } else {
    if(a){
      tone(SPEAKER, NOTE_A);
    }
    if(c){
      tone(SPEAKER, NOTE_C);
    }
    if(d){
      tone(SPEAKER, NOTE_D);
    }
    if(e){
      tone(SPEAKER, NOTE_E);
    }
    if(g){
      tone(SPEAKER, NOTE_G);
    }
  }
  
 
 //Stop playing if all buttons have been released

}