long tiempo; 
float distancia;
const int echo = 2;
const int trig = 15;

void setup() {

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
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
}