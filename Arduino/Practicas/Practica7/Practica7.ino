/*
  Practica 7 --> LED por PUSH DOWN
*/

int est=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(10, INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  digitalWrite(13,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  est = digitalRead(10);
  if(est==1){
    Serial.println("Encendido");
  }
}
