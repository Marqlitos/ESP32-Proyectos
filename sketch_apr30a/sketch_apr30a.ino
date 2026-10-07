#include <ESP32Servo.h>

Servo miServo;  

int ledV1 = 2;
int ledR = 4;
int ledV2 = 16;

const int pinServo = 15; 

void setup() {
  
  miServo.attach(pinServo); 
  
  pinMode(ledV1, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledV2, OUTPUT);
}

void loop() {
  
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

  if(angulo >= 0 && angulo <= 60){

      digitalWrite(ledV1, HIGH);
      digitalWrite(ledR, LOW);
      digitalWrite(ledV2, LOW);

  }
  else if(angulo >= 61 && angulo <= 120){

      digitalWrite(ledV1, LOW);
      digitalWrite(ledR, HIGH);
      digitalWrite(ledV2, LOW);

  }
  else if (angulo >= 121 && angulo <= 180){

      digitalWrite(ledV1, LOW);
      digitalWrite(ledR, LOW);
      digitalWrite(ledV2, HIGH);
      
  }
}