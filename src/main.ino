// int tinkerCADhBridgeFix = 2;
int backwardRight = 8;
int forwardRight = 9;
int forwardLeft = 10;
int backwardLeft = 11;
// int buttonForward = 8;
// int buttonRear = 9;
// int buttonRight = 10;
// int buttonLeft = 11;
// int rearLEDindicator = 12;

void setup() {
    // pinMode(tinkerCADhBridgeFix, OUTPUT);
    pinMode(backwardRight, OUTPUT);
    pinMode(forwardRight, OUTPUT);
    pinMode(forwardLeft, OUTPUT);
    pinMode(backwardLeft, OUTPUT);
    // pinMode(rearLEDindicator, OUTPUT);
    // pinMode(buttonForward, INPUT);
    // pinMode(buttonRear, INPUT);
    // pinMode(buttonRight, INPUT);
    // pinMode(buttonLeft, INPUT);

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
    // digitalWrite(rearLEDindicator, HIGH);
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
    // digitalWrite(rearLEDindicator, LOW);
}

void loop() {
    // test
    // digitalWrite(backwardRight, LOW);  // 8
    // digitalWrite(forwardRight, HIGH);   // 9
    // digitalWrite(forwardLeft, HIGH);    // 10
    // digitalWrite(backwardLeft, LOW);   // 11

    // forwards
    digitalWrite(backwardRight, LOW);
    digitalWrite(forwardRight, HIGH);
    digitalWrite(forwardLeft, HIGH);
    digitalWrite(backwardLeft, LOW);

    delay(1000);

    // backwards()
    digitalWrite(backwardRight, HIGH);
    digitalWrite(forwardRight, LOW);
    digitalWrite(forwardLeft, LOW);
    digitalWrite(backwardLeft, HIGH);

    delay(1000);

    // // while(digitalRead(buttonForward) == HIGH) {
    //     forwards();
    //     delay(2000);
    // // }

    // // while(digitalRead(buttonRear) == HIGH) {
    //     backwards();
    //     delay(2000);
    // // }

    // // while(digitalRead(buttonRight) == HIGH) {
    //     turnRight();
    //     delay(2000);
    // // }

    // // while(digitalRead(buttonLeft) == HIGH) {
    //     turnLeft();
    //     delay(2000);
    // // }

    // fullStop();
    // delay(2000);
}