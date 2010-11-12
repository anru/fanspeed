#include <FanSpeed.h>

long previousMillis = 0;

FanSpeed fan(2, false);

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  unsigned long currentMillis = millis();
  
  fan.process();

  if (currentMillis - previousMillis > 1000) {
    previousMillis = currentMillis; 
    Serial.print(fan.getPulseCounter()*30); // 60/2  (seconds in minute divide by hall rising count per rotation
    Serial.print(" rpm\r\n");
    fan.reset();
  }
}
