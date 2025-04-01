#define LDR_PIN A0    // Fotoresistencia en A0
#define TRIAC_PIN 9   // Control del TRIAC

void setup() {
    pinMode(TRIAC_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int luz = analogRead(LDR_PIN);
    int intensidad = map(luz, 0, 1023, 255, 0); // Más oscuridad, más brillo

    Serial.print("Luz: "); Serial.print(luz);
    Serial.print(" | Intensidad: "); Serial.println(intensidad);

    analogWrite(TRIAC_PIN, intensidad); // Modula la lámpara
    delay(100);
}

