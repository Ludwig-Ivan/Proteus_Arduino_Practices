#include <Servo.h>

// Crear objetos Servo
Servo servoX;
Servo servoY;

// Pines del joystick
const int pinX = A0;       // Eje X
const int pinY = A1;       // Eje Y
const int pinButton = 2;   // Botón del joystick (digital)

// Pines de los servos
const int servoPinX = 9;
const int servoPinY = 10;

// Pin del láser (salida digital)
const int laserPin = 3;

// Estado del láser
bool laserEncendido = false;
bool botonAnterior = HIGH;

void setup() {
  servoX.attach(servoPinX);
  servoY.attach(servoPinY);
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(laserPin, OUTPUT);
  digitalWrite(laserPin, LOW);

  Serial.begin(9600);
  Serial.println("Control de 2 servos + laser con Joystick");
}

void loop() {
  // Leer valores del joystick
  int valorX = analogRead(pinX);
  int valorY = analogRead(pinY);
  bool botonActual = digitalRead(pinButton);

  // Mapear joystick (0-1023) a ángulo servo (0-180)
  int anguloX = map(valorX, 0, 1023, 0, 180);
  int anguloY = map(valorY, 0, 1023, 0, 180);

  // Mover servos
  servoX.write(anguloX);
  servoY.write(anguloY);

  // Control del láser (detección de flanco descendente)
  if (botonAnterior == HIGH && botonActual == LOW) {
    laserEncendido = !laserEncendido;
    digitalWrite(laserPin, laserEncendido ? HIGH : LOW);
    Serial.print("Laser ");
    Serial.println(laserEncendido ? "ENCENDIDO" : "APAGADO");
    delay(200); // Evita rebotes
  }

  botonAnterior = botonActual;
}

