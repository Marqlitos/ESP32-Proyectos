const int led = 15;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  analogWrite(led,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<255; i++){
    analogWrite(led,i);
    delay (100);
    }
    for(int i = 255; i>0; i--){c:\Users\marco\OneDrive\Documents\Apuntes Principios electricos\Design1.ms14
      analogWrite(led, i);
      delay (10);
  }
}