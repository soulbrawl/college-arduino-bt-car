#include <string.h>
#include "commonFunctions.h"

#define SPEED 50 // analog = 0->255

#include "pin.h"
#include "engine.h"
#include "US_HC-SR04.h"
// #include "BT_HC-06_ZS-040.h"

void setup() {
    engineSetup();
    // BT.BT_Setup();
    ultrasonicSensorSetup();
    Serial.begin(9600);

    // Debugging -- running once the car is started
    // engineTestingRoutine();
    // ultrasonicSensorTestingRoutine();
}

void loop() {
    // BT.BT_Loop();
    // forwards();
    ultrasonicSensorTestingRoutine();
    // engineTestingRoutine();
}
