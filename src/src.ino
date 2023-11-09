#include <string.h>
#include "pin.h"
#include "commonFunctions.h"

#define SPEED 50 // analog = 0->255

// #include "BT_ESP-WROOM-32.h"
#include "US_HC-SR04.h"
#include "engine.h"

#include <SoftwareSerial.h>
SoftwareSerial espSerial(2, 3); // RX, TX on Arduino Mega

void setup() {
    Serial.begin(9600); // default=9600
    Serial.println("Arduino is ready");
    // Serial.println("Remember to select Both NL & CR (CRLF in VSCode) in the serial monitor");

    espSerial.begin(115200);
    Serial.println("espSerial OK");

    engineSetup();
    ultrasonicSensorSetup();

    // Debugging -- running (only) once the car is started
    // engineTestingRoutine();
    // ultrasonicSensorTestingRoutine();
}

void loop() {
    // Testing movement proximity restrictions
    // while(runForDuration(3000)) {
    //     forwards();
    // }

    // while(runForDuration(3000)) {
    //     backwards();
    // }


    // RC car's control logic based on the commands received from ESP32 via SoftwareSerial (espSerial).

    if (espSerial.available()) {
        char command = espSerial.read();

        if (command == 'F') {
            // forwards();
            Serial.println("forwards()");
        } else if (command == 'B') {
            // backwards();
            Serial.println("backwards()");
        } else if (command == 'L') {
            // turnLeft();
            Serial.println("turnLeft()");
        } else if (command == 'R') {
            // turnRight();
            Serial.println("turnRight()");
        } else {
            // stop();
            Serial.println("stop()");
        }
    }

    // Debugging -- looping
    // engineTestingRoutine();
    // ultrasonicSensorTestingRoutine();
}
