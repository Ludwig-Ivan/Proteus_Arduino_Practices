const int analogInPin = A0;
const int firstpin=2;
const int secondpin=3;
const int thirdpin=4;

int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
    pinMode(firstpin,OUTPUT);
    pinMode(secondpin,OUTPUT);
    pinMode(thirdpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    sensorValue = analogRead(analogInPin);
  
    if(sensorValue<256){
        digitalWrite(firstpin,LOW);
        digitalWrite(secondpin,LOW);
        digitalWrite(thirdpin,LOW);
    }

    if(sensorValue>=256 && sensorValue<=512){
        digitalWrite(firstpin,HIGH);
        digitalWrite(secondpin,LOW);
        digitalWrite(thirdpin,LOW);
    }

    if(sensorValue>=513 && sensorValue<=768){
        digitalWrite(firstpin,LOW);
        digitalWrite(secondpin,HIGH);
        digitalWrite(thirdpin,LOW);
    }

    if(sensorValue>=768){
        digitalWrite(firstpin,LOW);
        digitalWrite(secondpin,LOW);
        digitalWrite(thirdpin,HIGH);
    }
    
    delay(2);
}
