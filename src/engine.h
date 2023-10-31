// DELETE/COMMENT when VERIFYING/UPLOADING the includes below
// -- poor fix for VSCode syntax highlighting BUG
// #include "pin.h"
// #include "US_HC-SR04.h"
// #include "commonFunctions.h"

const unsigned int safeDistance = 10;

void engineSetup() {
    pinMode(ENGINE_FL, OUTPUT);
    pinMode(ENGINE_FR, OUTPUT);
    pinMode(ENGINE_BL, OUTPUT);
    pinMode(ENGINE_BR, OUTPUT);
}

void stop() {
    digitalWrite(ENGINE_FL, LOW);
    digitalWrite(ENGINE_FR, LOW);
    digitalWrite(ENGINE_BL, LOW);
    digitalWrite(ENGINE_BR, LOW);
}

void forwards() {
    ultrasonicSensors[0].US_Loop();
    ultrasonicSensors[1].US_Loop();

    if (ultrasonicSensors[0]._distanceCm > safeDistance &&
        ultrasonicSensors[1]._distanceCm > safeDistance) {
        analogWrite(ENGINE_FL, SPEED);
        analogWrite(ENGINE_FR, SPEED);
        digitalWrite(ENGINE_BL, LOW);
        digitalWrite(ENGINE_BR, LOW);
    } else {
        stop();
    }
}

void backwards() {
    ultrasonicSensors[2].US_Loop();
    ultrasonicSensors[3].US_Loop();

    if (ultrasonicSensors[2]._distanceCm > safeDistance &&
        ultrasonicSensors[3]._distanceCm > safeDistance) {
        digitalWrite(ENGINE_FL, LOW);
        digitalWrite(ENGINE_FR, LOW);
        analogWrite(ENGINE_BL, SPEED);
        analogWrite(ENGINE_BR, SPEED);
    } else {
        stop();
    }
}

void turnRight() {
    analogWrite(ENGINE_FL, SPEED);
    digitalWrite(ENGINE_FR, LOW);
    digitalWrite(ENGINE_BL, LOW);
    analogWrite(ENGINE_BR, SPEED);
}

void turnLeft() {
    digitalWrite(ENGINE_FL, LOW);
    analogWrite(ENGINE_FR, SPEED);
    analogWrite(ENGINE_BL, SPEED);
    digitalWrite(ENGINE_BR, LOW);
}

void (*engineMovementFunctions[5])() = {forwards, backwards, turnLeft, turnRight, stop};

void engineTestingRoutine() {
    for (int i = 0; i < 5; i++) {
        while (runForDuration(2000)) {
            engineMovementFunctions[i]();
        }
    }
}
