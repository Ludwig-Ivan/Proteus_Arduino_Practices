#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal_I2C lcd(0x27,20,4);
const int limit_time=1000;
unsigned long last_time = 0; 
String text="";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init(); // Inicializa el LCD
  lcd.backlight(); // Enciende la luz de fondo

    // Escribir en las 4 líneas del LCD
    lcd.setCursor(0, 0);
    lcd.write("Linea 1: Hola!");
    
    lcd.setCursor(0, 1);
    lcd.print("Linea 2: Arduino");
    
    lcd.setCursor(0, 2);
    lcd.print("Linea 3: 20x4 LCD");
    
    lcd.setCursor(0, 3);
    lcd.print("Linea 4: I2C OK");
}

void loop() {
  /* Hago la lectura de la informacion enviada por el serial monitor
  while(Serial.available()>0){
    char letter = Serial.read();
    text+=letter;
    last_time = millis();
  }

  /* Si tengo algun texto y el tiempo en que lo escribi supera los 500 ms se considera
  que no hay mas info q escribir, y la muestra en el lcd
  /
  if (text.length() > 0 && millis() - last_time > limit_time) {
    lcd.clear();
    lcd.print(text);
    Serial.println("Mensaje mostrado: " + text);

    delay(1000);

    for (int positionCounter = 0; positionCounter < text.length(); positionCounter++) {
      // scroll one position left:
      lcd.scrollDisplayLeft();
      // wait a bit:
      delay(300);
    }

    for (int positionCounter = 0; positionCounter < text.length(); positionCounter++) {
      // scroll one position left:
      lcd.scrollDisplayRight();
      // wait a bit:
    }
    
    text = "";
  }*/
}
