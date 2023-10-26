void engineSetup() {
    pinMode(InputFORWARD_Right, OUTPUT);
    pinMode(InputBACK_Right, OUTPUT);
    pinMode(InputFORWARD_Left, OUTPUT);
    pinMode(InputBACK_Left, OUTPUT);
}

void forwards() {
    analogWrite(InputFORWARD_Right, SPEED);
    digitalWrite(InputBACK_Right, LOW);
    analogWrite(InputFORWARD_Left, SPEED);
    digitalWrite(InputBACK_Left, LOW);
}

void backwards() {
    digitalWrite(InputFORWARD_Right, LOW);
    analogWrite(InputBACK_Right, SPEED);
    digitalWrite(InputFORWARD_Left, LOW);
    analogWrite(InputBACK_Left, SPEED);
}

void turnRight() {
    digitalWrite(InputFORWARD_Right, LOW);
    analogWrite(InputBACK_Right, SPEED);
    analogWrite(InputFORWARD_Left, SPEED);
    digitalWrite(InputBACK_Left, LOW);
}

void turnLeft() {
    analogWrite(InputFORWARD_Right, SPEED);
    digitalWrite(InputBACK_Right, LOW);
    digitalWrite(InputFORWARD_Left, LOW);
    analogWrite(InputBACK_Left, SPEED);
}

void stop() {
    digitalWrite(InputFORWARD_Right, LOW);
    digitalWrite(InputBACK_Right, LOW);
    digitalWrite(InputFORWARD_Left, LOW);
    digitalWrite(InputBACK_Left, LOW);
}

void (*engineMovementFunctions[])() = {forwards, backwards, turnLeft, turnRight};

void engineTestingRoutine() {
    for (int i = 0; i < 4; i++) {
        engineMovementFunctions[i]();
        delay(2000);
        stop();
    }
}
