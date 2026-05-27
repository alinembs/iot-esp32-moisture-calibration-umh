#include <Arduino.h>
#define AOUT_PIN 36 // ESP32 pin GIOP36 (ADC0) that connects to AOUT pin of moisture sensor

#define wet 4095
#define dry 2350


String onSensorChange()  {
  float sensor;
  sensor = analogRead(AOUT_PIN);
  sensor =  map(sensor,dry,wet,100,0);
  return  String(sensor);
}
void setup() {
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from sensor
      // read the analog value from sensor
  float tensao = (float)value / 4095.0 * 3.3; // Supondo 3,3V como tensão de referência
  Serial.print("Moisture value: ");
  Serial.println(value);
  Serial.print("Percentual: ");
  Serial.println(onSensorChange());
  Serial.println("Tensão:");
  Serial.println(tensao);

  delay(5000);
}
//UMD 2500 100%
// UMD 4095  0%
// 1595 
//2700 ? 
