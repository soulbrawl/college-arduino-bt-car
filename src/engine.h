void engineSetup() {
    pinMode(ENGINE_FL, OUTPUT);
    pinMode(ENGINE_FR, OUTPUT);
    pinMode(ENGINE_BL, OUTPUT);
    pinMode(ENGINE_BR, OUTPUT);
}

void forwards() {
    // while(ultrasonicSensors[0]->US_Distance > 10)
    analogWrite(ENGINE_FL, SPEED);
    analogWrite(ENGINE_FR, SPEED);
    digitalWrite(ENGINE_BL, LOW);
    digitalWrite(ENGINE_BR, LOW);
}

void backwards() {
    digitalWrite(ENGINE_FL, LOW);
    digitalWrite(ENGINE_FR, LOW);
    analogWrite(ENGINE_BL, SPEED);
    analogWrite(ENGINE_BR, SPEED);
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

void stop() {
    digitalWrite(ENGINE_FL, LOW);
    digitalWrite(ENGINE_FR, LOW);
    digitalWrite(ENGINE_BL, LOW);
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
