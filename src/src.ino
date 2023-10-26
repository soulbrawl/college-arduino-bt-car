#include <string.h>

#define SPEED 50 // analog = 0->255

#include "pin.h"
#include "engine.h"
#include "US_HC-SR04.h"
// #include "BT_HC-06_ZS-040.h"

void setup() {
    // engineSetup();
    // BT.BT_Setup();
    ultrasonicSensorSetup();
    Serial.begin(9600);

    // Debugging
    ultrasonicSensorTestingRoutine();
    engineTestingRoutine(); // running once the car is started
}

void loop() {
    // BT.BT_Loop();

    // engineTestingRoutine();
}
