// #define DEBUG_MODE  // Uncomment to enable (general [BT, etc.]) debugging
// #define DEBUG_MODE_ROUTINE_LOOPING_ONLY // Uncomment to enable testingRoutine looping

// Dabble App Section
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#include "pin.h"
#include "commonFunctions.h"

#include "US_HC-SR04.h"

// `speed` is declared here in this specific position considering headers below use it.
// uint8_t: Represents an 8-bit unsigned integer. Its range is typically from 0 to 255.
uint8_t speed = 50; // analog = 0 to 255
#include "engine.h"

void setup() {
    #if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
    pinMode(BUILTIN_LED, OUTPUT);
    digitalWrite(BUILTIN_LED, HIGH);
    #endif

    Serial.begin(115200); // make sure your Serial Monitor is also set at this baud rate
    #if !defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
    Dabble.begin("RC-Car_dabble"); // set bluetooth name of your device
    #endif

    #if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY) // running (only) once the car is started
    Serial.println("ESP32 is ready");
    Serial.println("*Remember to select baud rate and both NL & CR (CRLF in VSCode)");
    #endif

    engineSetup();
    ultrasonicSensorSetup();

    #ifdef DEBUG_MODE // running (only) once the car is started
    engineTestingRoutine();
    ultrasonicSensorTestingRoutine();
    #endif
}

void loop() {
    #if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
    blinkLED(); // don't know if this works or conflict with everything below due the usage of delay()
    #endif

    #ifdef DEBUG_MODE_ROUTINE_LOOPING_ONLY // looping indefinitely
    engineTestingRoutine();
    ultrasonicSensorTestingRoutine();
    #endif

    #if !defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
    // The function below is used to refresh data obtained from smartphone.
    // Hence calling this function is mandatory in order to get data properly from your mobile.
    Dabble.processInput();

    #ifdef DEBUG_MODE
    Serial.print("KeyPressed: "); // Serial Monitor debugging
    #endif

    if (GamePad.isUpPressed()) {
        forwards();
        #ifdef DEBUG_MODE
        Serial.println('F -> forwards()');
        #endif
    }

    if (GamePad.isDownPressed()) {
        backwards();
        #ifdef DEBUG_MODE
        Serial.println('B -> backwards()');
        #endif
    }

    if (GamePad.isLeftPressed()) {
        turnLeft();
        #ifdef DEBUG_MODE
        Serial.println('L -> turnLeft()');
        #endif
    }

    if (GamePad.isRightPressed()) {
        turnRight();
        #ifdef DEBUG_MODE
        Serial.println('R -> turnRight()');
        #endif
    }

    // if (GamePad.isSquarePressed()) { // use while(runForDuration)??
    //     #ifdef DEBUG_MODE
    //     Serial.println('Square -> speed BOOST');
    //     #endif
    // }

    if (GamePad.isCirclePressed()) {
        if (speed < 235) speed += 10;
        #ifdef DEBUG_MODE
        Serial.println('Circle -> INCREASE speed by 10');
        #endif
    }

    if (GamePad.isCrossPressed()) {
        if (speed > 30) speed -= 10;
        #ifdef DEBUG_MODE
        Serial.println('Cross -> DECREASE speed by 10');
        #endif
    }

    // if (GamePad.isTrianglePressed()) {
    //     #ifdef DEBUG_MODE
    //     Serial.println('Triangle -> ');
    //     #endif
    // }

    // if (GamePad.isStartPressed()) {
    //     #ifdef DEBUG_MODE
    //     Serial.println('Start -> ');
    //     #endif
    // }

    // if (GamePad.isSelectPressed()) {
    //     #ifdef DEBUG_MODE
    //     Serial.println('Select -> ');
    //     #endif
    // }
    #endif
}
