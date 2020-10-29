/*
  Project #03 from the Arduino Starter Kit Project Book
*/

const int sensorPin = A0;
const float baselineTemp = 16.0;

void setup()
{
    Serial.begin(9600);
    for(int pinNumber = 2; pinNumber<5; pinNumber++) {
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
    }
}

void loop()
{
	int sensorVal = analogRead(sensorPin);

  // debug info to the consonle
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");

  // convert the voltage to temperature in degrees 
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  if(temperature < baselineTemp+2) {
    // if the temp is > 20c and < 22c
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4) {
    // if the temp >= 22c and temp < 24c
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6) {
    // if temp >= 24c and temp < 26
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+6) {
    // if temp > 26c
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(100);

}
