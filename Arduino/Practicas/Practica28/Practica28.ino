#include <IRremote.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RECV_PIN 2  // Pin del receptor IR

// Pines de los LEDs
const int LEDS[] = {3, 4, 5, 6};  
const int NUM_LEDS = sizeof(LEDS) / sizeof(LEDS[0]);

// Definir códigos IR de los botones del control (debes obtenerlos con el Monitor Serie)
#define BTN_LED1   0xFF30CF  // Código del botón que controla el LED1
#define BTN_LED2   0xFF18E7  // Código del botón que controla el LED2
#define BTN_LED3   0xFF7A85  // Código del botón que controla el LED3
#define BTN_LED4   0xFF10EF  // Código del botón que controla el LED4
#define BTN_LEFT   0xFF22DD  // Flecha IZQUIERDA (<--)
#define BTN_RIGHT  0xFFC23D  // Flecha DERECHA (-->)
#define BTN_UP     0xFF629D  // Flecha ARRIBA (Aumentar contador)
#define BTN_DOWN   0xFFA857  // Flecha ABAJO (Disminuir contador)

// Servo y LCD
Servo servoMotor;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Dirección I2C del LCD (puede ser 0x3F en algunos modelos)

// Variables
int servoPos = 90;  // Posición inicial del servo
int contador = 0;   // Valor del contador
bool ledState[NUM_LEDS] = {0};  // Estados de los LEDs

IRrecv irrecv(RECV_PIN);  
decode_results results;

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();  // Iniciar el receptor IR
    servoMotor.attach(9); // Pin del servomotor
    servoMotor.write(servoPos);

    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(LEDS[i], OUTPUT);
    }

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Contador: ");
    lcd.setCursor(10, 0);
    lcd.print(contador);
}

void loop() {
    if (irrecv.decode(&results)) {
        Serial.print("Codigo IR: ");
        Serial.println(results.value, HEX);
        manejarIR(results.value);
        irrecv.resume();  // Recibir el siguiente código IR
    }
}

void manejarIR(unsigned long codigo) {
    // Control de LEDs
    for (int i = 0; i < NUM_LEDS; i++) {
        if (codigo == (BTN_LED1 + i * 0xFFFFF0)) {  // Ajusta según códigos IR reales
            ledState[i] = !ledState[i];
            digitalWrite(LEDS[i], ledState[i]);
        }
    }

    // Control del Servo
    if (codigo == BTN_LEFT) {
        servoPos = max(0, servoPos - 10);
        servoMotor.write(servoPos);
    } else if (codigo == BTN_RIGHT) {
        servoPos = min(180, servoPos + 10);
        servoMotor.write(servoPos);
    }

    // Control del Contador en LCD
    if (codigo == BTN_UP) {
        contador++;
    } else if (codigo == BTN_DOWN) {
        contador--;
    }

    lcd.setCursor(10, 0);
    lcd.print("    ");  // Borrar número anterior
    lcd.setCursor(10, 0);
    lcd.print(contador);
}
