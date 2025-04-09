#include <AFMotor.h>

// Crear el objeto motor en el puerto 1 (puedes usar 1 a 4)
AF_DCMotor motor(1); 

void setup() {
  Serial.begin(9600);
  Serial.println("Control de velocidad con AFMotor");
  
  // Establecer dirección inicial
  motor.setSpeed(0); 
  motor.run(FORWARD); // Dirección: FORWARD o BACKWARD
}

void loop() {
  // Aumentar velocidad de 0 a 255
  for (int velocidad = 0; velocidad <= 255; velocidad += 5) {
    motor.setSpeed(velocidad);
    Serial.print("Velocidad aumentando: ");
    Serial.println(velocidad);
    delay(50);
  }

  delay(500);

  // Disminuir velocidad
  for (int velocidad = 255; velocidad >= 0; velocidad -= 5) {
    motor.setSpeed(velocidad);
    Serial.print("Velocidad disminuyendo: ");
    Serial.println(velocidad);
    delay(50);
  }

  delay(500);
}

