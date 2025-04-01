#define TRIG 9  // Pin del Trigger del sensor ultrasónico
#define ECHO 10 // Pin del Echo del sensor ultrasónico
#define BUZZER 5 // Pin del buzzer

void setup() {
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(BUZZER, OUTPUT);
    Serial.begin(9600); // Inicia el Monitor Serie
}

void loop() {
    long duration;
    float distanceCM, distanceM, distanceIN;

    // Enviar pulso al Trigger
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    // Leer el tiempo de respuesta del Echo
    duration = pulseIn(ECHO, HIGH);

    // Convertir tiempo en distancia
    distanceCM = duration * 0.0343 / 2; // Conversión a cm
    distanceM = distanceCM / 100.0; // Conversión a metros
    distanceIN = distanceCM * 0.3937; // Conversión a pulgadas

    // Imprimir en el Monitor Serie
    Serial.print("Distancia: ");
    Serial.print(distanceCM); Serial.print(" cm | ");
    Serial.print(distanceM); Serial.print(" m | ");
    Serial.print(distanceIN); Serial.println(" in");

    // Control del buzzer según la distancia
    if (distanceCM < 50) {
        tone(BUZZER, 1000); // Sonido rápido
        delay(100);
        noTone(BUZZER);
        delay(100);
    } 
    else if (distanceCM >= 50 && distanceCM <= 100) {
        tone(BUZZER, 800); // Sonido intermitente más lento
        delay(300);
        noTone(BUZZER);
        delay(300);
    } 
    else {
        noTone(BUZZER); // Sin sonido si está lejos
    }

    delay(200); // Pequeño retraso antes de la siguiente lectura
}
