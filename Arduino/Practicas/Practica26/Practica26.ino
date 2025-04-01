#define PIR_PIN 2      // Pin del sensor PIR
#define LED_PIN 3      // Pin del LED
#define BUZZER_PIN 4   // Pin del buzzer
#define BUTTON_PIN 5   // Pin del botón

bool alarma_activada = false; // Estado de la alarma

void setup() {
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Botón con resistencia pull-up

    Serial.begin(9600);
}

void loop() {
    int pir_estado = digitalRead(PIR_PIN);
    int boton_estado = digitalRead(BUTTON_PIN);

    if (pir_estado == HIGH && !alarma_activada) {
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(BUZZER_PIN, HIGH);
        Serial.println("Movimiento detectado! Alarma activada.");
        alarma_activada = true; // Bloquea el sistema hasta que se presione el botón
    }

    if (alarma_activada && boton_estado == LOW) {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(BUZZER_PIN, LOW);
        Serial.println("Alarma desactivada. Reanudando detección.");
        alarma_activada = false;
        delay(500); // Pequeño retraso para evitar rebotes del botón
    }
}
