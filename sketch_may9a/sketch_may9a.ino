
const int pinSensor = 2;  
const int pinLED = 15;     

void setup() {
  pinMode(pinSensor, INPUT);    
  pinMode(pinLED, OUTPUT);     
  Serial.begin(115200);         

}

void loop() {
  int estadoSensor = digitalRead(pinSensor);

  if (estadoSensor == LOW) { 
    digitalWrite(pinLED, HIGH); 
    Serial.println("¡Obstáculo detectado!");
  } 
  else {
    digitalWrite(pinLED, LOW);
  }
  
  delay(100); 
}