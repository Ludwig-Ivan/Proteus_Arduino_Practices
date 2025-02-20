long resultado;
int numerador=5;
int denominador=2;
int numero=1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  // resultado=numerador/denominador;
  resultado=long(numero)*1000;
  Serial.println(resultado);
}

void loop() {
  // put your main code here, to run repeatedly:

}
