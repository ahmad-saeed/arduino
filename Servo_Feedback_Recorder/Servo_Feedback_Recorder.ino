#include <EEPROM.h>

uint16_t calibMaxS1 = 447;
uint16_t calibMinS1 = 85;

uint16_t delayPeriod = 250;

uint8_t counter = -1;

void setup() {


}

void loop() {
counter+=1;
EEPROM.write(counter, map(analogRead(0),calibMinS1,calibMaxS1,0,180));
delay(delayPeriod);
}
