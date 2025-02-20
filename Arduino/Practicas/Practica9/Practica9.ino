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
  // put your main code here, to run repeatedly:
  for(int i=0;i<cant;i++){
    digitalWrite(pins[i],HIGH);
    delay(100);
  }
  for(int i=0;i<cant;i++){
    digitalWrite(pins[i],LOW);
    delay(100);
  }
}
