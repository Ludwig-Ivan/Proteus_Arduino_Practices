/*
  Practica 6 ---> LED intermitente
  Participantes: Ludwig Ivan Ortiz Sierra y Sergio Octavio Cervantes Mujica
*/

void setup() {
  // Indica el modo en el q estara el pin 10 (SALIDA - OUTPUT)
  pinMode(10, OUTPUT);
}

void loop() {
  // digitalWrite escribe en el pin indicado un estado LOW (0v) o HIGH (5.5v)
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  delay(1000);
}
