// CONFIGURANDO OS PINOS:
void setup() {
  // SEMÁFORO 1:
  pinMode(7, OUTPUT); // Vermelho 1
  pinMode(4, OUTPUT); // Amarelo 1
  pinMode(2, OUTPUT); // Verde 1

  // SEMÁFORO 2:
  pinMode(13, OUTPUT); // Vermelho 2
  pinMode(12, OUTPUT); // Amarelo 2
  pinMode(8, OUTPUT);  // Verde 2
  
  Serial.begin(9600);
}

// DEFININDO A FUNÇÃO DO CICLO:
void semaforo() {
  
  // CONDIÇÃO 1: SEMÁFORO 1 VERDE / SEMÁFORO 2 VERMELHO
  Serial.write("Semáforo 1 Verde, Semáforo 2 Vermelho");
  digitalWrite(2, HIGH); digitalWrite(4, LOW);  digitalWrite(7, LOW);
  digitalWrite(8, LOW);  digitalWrite(12, LOW); digitalWrite(13, HIGH);
  delay(4000);

  // CONDIÇÃO 2: SEMÁFORO 1 AMARELO / SEMÁFORO 2 VERMELHO
  Serial.write("Semáforo 1 Amarelo, Semáforo 2 Vermelho");
  digitalWrite(2, LOW);  digitalWrite(4, HIGH); digitalWrite(7, LOW);
  digitalWrite(8, LOW);  digitalWrite(12, LOW); digitalWrite(13, HIGH);
  delay(2000);

  // CONDIÇÃO 3: SEMÁFORO 1 VERMELHO / SEMÁFORO 2 VERDE
  Serial.write("Semáforo 1 Vermelho, Semáforo 2 Verde");
  digitalWrite(2, LOW);  digitalWrite(4, LOW);  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH); digitalWrite(12, LOW); digitalWrite(13, LOW);
  delay(4000);

  // CONDIÇÃO 4: SEMÁFORO 1 VERMELHO / SEMÁFORO 2 AMARELO
  Serial.write("Semáforo 1 Vermelho, Semáforo 2 Amarelo");
  digitalWrite(2, LOW);  digitalWrite(4, LOW);  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);  digitalWrite(12, HIGH); digitalWrite(13, LOW);
  delay(2000);
}

// REPETINDO EM LOOP:
void loop() {
  semaforo();
}
