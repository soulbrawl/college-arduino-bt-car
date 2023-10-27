#include <string.h>
#include "commonFunctions.h"

#define SPEED 50 // analog = 0->255

#include "pin.h"
#include "BT_HC-06_ZS-040.h"
#include "US_HC-SR04.h"
#include "engine.h"

void setup() {
    Serial.begin(9600); // default=9600
    // BT.BT_Setup();
    Serial.println("Arduino is ready");
    Serial.println("Remember to select Both NL & CR (CRLF in VSCode) in the serial monitor");

    engineSetup();
    ultrasonicSensorSetup();

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
