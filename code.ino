// int tinkerCADhBridgeFix = 2;
int backwardRight = 3;
int forwardRight = 4;
int forwardLeft = 5;
int backwardLeft = 6;
int buttonForward = 8;
int buttonRear = 9;
int buttonRight = 10;
int buttonLeft = 11;
int rearLEDindicator = 12;

void setup() {
    // pinMode(tinkerCADhBridgeFix, OUTPUT);
    pinMode(backwardRight, OUTPUT);
    pinMode(forwardRight, OUTPUT);
    pinMode(forwardLeft, OUTPUT);
    pinMode(backwardLeft, OUTPUT);
    pinMode(rearLEDindicator, OUTPUT);
    pinMode(buttonForward, INPUT);
    pinMode(buttonRear, INPUT);
    pinMode(buttonRight, INPUT);
    pinMode(buttonLeft, INPUT);

    Serial.begin(9600);
}

void forwards() {
    // digitalWrite(tinkerCADhBridgeFix, HIGH);
    digitalWrite(backwardRight, LOW);
    digitalWrite(forwardRight, HIGH);
    digitalWrite(forwardLeft, HIGH);
    digitalWrite(backwardLeft, LOW);
}

void backwards() {
    // digitalWrite(tinkerCADhBridgeFix, HIGH);
    digitalWrite(rearLEDindicator, HIGH);
    digitalWrite(backwardRight, HIGH);
    digitalWrite(forwardRight, LOW);
    digitalWrite(forwardLeft, LOW);
    digitalWrite(backwardLeft, HIGH);
}

void turnRight() {
    // digitalWrite(tinkerCADhBridgeFix, HIGH);
    digitalWrite(backwardRight, HIGH);
    digitalWrite(forwardRight, LOW);
    digitalWrite(forwardLeft, HIGH);
    digitalWrite(backwardLeft, LOW);
}

void turnLeft() {
    // digitalWrite(tinkerCADhBridgeFix, HIGH);
    digitalWrite(backwardRight, LOW);
    digitalWrite(forwardRight, HIGH);
    digitalWrite(forwardLeft, LOW);
    digitalWrite(backwardLeft, HIGH);
}

void fullStop() {
    // digitalWrite(tinkerCADhBridgeFix, LOW);
    digitalWrite(backwardRight, LOW);
    digitalWrite(forwardRight, LOW);
    digitalWrite(forwardLeft, LOW);
    digitalWrite(backwardLeft, LOW);
    digitalWrite(rearLEDindicator, LOW);
}

void loop() {
    while(digitalRead(buttonForward) == HIGH) {
        forwards();
    }

    while(digitalRead(buttonRear) == HIGH) {
        backwards();
    }

    while(digitalRead(buttonRight) == HIGH) {
        turnRight();
    }

    while(digitalRead(buttonLeft) == HIGH) {
        turnLeft();
    }

    fullStop();
}