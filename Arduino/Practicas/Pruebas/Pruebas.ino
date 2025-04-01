float sensVal=50.9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  sensVal=max(sensVal,100);
  Serial.println(sensVal);
}
