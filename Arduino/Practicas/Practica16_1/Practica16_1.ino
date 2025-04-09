// Pin PWM que controla la base del transistor (velocidad del motor)
const int motorPWM = 9;

void setup() {
  pinMode(motorPWM, OUTPUT);
  Serial.begin(9600);
  Serial.println("Control de velocidad del motor con 2N2222");
}

void loop() {
  // Aumentar velocidad con ciclo for
  for (int velocidad = 0; velocidad <= 255; velocidad += 5) {
    analogWrite(motorPWM, velocidad);
    Serial.print("Aumentando velocidad: ");
    Serial.println(velocidad);
    delay(50);
  }

  delay(500); // Mantener velocidad máxima

  // Disminuir velocidad con ciclo for
  for (int velocidad = 255; velocidad >= 0; velocidad -= 5) {
    analogWrite(motorPWM, velocidad);
    Serial.print("Disminuyendo velocidad: ");
    Serial.println(velocidad);
    delay(50);
  }

  delay(500); // Motor apagado un momento antes de reiniciar ciclo
}
