#include <Stepper.h>

// Número de pasos para 360°, ajustable
int totalPasos = 100; // Puedes cambiar a 20 o 50 más adelante

// Pines de control del ULN2003 conectados al Arduino
const int motorPins[] = {8, 9, 10, 11};

// Crear objeto Stepper
Stepper motor(totalPasos, motorPins[0], motorPins[2], motorPins[1], motorPins[3]);

// Pines de botones para sentido de giro
const int botonHorario = 6;
const int botonAntihorario = 7;

// Velocidad en RPM (elige una de estas: 10, 20, 30, 50, 60)
int velocidadRPM = 30;

void setup() {
  // Configurar pines de botones
  pinMode(botonHorario, INPUT_PULLUP);
  pinMode(botonAntihorario, INPUT_PULLUP);

  // Configurar velocidad del motor
  motor.setSpeed(velocidadRPM);

  Serial.begin(9600);
  Serial.println("Control de Motor Paso a Paso ULN2003");
}

void loop() {
  if (digitalRead(botonHorario) == LOW) {
    Serial.println("Girando horario");
    motor.step(totalPasos);  // Gira 360° en sentido horario
    delay(500);
  }

  if (digitalRead(botonAntihorario) == LOW) {
    Serial.println("Girando antihorario");
    motor.step(-totalPasos); // Gira 360° en sentido antihorario
    delay(500);
  }
}
