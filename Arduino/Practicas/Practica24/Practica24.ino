#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Configuración del LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Dirección I2C (0x27 o 0x3F)

// Configuración del sensor DHT
#define DHTPIN 2      // Pin del sensor
#define DHTTYPE DHT11 // DHT11 o DHT22
DHT dht(DHTPIN, DHTTYPE);

// Definir pines de calefactor y extractor
#define CALEFACTOR 3  // Pin del calefactor
#define EXTRACTOR 4   // Pin del extractor

// Definir temperatura ambiente
const float TEMP_AMBIENTE = 25.0; // Ajustable

void setup() {
    Serial.begin(9600); // Iniciar Monitor Serie
    dht.begin();        // Iniciar sensor DHT
    lcd.init();         // Iniciar LCD
    lcd.backlight();    // Encender luz del LCD

    // Configurar calefactor y extractor como salida
    pinMode(CALEFACTOR, OUTPUT);
    pinMode(EXTRACTOR, OUTPUT);

    // Mostrar mensaje inicial
    lcd.setCursor(0, 0);
    lcd.print("  Monitoreo DHT  ");
    delay(2000);
    lcd.clear();
}

void loop() {
    // Leer temperatura y humedad
    float temperatura = dht.readTemperature();  // °C
    float humedad = dht.readHumidity();        // %

    // Validar datos correctos
    if (isnan(temperatura) || isnan(humedad)) {
        Serial.println("Error en lectura del sensor!");
        lcd.setCursor(0, 0);
        lcd.print("Error en Sensor");
        delay(1000);
        return;
    }

    // Mostrar en Monitor Serie
    Serial.print("Temperatura: "); Serial.print(temperatura); Serial.print(" °C | ");
    Serial.print("Humedad: "); Serial.print(humedad); Serial.println(" %");

    // Mostrar en LCD
    lcd.setCursor(0, 0);
    lcd.print("Temp: "); lcd.print(temperatura); lcd.print("C ");
    lcd.setCursor(0, 1);
    lcd.print("Humed: "); lcd.print(humedad); lcd.print("% ");

    // Control de calefactor y extractor
    if (temperatura < TEMP_AMBIENTE) {
        digitalWrite(CALEFACTOR, HIGH);
        digitalWrite(EXTRACTOR, LOW);
        Serial.println("CALEFACTOR ENCENDIDO");
    } else if (temperatura > TEMP_AMBIENTE) {
        digitalWrite(CALEFACTOR, LOW);
        digitalWrite(EXTRACTOR, HIGH);
        Serial.println("EXTRACTOR ENCENDIDO");
    } else {
        digitalWrite(CALEFACTOR, LOW);
        digitalWrite(EXTRACTOR, LOW);
        Serial.println("Temperatura estable");
    }

    delay(2000); // Esperar antes de la siguiente lectura
}
