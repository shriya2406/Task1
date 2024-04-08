#include <dht.h>
dht DHT;
#define  dataPin 8
int LED=13;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int readData=DHT.read22(dataPin);
  float t=DHT.temperature;
  float h=DHT.humidity;
  float RainPossibility=0.04628089*h+0.00197808*t+0.5555905405405404;
  float Percentage_RainPossibility=(RainPossibility/5.3419)*100;
  if (Percentage_RainPossibility>50){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  Serial.print("Temperature= ");
  Serial.print(t);
  Serial.print(" C ");
  Serial.print(" Humidity = ");
  Serial.print(h);
  Serial.print(" % ");
  Serial.print(" RainPossibility ");
  Serial.print(Percentage_RainPossibility);
  Serial.println(" % ");
  delay(5000);
}
