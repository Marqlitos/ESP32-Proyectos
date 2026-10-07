char op;

int ledA = 15;
int ledB = 2;
int ledC = 4;
int ledD = 

void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);

  Serial.begin(9600);
  Serial.println("Selecciona una opcion A,B,C,D");
}

void loop() {
  if (Serial.available() > 0) {
    op = Serial.read();
  }

  if (op == 'a') {
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledA, HIGH);
      delay(500);
      digitalWrite(ledA, LOW);
      delay(500);
    }
  }

  if (op == 'b') {

    for (int i = 0; i <= 250; i++) {
      analogWrite(ledB, i);
      delay(5);
    }

    for (int i = 250; i >= 0; i--) {
      analogWrite(ledB, i);
      delay(5);
    }
  }

  if (op == 'c') {

    for (int i = 0; i < 5; i++) {
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
      digitalWrite(ledC, HIGH);
      delay(500);

      digitalWrite(ledA, LOW);
      digitalWrite(ledB, LOW);
      digitalWrite(ledC, LOW);
      delay(500);
    }

    for (int i = 0; i <= 255; i++) {
      analogWrite(ledA, i);
      analogWrite(ledB, i);
      analogWrite(ledC, i);
      delay(5);
    }
  }

  if (op == 'd') {
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, LOW);
  }
}