void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void cleanPins(){
  bool ban = true;
  digitalWrite(2,ban);
  digitalWrite(3,ban);
  digitalWrite(4,ban);
  digitalWrite(5,ban);
  digitalWrite(6,ban);
  digitalWrite(7,ban);
  digitalWrite(8,ban);
}

void onPins(int pins[], int tam){
  for (int cont=0; cont<tam; cont++) {
      digitalWrite(pins[cont],LOW);
      Serial.println(pins[cont]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  cleanPins();
  int cero[]={8,7,6,5,4,3};
  int uno[]={7,6};
  int dos[]={8,7,2,4,5};
  int tres[]={8,7,2,6,5};
  int cuatro[]={3,2,7,6};
  int cinco[]={8,3,2,6,5};
  int seis[]={8,3,4,2,6,5};
  int siete[]={8,7,6};
  int ocho[]={8,7,6,5,4,3,2};
  int nueve[]={8,3,7,2,6};

  // Numero 0 - (8,7,6,5,4,3)
  onPins(cero,sizeof(cero)/2);
  delay(1000);
  cleanPins();
  // Numero 1 - (3,4)
  onPins(uno,sizeof(uno)/2);
  delay(1000);
  cleanPins();
  // Numero 2 - (8,7,2,4,5)
  onPins(dos,sizeof(dos)/2);
  delay(1000);
  cleanPins();
  // Numero 3 - (8,7,2,6,5)
  onPins(tres,sizeof(tres)/2);
  delay(1000);
  cleanPins();
  // Numero 4 - (3,2,7,6)
  onPins(cuatro,sizeof(cuatro)/2);
  delay(1000);
  cleanPins();
  // Numero 5 - (8,3,2,6,5)
  onPins(cinco,sizeof(cinco)/2);
  delay(1000);
  cleanPins();
  // Numero 6 - (7,2,6,4,5)
  onPins(seis,sizeof(seis)/2);
  delay(1000);
  cleanPins();
  // Numero 7 - (8,7,6)
  onPins(siete,sizeof(siete)/2);
  delay(1000);
  cleanPins();
  // Numero 8 - (8,7,6,5,4,3,2)
  onPins(ocho,sizeof(ocho)/2);
  delay(1000);
  cleanPins();
  // Numero 9 - (8,7,6,3,2)
  onPins(nueve,sizeof(nueve)/2);
  delay(1000);
  cleanPins();
}
