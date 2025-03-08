const int analogInPin = A0;  // Pin analógico de entrada
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10}; // Pines de los LEDs

void setup() {
    for (int i = 0; i < 9; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
    Serial.begin(9600);  // Para depuración en el Monitor Serie
}

void loop() {
    int sensorValue = analogRead(analogInPin); // Leer entrada analógica
    int nivel = map(sensorValue, 0, 1023, 0, 9); // Convertir a escala de 0 a 9

    Serial.print("Sensor: ");
    Serial.print(sensorValue);
    Serial.print("\tNivel: ");
    Serial.println(nivel);

    // Apagar todos los LEDs antes de actualizar
    for (int i = 0; i < 9; i++) {
        digitalWrite(ledPins[i], LOW);
    }

    // Encender LEDs según el nivel detectado
    for (int i = 0; i < nivel; i++) {
        digitalWrite(ledPins[i], HIGH);
    }

    delay(100);  // Pequeño retraso para estabilidad
}