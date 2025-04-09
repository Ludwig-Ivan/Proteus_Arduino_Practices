#include <Servo.h>

// Pines del sensor ultrasónico
const int trigPin = 8;
const int echoPin = 9;

// Servo para girar el sensor
Servo servo;

// Pines de los LEDs
const int ledIzq = 2;
const int ledFrente = 3;
const int ledDer = 4;

// Ángulos para los 3 flancos
const int anguloIzq = 0;
const int anguloFrente = 90;
const int anguloDer = 180;

// Distancia crítica (cm)
const int distanciaCritica = 25;

// Variables para guardar distancias
int distIzq, distFrente, distDer;

void setup() {
  Serial.begin(9600);
  
  // Configurar pines del sensor y LEDs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledIzq, OUTPUT);
  pinMode(ledFrente, OUTPUT);
  pinMode(ledDer, OUTPUT);

  // Conectar servo
  servo.attach(10);

  Serial.println("Escaneo de obstáculos iniciado...");
}

void loop() {
  // Escanear izquierda
  servo.write(anguloIzq);
  delay(500);
  distIzq = medirDistancia();
  Serial.print("Izquierda: "); Serial.print(distIzq); Serial.println(" cm");

  // Escanear frente
  servo.write(anguloFrente);
  delay(500);
  distFrente = medirDistancia();
  Serial.print("Frente: "); Serial.print(distFrente); Serial.println(" cm");

  // Escanear derecha
  servo.write(anguloDer);
  delay(500);
  distDer = medirDistancia();
  Serial.print("Derecha: "); Serial.print(distDer); Serial.println(" cm");

  // Lógica de decisión
  digitalWrite(ledIzq, LOW);
  digitalWrite(ledFrente, LOW);
  digitalWrite(ledDer, LOW);

  if (distFrente > distanciaCritica) {
    digitalWrite(ledFrente, HIGH); // Camino libre al frente
  } else if (distDer > distanciaCritica) {
    digitalWrite(ledDer, HIGH); // Camino libre a la derecha
  } else if (distIzq > distanciaCritica) {
    digitalWrite(ledIzq, HIGH); // Camino libre a la izquierda
  } else {
    // Todos los caminos bloqueados
    Serial.println("¡Obstáculo en todos los flancos!");
  }

  delay(1500); // Espera antes de nuevo escaneo
}

// Función para medir distancia con el sensor ultrasónico
int medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracion = pulseIn(echoPin, HIGH);
  int distancia = duracion * 0.034 / 2; // Convertir a cm

  return distancia;
}