#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
    lcd.init();
    lcd.backlight();
    lcd.clear();

    // Mensaje inicial en cada fila
    lcd.setCursor(0, 0);
    lcd.print("Hola Mundo!!");

    lcd.setCursor(0, 1);
    lcd.print("Hola Checo :3");

    lcd.setCursor(0, 2);
    lcd.print("Hola Fanny");

    lcd.setCursor(0, 3);
    lcd.print("Hola Wiwin");
    

    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        String mensaje = Serial.readStringUntil('\n');  // Leer mensaje del monitor serial
        lcd.clear();  // Borrar pantalla
        lcd.print(mensaje);
    }
    lcd.scrollDisplayLeft();
    delay(500);
}
