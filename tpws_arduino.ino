#define LEDPin 2
#define piezzoPin 3
#define TestPin 4
#define ClearPin 5
int ledState = 0;
int piezzoClearState = 0;
int 
void setup() {
   pinMode(piezzoPin, OUTPUT);
   pinMode(LEDPin, OUTPUT);
   pinMode(TestPin, INPUT_PULLUP);
   pinMode(ClearPin, INPUT_PULLUP);
}

void loop() {
  int clearState = digitalRead(ClearPin);
  int testState = digitalRead(TestPin);
  if(testState == HIGH && clearState == LOW){
    ledState == 1;
    digitalWrite(LEDPin, 1);
    tone(piezzoPin, 600);
    if(piezzoClearState != 0){
      piezzoClearState = 0;
    }
  }
  if(clearState == HIGH && testState == LOW){
    ledState == 0;
    digitalWrite(LEDPin, 0);
    if(piezzoClearState == 0){
      tone(piezzoPin, 1000);
      piezzoClearState = 1;
    }
    noTone(piezzoPin);
  }
}
