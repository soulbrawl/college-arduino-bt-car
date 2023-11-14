#ifdef ENGINE_ACTIVE
constexpr uint8_t SafeDistance = 10;

void stop() {
    digitalWrite(ENGINE_FL, LOW);
    digitalWrite(ENGINE_FR, LOW);
    digitalWrite(ENGINE_BL, LOW);
    digitalWrite(ENGINE_BR, LOW);
}

void engineSetup() {
    pinMode(ENGINE_FL, OUTPUT);
    pinMode(ENGINE_FR, OUTPUT);
    pinMode(ENGINE_BL, OUTPUT);
    pinMode(ENGINE_BR, OUTPUT);
    stop();
}

void forwards() {
    #ifdef US_ACTIVE
    ultrasonicSensors[0].US_Loop();
    ultrasonicSensors[1].US_Loop();

    if (ultrasonicSensors[0]._distanceCm > SafeDistance &&
        ultrasonicSensors[1]._distanceCm > SafeDistance) {
        analogWrite(ENGINE_FL, speed);
        analogWrite(ENGINE_FR, speed);
        digitalWrite(ENGINE_BL, LOW);
        digitalWrite(ENGINE_BR, LOW);
    } else {
        stop();
    }
    #endif

    #ifndef US_ACTIVE
    analogWrite(ENGINE_FL, speed);
    analogWrite(ENGINE_FR, speed);
    digitalWrite(ENGINE_BL, LOW);
    digitalWrite(ENGINE_BR, LOW);
    #endif
}

void backwards() {
    #ifdef US_ACTIVE
    ultrasonicSensors[2].US_Loop();
    ultrasonicSensors[3].US_Loop();

    if (ultrasonicSensors[2]._distanceCm > SafeDistance &&
        ultrasonicSensors[3]._distanceCm > SafeDistance) {
        digitalWrite(ENGINE_FL, LOW);
        digitalWrite(ENGINE_FR, LOW);
        analogWrite(ENGINE_BL, speed);
        analogWrite(ENGINE_BR, speed);
    } else {
        stop();
    }
    #endif

    #ifndef US_ACTIVE
    digitalWrite(ENGINE_FL, LOW);
    digitalWrite(ENGINE_FR, LOW);
    analogWrite(ENGINE_BL, speed);
    analogWrite(ENGINE_BR, speed);
    #endif
}

void turnRight() {
    analogWrite(ENGINE_FL, speed);
    digitalWrite(ENGINE_FR, LOW);
    digitalWrite(ENGINE_BL, LOW);
    analogWrite(ENGINE_BR, speed);
}

void turnLeft() {
    digitalWrite(ENGINE_FL, LOW);
    analogWrite(ENGINE_FR, speed);
    analogWrite(ENGINE_BL, speed);
    digitalWrite(ENGINE_BR, LOW);
}

#if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
void (*engineMovementFunctions[5])() = {forwards, backwards, turnLeft, turnRight, stop};

void engineTestingRoutine() {
    for (uint8_t i = 0; i < 5; i++) {
        while (runForDuration(TestDurationMillis)) {
            engineMovementFunctions[i]();
        }
    }
}
#endif

#endif // ENGINE_ACTIVE