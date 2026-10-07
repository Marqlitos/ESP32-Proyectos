#include <ESP32Servo.h>

//Pines por declarar
Servo miServo;
long tiempo;
float distancia;
const int echo = 19;
const int trig = 18;
const int ledV = 15;
const int ledA = 2;
const int ledR = 4;
const int pinServo = 17;
const int buzzer = 5; // <-- NUEVO PIN

void setup() {

  Serial.begin(115200);
  pinMode(ledV, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  //pinMode(buzzer, OUTPUT); // <-- NUEVO
  //miServo.attach(pinServo);

}

void loop() {

  for(int i = 0; i <= 180; i++) {
    miServo.write(i);
    medirDistancia();
    actualizarLeds();
    Serial.print("Angulo: ");
    Serial.print(i);
    Serial.print(" | Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
    delay(20);
  }

  for(int i = 180; i >= 0; i--) {
    miServo.write(i);
    medirDistancia();
    actualizarLeds();
    Serial.print("Angulo: ");
    Serial.print(i);
    Serial.print(" | Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
    delay(20);
  }
}

void medirDistancia() {
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  tiempo = pulseIn(echo, HIGH);
  distancia = tiempo / 58.2;

}

void actualizarLeds() {

  digitalWrite(ledV, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledR, LOW);

  if (distancia >= 20) {
    digitalWrite(ledV, HIGH);
    //tone(buzzer, 1000); // 🔊 suena cuando está lejos
  }

  else if (distancia > 10 && distancia < 20) {
    digitalWrite(ledA, HIGH);
    //noTone(buzzer); // 🔇 sin sonido
  }

  else if (distancia > 0 && distancia <= 10) {
    digitalWrite(ledR, HIGH);
    //noTone(buzzer); // 🔇 sin sonido
  }

}