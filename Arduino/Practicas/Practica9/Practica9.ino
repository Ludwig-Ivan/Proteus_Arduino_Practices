/*
  Practica 9 --> Estela de leds
  Participantes: Ludwig Ivan Ortiz Sierra y Sergio Octavio Cervantes Mujica
*/
int cant=8;
int pins[8]={2,3,4,5,6,7,8,9};

void setup() {
    // put your setup code here, to run once:
  for(int i=0;i<cant;i++){
    pinMode(pins[i],OUTPUT);
  }
}

void loop() {
  // Encender LEDs en una dirección
  for (int i = 0; i < cant; i++) {
    digitalWrite(pins[i], HIGH);
    if (i > 0) {
      digitalWrite(pins[i - 1], LOW);
    }
    delay(20);
  }

  delay(10);
  
  // Apagar el último LED encendido
  digitalWrite(pins[cant - 1], LOW);

  // Encender LEDs en la dirección opuesta
  for (int i = cant - 1; i >= 0; i--) {
    digitalWrite(pins[i], HIGH);
    if (i < cant - 1) {
      digitalWrite(pins[i + 1], LOW);
    }
    delay(20);
  }
}

