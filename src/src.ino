#include <string.h>
#include "pin.h"
#include "commonFunctions.h"

#define SPEED 50 // analog = 0->255

// #include "BT_HC-06_ZS-040.h"
#include "US_HC-SR04.h"
#include "engine.h"

// char c = ' '; // for testing BT module Serial Monitor printing

void setup() {
    // LED blinking (CONTROL) setup
    // pinMode(BUILTIN_LED, OUTPUT);
    // digitalWrite(BUILTIN_LED, LOW);

    Serial.begin(9600); // default=9600
    Serial.println("Arduino is ready");
    // Serial.println("Remember to select Both NL & CR (CRLF in VSCode) in the serial monitor");

    // BT.BT_Setup();
    // BTserial.begin(38400);
    // Serial.println("BT_Setup OK");

    engineSetup();
    ultrasonicSensorSetup();

    // Debugging -- running once the car is started
    // engineTestingRoutine();
    ultrasonicSensorTestingRoutine();
}

void loop() {
    // LED blinking (CONTROL) test
    // blinkLED();

    // Testing movement proximity restrictions
    while(runForDuration(3000)) {
        forwards();
    }

    while(runForDuration(3000)) {
        backwards();
    }

    // Bluetooth Section
    // BT.BT_Loop();
    // BT.BT_Display();
    // if (BTserial.available()) {
    //     c = BTserial.read();
    //     Serial.write(c); // Print the character received from Bluetooth to the serial monitor
    // }

    // // Keep reading from Arduino Serial Monitor and send to HC-06
    // if (Serial.available()) {
    //     c = Serial.read();
    //     BTserial.write(c); // Send the character received from the serial monitor to Bluetooth
    // }

    // Debugging -- looping
    // engineTestingRoutine();
    // ultrasonicSensorTestingRoutine();
}
