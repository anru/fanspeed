#include <FanSpeed.h>

long previousMillis = 0;
unsigned long counter4 = 0;
unsigned long counter5 = 0;

void fancb(uint8_t stateMask) {
    if (stateMask & _BV(4)) {
        counter4 ++;
    }
    if (stateMask & _BV(5)) {
        counter5 ++;
    }
}

FanSpeedMultiD fans(_BV(4)|_BV(5), 0); // read rpm from pin ports 4 and 5



void setup() {
  Serial.begin(9600);
}

void loop() {
  
  unsigned long currentMillis = millis();
  
  fans.process();

  if (currentMillis - previousMillis > 1000) {
    previousMillis = currentMillis; 
    Serial.print(counter4*30); // 60/2  (seconds in minute divide by hall rising count per rotation
    Serial.print(" rpm at pin4\r\n");
    Serial.print(counter5*30); // 60/2  (seconds in minute divide by hall rising count per rotation
    Serial.print(" rpm at pin5\r\n");
    counter4 = 0;
    counter5 = 0;
  }
}
