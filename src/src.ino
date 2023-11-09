// Dabble App Section
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#include <string.h>
#include "pin.h"
#include "commonFunctions.h"

// uint8_t: Represents an 8-bit unsigned integer. Its range is typically from 0 to 255.
uint8_t speed = 50; // analog = 0 to 255

#include "US_HC-SR04.h"
#include "engine.h"

void setup() {
    Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
    Dabble.begin("RC-Car_dabble");       //set bluetooth name of your device
    Serial.println("ESP32 is ready");
    // Serial.println("Remember to select Both NL & CR (CRLF in VSCode) in the serial monitor");

    engineSetup();
    ultrasonicSensorSetup();

    // Debugging -- running (only) once the car is started
    // engineTestingRoutine();
    // ultrasonicSensorTestingRoutine();
}

void loop() {
    // The function below is used to refresh data obtained from smartphone.
    // Hence calling this function is mandatory in order to get data properly from your mobile.
    Dabble.processInput();

    Serial.print("KeyPressed: "); // Serial Monitor debugging

    if (GamePad.isUpPressed()) {
        forwards();
        Serial.println('F -> forwards()');
    }

    if (GamePad.isDownPressed()) {
        backwards();
        Serial.println('B -> backwards()');
    }

    if (GamePad.isLeftPressed()) {
        turnLeft();
        Serial.println('L -> turnLeft()');
    }

    if (GamePad.isRightPressed()) {
        turnRight();
        Serial.println('R -> turnRight()');
    }

    // if (GamePad.isSquarePressed()) { // use while(runForDuration)??
    //     Serial.println('Square -> speed BOOST');
    // }

    if (GamePad.isCirclePressed()) {
        if (speed < 235) speed += 10;
        Serial.println('Circle -> INCREASE speed by 10');
    }

    if (GamePad.isCrossPressed()) {
        if (speed > 30) speed -= 10;
        Serial.println('Cross -> DECREASE speed by 10');
    }

    // if (GamePad.isTrianglePressed()) {
    //     Serial.println('Triangle -> ');
    // }

    // if (GamePad.isStartPressed()) {
    //     Serial.println('Start -> ');
    // }

    // if (GamePad.isSelectPressed()) {
    //     Serial.println('Select -> ');
    // }


    // Debugging -- looping
    // engineTestingRoutine();
    // ultrasonicSensorTestingRoutine();
}
