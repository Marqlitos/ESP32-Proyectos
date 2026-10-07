long tiempo; 
float distancia;
const int echo = 17;
const int trig = 18;

int ledA = 15;
int ledB = 2;
int ledC = 4;
int ledD = 16;

void setup() {

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(1);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo / 52;
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" CM");
  delay(500);

  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, LOW);

  if(distancia > 1 && distancia <= 5){
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, LOW);
      digitalWrite(ledD, LOW);
  }

  else if(distancia >= 6 && distancia <= 10){
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, HIGH);  
  }

  else if (distancia >= 11 && distancia <= 15){
     digitalWrite(ledC, HIGH);
     digitalWrite(ledB, LOW);
     digitalWrite(ledA, LOW);
     digitalWrite(ledD, LOW);
  }

  else if (distancia >= 16){
     digitalWrite(ledD, HIGH);
     digitalWrite(ledC, LOW);
     digitalWrite(ledB, LOW);
     digitalWrite(ledA, LOW);
  }

}