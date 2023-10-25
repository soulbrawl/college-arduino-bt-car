void engineSetup() {
    pinMode(InputFORWARD_Right, OUTPUT);
    pinMode(InputBACK_Right, OUTPUT);
    pinMode(InputFORWARD_Left, OUTPUT);
    pinMode(InputBACK_Left, OUTPUT);
}

void forwards() {
    analogWrite(InputFORWARD_Right, 50);
    digitalWrite(InputBACK_Right, LOW);
    analogWrite(InputFORWARD_Left, 50);
    digitalWrite(InputBACK_Left, LOW);
}

void backwards() {
    digitalWrite(InputFORWARD_Right, LOW);
    analogWrite(InputBACK_Right, 50);
    digitalWrite(InputFORWARD_Left, LOW);
    analogWrite(InputBACK_Left, 50);
}

void turnRight() {
    digitalWrite(InputFORWARD_Right, LOW);
    analogWrite(InputBACK_Right, 50);
    analogWrite(InputFORWARD_Left, 50);
    digitalWrite(InputBACK_Left, LOW);
}

void turnLeft() {
    analogWrite(InputFORWARD_Right, 50);
    digitalWrite(InputBACK_Right, LOW);
    digitalWrite(InputFORWARD_Left, LOW);
    analogWrite(InputBACK_Left, 50);
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
