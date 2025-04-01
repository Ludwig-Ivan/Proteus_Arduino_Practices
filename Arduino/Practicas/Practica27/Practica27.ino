#define MICROFONO A0  // Entrada del sensor de sonido
#define BUZZER 10     // Alarma sonora

// Pines de los LEDs
const int LEDS[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int NUM_LEDS = sizeof(LEDS) / sizeof(LEDS[0]);

void setup() {
    pinMode(MICROFONO, INPUT);
    pinMode(BUZZER, OUTPUT);

    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(LEDS[i], OUTPUT);
    }

    Serial.begin(9600);
}

void loop() {
    int sonido = analogRead(MICROFONO);  // Leer nivel de sonido (0-1023)
    int nivel = map(sonido, 0, 1023, 0, NUM_LEDS);  // Mapear a 0-8 LEDs

    Serial.print("Nivel de sonido: "); Serial.print(sonido);
    Serial.print(" | LEDs encendidos: "); Serial.println(nivel);

    // Apagar todos los LEDs y el buzzer antes de actualizar
    for (int i = 0; i < NUM_LEDS; i++) {
        digitalWrite(LEDS[i], LOW);
    }
    digitalWrite(BUZZER, LOW);

    // Encender la cantidad de LEDs según el nivel de sonido
    for (int i = 0; i < nivel; i++) {
        digitalWrite(LEDS[i], HIGH);
    }

    // Activar buzzer si todos los LEDs están encendidos (ruido muy alto)
    if (nivel == NUM_LEDS) {
        digitalWrite(BUZZER, HIGH);
    }

    delay(100);  // Pequeña pausa para estabilidad
}

// Para verificar los codigos de los btns
// #include <IRremote.h>
// IRrecv irrecv(2);
// decode_results results;
// void setup() { Serial.begin(9600); irrecv.enableIRIn(); }
// void loop() {
//     if (irrecv.decode(&results)) {
//         Serial.println(results.value, HEX);
//         irrecv.resume();
//     }
// }

