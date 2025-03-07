int valor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
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
    limpiar();
    valor=Serial.read();
    Serial.println(valor);

  if(valor==49)
    digitalWrite(2,HIGH);
  if(valor==50)
    digitalWrite(3,HIGH);
  if(valor==51)
    digitalWrite(4,HIGH);
  if(valor==52)
    digitalWrite(5,HIGH);
  }
}
