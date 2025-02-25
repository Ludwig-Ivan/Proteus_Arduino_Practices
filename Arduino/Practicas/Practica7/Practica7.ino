/*
  Practica 7 --> LED por PUSH DOWN
*/
bool banant=true;
bool banact=false;
bool est=false;

void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(13,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
    int banact = digitalRead(13);

    if(banact==LOW && banant==HIGH){
      est=!est;
      digitalWrite(10,est);
    }

    banant=banact;
  delay(100);
}
