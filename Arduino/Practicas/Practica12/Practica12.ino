int valor;
bool rojo, azul, verde, buzz;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  azul=false;
  rojo=false;
  verde=false;
  buzz=false;
}

void limpiar(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    valor=Serial.read();
    Serial.println(valor);

  if(valor==49){
    rojo=!rojo;
    digitalWrite(2,rojo);
  }
    
  if(valor==50){
    verde=!verde;
    digitalWrite(3,verde);
  }
    
  if(valor==51){
    azul=!azul;
    digitalWrite(4,azul);
  }
  
  if(valor==52)
    buzz=!buzz;
    digitalWrite(5,buzz);
  }
}
