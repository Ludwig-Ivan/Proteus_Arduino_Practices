#include <Servo.h>

// Declaración del servo
Servo servoMotor;

// Pines de entrada
const int potPin = A0;  // Potenciómetro en A0
const int btnIzq = 2;   // Botón para posición izquierda
const int btnCentro = 3; // Botón para posición centro
const int btnDer = 4;   // Botón para posición derecha

// Variables de estado
int modo = 1; // 1 = Automático, 2 = Potenciómetro, 3 = Botones
int angulo = 0; // Ángulo del servo

void setup() {
    servoMotor.attach(9); // Conectar el servo al pin 9

    // Configurar pines de botones como entrada con pull-up interno
    pinMode(btnIzq, INPUT_PULLUP);
    pinMode(btnCentro, INPUT_PULLUP);
    pinMode(btnDer, INPUT_PULLUP);

    Serial.begin(9600);  // Para depuración
}

void loop() {
    if (modo == 1) {
        // **Modo Automático (de 0 a 179 en pasos de 5)**
        for (angulo = 0; angulo <= 179; angulo += 5) {
            servoMotor.write(angulo);
            Serial.print("Modo Auto - Ángulo: ");
            Serial.println(angulo);
            delay(100);
        }
        for (angulo = 179; angulo >= 0; angulo -= 5) {
            servoMotor.write(angulo);
            Serial.print("Modo Auto - Ángulo: ");
            Serial.println(angulo);
            delay(100);
        }
    } 
    else if (modo == 2) {
        // **Modo Potenciómetro**
        int lectura = analogRead(potPin);
        angulo = map(lectura, 0, 1023, 0, 179);
        servoMotor.write(angulo);
        Serial.print("Modo Potenciómetro - Ángulo: ");
        Serial.println(angulo);
        delay(50);
    } 
    else if (modo == 3) {
        // **Modo Botones**
        if (digitalRead(btnIzq) == LOW) {
            angulo = 0; // Izquierda
        } else if (digitalRead(btnCentro) == LOW) {
            angulo = 90; // Centro
        } else if (digitalRead(btnDer) == LOW) {
            angulo = 179; // Derecha
        }
        servoMotor.write(angulo);
        Serial.print("Modo Botón - Ángulo: ");
        Serial.println(angulo);
        delay(100);
    }
}
