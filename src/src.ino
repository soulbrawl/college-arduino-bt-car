#include <string.h>

#include "pin.h"
// #include "engine.h"
#include "US_HC-SR04.h"
// #include "BT_HC-06_ZS-040.h"

void setup() {
    // engineSetup();
    // BT.BT_Setup();
    ultrasonicSensorSetup();
    Serial.begin(9600);

    // Debugging
    // engineTestingRoutine(); // running once the car is started
}

void loop() {
    // BT.BT_Loop();

    ultrasonicSensorTestingRoutine();
    // engineTestingRoutine();
}
