const int analogInPin = A0;
const int analogOutPin = 11;

int sensorValue = 0;
int outputValue = 0;
int antSensorValue=0;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    sensorValue = analogRead(analogInPin);
  if(antSensorValue!=sensorValue){
      antSensorValue=sensorValue;
      outputValue = map(sensorValue, 0, 1023, 0, 255);

      analogWrite(analogOutPin, outputValue);

      Serial.print("sensor = " );
      Serial.print(sensorValue);

      Serial.print("\t output = ");
      Serial.println(outputValue);
  }
    

    delay(2);
}
