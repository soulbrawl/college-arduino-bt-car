// #define DEBUG_MODE // Uncomment to enable (general [BT, etc.]) debugging
// #define DEBUG_MODE_ROUTINE_LOOPING_ONLY // Uncomment to enable testingRoutine looping

#define ENGINE_ACTIVE
#define US_ACTIVE // Ultrasonic Sensors

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

#include "pin.h"
#include "commonFunctions.h"

#include "US_HC-SR04.h"

// `speed` is declared here in this specific position considering headers below use it.
// uint8_t: 8-bit unsigned integer. Its range is typically from 0 to 255.
uint8_t speed = 60; // analog = 0 to 255
#include "engine.h"

constexpr uint8_t MIN_SPEED = 60; // analog = 0 to 255
constexpr uint8_t MAX_SPEED = 225; // analog = 0 to 255

// uint32_t: 32-bit unsigned integer (long)
uint32_t boostStartTime = 0;
uint32_t boostDuration = 1000; // (ms)
bool boostActive = false; // boost management flag

void setup() {
    #if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
    pinMode(BUILTIN_LED, OUTPUT);
    digitalWrite(BUILTIN_LED, HIGH);
    #endif

    Serial.begin(115200); // make sure your Serial Monitor is also set at this baud rate.
    Dabble.begin(9600); // (Serial3 [RX3/TX3 on Arduino]) Enter baudrate of your bluetooth module.

    #if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY) // running (only) once the car is started
    Serial.println("HC-05 is ready");
    Serial.println("*Remember to select baud rate and both NL & CR (CRLF in VSCode)");
    #endif

    #ifdef ENGINE_ACTIVE
    engineSetup();
    #endif

    #ifdef US_ACTIVE
    ultrasonicSensorSetup();
    #endif

    #ifdef DEBUG_MODE // running (only) once the car is started
    #ifdef ENGINE_ACTIVE
    engineTestingRoutine();
    #endif
    #ifdef US_ACTIVE
    ultrasonicSensorTestingRoutine();
    #endif
    #endif // DEBUG_MODE
}

void loop() {
    #ifdef DEBUG_MODE_ROUTINE_LOOPING_ONLY // looping indefinitely
    #ifdef ENGINE_ACTIVE
    engineTestingRoutine();
    #endif
    #ifdef US_ACTIVE
    ultrasonicSensorTestingRoutine();
    #endif
    #endif // DEBUG_MODE_ROUTINE_LOOPING_ONLY

    #ifndef DEBUG_MODE_ROUTINE_LOOPING_ONLY
    // The function below is used to refresh data obtained from smartphone.
    // Hence calling this function is mandatory in order to get data properly from your mobile.
    Dabble.processInput();

    #ifdef DEBUG_MODE // Serial Monitor debugging
    Serial.print("(DEBUG_MODE) ");
    #ifdef ENGINE_ACTIVE
    Serial.print("ENGINE: ON // ");
    #endif
    #ifndef ENGINE_ACTIVE
    Serial.print("ENGINE: OFF // ");
    #endif
    #ifdef US_ACTIVE
    Serial.print("US: ON // ");
    #endif
    #ifndef US_ACTIVE
    Serial.print("US: OFF // ");
    #endif
    Serial.print("speed = ");
    Serial.print(speed);
    Serial.print(" // KeyPressed: ");
    #endif // DEBUG_MODE

    if (!GamePad.isUpPressed() &&
        !GamePad.isDownPressed() &&
        !GamePad.isLeftPressed() &&
        !GamePad.isRightPressed()) {
        #ifdef ENGINE_ACTIVE
        stop();
        #endif
        #ifdef DEBUG_MODE
        Serial.println("NO direction pressed -> stop()");
        #endif
    }

    if (GamePad.isUpPressed()) {
        #ifdef ENGINE_ACTIVE
        forwards();
        #endif
        #ifdef DEBUG_MODE
        Serial.println("F -> forwards()");
        #endif
    }

    if (GamePad.isDownPressed()) {
        #ifdef ENGINE_ACTIVE
        backwards();
        #endif
        #ifdef DEBUG_MODE
        Serial.println("B -> backwards()");
        #endif
    }

    if (GamePad.isLeftPressed()) {
        #ifdef ENGINE_ACTIVE
        turnLeft();
        #endif
        #ifdef DEBUG_MODE
        Serial.println("L -> turnLeft()");
        #endif
    }

    if (GamePad.isRightPressed()) {
        #ifdef ENGINE_ACTIVE
        turnRight();
        #endif
        #ifdef DEBUG_MODE
        Serial.println("R -> turnRight()");
        #endif
    }

    if (GamePad.isCirclePressed()) {
        if (speed < MAX_SPEED) speed += 1;
        delay(5);
        #ifdef DEBUG_MODE
        Serial.print("Circle -> INCREASE speed by 1");
        #endif
    }

    if (GamePad.isCrossPressed()) {
        if (speed > MIN_SPEED) speed -= 1;
        delay(5);
        #ifdef DEBUG_MODE
        Serial.print("Cross -> DECREASE speed by 1");
        #endif
    }

    if (GamePad.isTrianglePressed()) {
        boostStartTime = millis();
        speed = MAX_SPEED;
        boostActive = true;
        #ifdef DEBUG_MODE
        Serial.print("Triangle -> MAX_SPEED");
        #endif
    } else if (millis() - boostStartTime >= boostDuration) {
        if (boostActive) speed = MIN_SPEED;
        boostActive = false;
    }

    if (GamePad.isSquarePressed()) {
        speed = MIN_SPEED;
        #ifdef DEBUG_MODE
        Serial.print("Square -> MIN_SPEED");
        #endif
    }

    // if (GamePad.isStartPressed()) {
    //     #ifdef DEBUG_MODE
    //     Serial.println("Start -> ");
    //     #endif
    // }

    // if (GamePad.isSelectPressed()) {
    //     #ifdef DEBUG_MODE
    //     Serial.println("Select -> ");
    //     #endif
    // }

    Serial.println();
    #endif // !DEBUG_MODE_ROUTINE_LOOPING_ONLY
}
