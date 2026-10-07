#include <ESP32Servo.h>
Servo miServo;  

long tiempo; 
float distancia;

const int echo = 19;
const int trig = 18;

int ledV = 15;
int ledA = 2;
int ledR = 4;
const int pinServo = 17; 

void setup() {
  // put your setup code here, to run once:
    
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  miServo.attach(pinServo); 

}

void loop() {
  // put your main code here, to run repeatedly:

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

  digitalWrite(ledV, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledR, LOW);

  for(int i = 0; i <= 180; i++){
    miServo.write(i);
    actualizarLeds(i);
    delay(10);
  }

  for(int i = 180; i >= 0; i--){
    miServo.write(i);
    actualizarLeds(i);
    delay(10);
  }

}

void actualizarLeds(int angulo) {

  if(distancia > 1 && distancia < 5){
      digitalWrite(ledV, HIGH);
      digitalWrite(ledA, LOW);
      digitalWrite(ledR, LOW);

  }

  else if(distancia > 6 && distancia < 10){
      digitalWrite(ledV, LOW);
      digitalWrite(ledA, HIGH);
      digitalWrite(ledR, LOW);

  }

  else if (distancia > 11 && distancia < 20){
      digitalWrite(ledV, LOW);
      digitalWrite(ledA, LOW);
      digitalWrite(ledR, HIGH);
      
  }

}
