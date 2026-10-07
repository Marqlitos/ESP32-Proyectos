const int led = 15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led,0);
} 

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()){
    char c = Serial.read();

    if(c == 'a'){
      digitalWrite(led , 1);
    }

    if(c == 'b'){
      digitalWrite(led, 0);
    }
  }
}
