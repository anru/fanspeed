#include <FanSpeed.h>

long previousMillis = 0;

FanSpeedInt fan(2, false);

void rpm2() {
    fan.process();
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, rpm2, RISING);
}

void loop() {
  
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > 1000) {
    previousMillis = currentMillis; 
    Serial.print(fan.counter*30); // 60/2  (seconds in minute divide by hall rising count per rotation
    Serial.print(" rpm\r\n");
    fan.reset();
  }
}
