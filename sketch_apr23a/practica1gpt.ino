// Definimos los pines
int led1 = 9;
int led2 = 10;
int led3 = 11;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char letra = Serial.read();

    // --- OPCIÓN A: 1er LED parpadea 5 veces ---
    if (letra == 'a') {
      digitalWrite(led1, HIGH); delay(300); digitalWrite(led1, LOW); delay(300);
      digitalWrite(led1, HIGH); delay(300); digitalWrite(led1, LOW); delay(300);
      digitalWrite(led1, HIGH); delay(300); digitalWrite(led1, LOW); delay(300);
      digitalWrite(led1, HIGH); delay(300); digitalWrite(led1, LOW); delay(300);
      digitalWrite(led1, HIGH); delay(300); digitalWrite(led1, LOW); delay(300);
      digitalWrite(led1, HIGH); // Se queda prendido
    }

    // --- OPCIÓN B: 2do LED sube y baja intensidad ---
    if (letra == 'b') {
      // Sube de 0 a 255
      for (int i = 0; i <= 255; i++) {
        analogWrite(led2, i);
        delay(10);
      }
      // Baja de 255 a 0
      for (int i = 255; i >= 0; i--) {
        analogWrite(led2, i);
        delay(10);
      }
      digitalWrite(led2, HIGH); // Se queda prendido
    }

    // --- OPCIÓN C: Todos parpadean y luego intensidad ---
    if (letra == 'c') {
      // Parpadeo simple (solo pondré 2 veces para no alargar el código, tú puedes repetir)
      digitalWrite(led1, HIGH); digitalWrite(led2, HIGH); digitalWrite(led3, HIGH);
      delay(500);
      digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW);
      delay(500);

      // Intensidad para todos
      for (int i = 0; i <= 255; i++) {
        analogWrite(led1, i); analogWrite(led2, i); analogWrite(led3, i);
        delay(10);
      }
      digitalWrite(led1, HIGH); digitalWrite(led2, HIGH); digitalWrite(led3, HIGH);
    }

    // --- OPCIÓN D: Apagar todo ---
    if (letra == 'D') {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
  }
}