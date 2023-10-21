#define BT_RX_PIN 14
#define BT_TX_PIN 15
const int US_TRIG_PIN = 10;
const int US_ECHO_PIN = 11;

#include "US_HC-SR04.h"
#include "BT_HC-06_ZS-040.h"

void setup() {
    Serial.begin(9600);
    BT.BT_Setup();
    US.US_Setup(US_TRIG_PIN, US_ECHO_PIN);
}

void loop() {
    US.US_Loop();
    US.US_Display();
    BT.BT_Loop();
}