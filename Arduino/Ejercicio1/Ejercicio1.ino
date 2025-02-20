  /*
CASTING DE VARIABLES
--------------------------
Ludwig Ivan Ortiz Sierra
10 de febrero del 2025
Tecnologico Nacional de Mexico
Campus Jiquilpan
------------------------------

*/

float variablefloat=3.4;
byte variablebyte=126;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(byte(variablefloat));
  Serial.println(int(variablefloat));
  Serial.println(word(variablefloat));
  Serial.println(long(variablefloat));
  Serial.println(char(variablebyte));
  Serial.println(float(variablebyte));
}

void loop() {
  // put your main code here, to run repeatedly:
}