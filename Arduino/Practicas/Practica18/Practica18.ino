#include <Servo.h>

// Pines de los sensores de luz (LDRs)
const int LDR_izq = A0; // LDR izquierda
const int LDR_der = A1; // LDR derecha

// Servomotor
Servo servoMotor;
const int pinServo = 9;

void setup() {
    servoMotor.attach(pinServo); // Conectar servo al pin 9
    Serial.begin(9600); // Para depuración
}

void loop() {
    int luzIzq = analogRead(LDR_izq); // Leer LDR izquierda
    int luzDer = analogRead(LDR_der); // Leer LDR derecha

    int diferencia = luzIzq - luzDer; // Diferencia entre sensores
    int angulo = map(diferencia, -500, 500, 0, 179); // Ajuste de ángulo

    angulo = constrain(angulo, 0, 179); // Limitar rango de ángulos

    servoMotor.write(angulo); // Mover el servo
    Serial.print("Luz Izq: "); Serial.print(luzIzq);
    Serial.print(" | Luz Der: "); Serial.print(luzDer);
    Serial.print(" | Servo: "); Serial.println(angulo);

    delay(50); // Pequeño retraso para estabilidad
}
