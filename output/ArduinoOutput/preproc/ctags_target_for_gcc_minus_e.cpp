# 1 "/home/soulbrawl/facul/10-classes/_2023.2/6. PPI-IoT/college-arduino-bt-car/src/src.ino"
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

// Pin number for the internal LED on Arduino Mega
const int ledPin = 13;

void setup() {
    // Initialize the LED pin as an output
    pinMode(ledPin, 0x1);

    // pinMode(tinkerCADhBridgeFix, OUTPUT);
    pinMode(backwardRight, 0x1);
    pinMode(forwardRight, 0x1);
    pinMode(forwardLeft, 0x1);
    pinMode(backwardLeft, 0x1);
    // pinMode(rearLEDindicator, OUTPUT);
    // pinMode(buttonForward, INPUT);
    // pinMode(buttonRear, INPUT);
    // pinMode(buttonRight, INPUT);
    // pinMode(buttonLeft, INPUT);

    Serial.begin(9600);
}

void forwards() {
    // digitalWrite(tinkerCADhBridgeFix, HIGH);
    digitalWrite(backwardRight, 0x0);
    digitalWrite(forwardRight, 0x1);
    digitalWrite(forwardLeft, 0x1);
    digitalWrite(backwardLeft, 0x0);
}

void backwards() {
    // digitalWrite(tinkerCADhBridgeFix, HIGH);
    // digitalWrite(rearLEDindicator, HIGH);
    digitalWrite(backwardRight, 0x1);
    digitalWrite(forwardRight, 0x0);
    digitalWrite(forwardLeft, 0x0);
    digitalWrite(backwardLeft, 0x1);
}

void turnRight() {
    // digitalWrite(tinkerCADhBridgeFix, HIGH);
    digitalWrite(backwardRight, 0x1);
    digitalWrite(forwardRight, 0x0);
    digitalWrite(forwardLeft, 0x1);
    digitalWrite(backwardLeft, 0x0);
}

void turnLeft() {
    // digitalWrite(tinkerCADhBridgeFix, HIGH);
    digitalWrite(backwardRight, 0x0);
    digitalWrite(forwardRight, 0x1);
    digitalWrite(forwardLeft, 0x0);
    digitalWrite(backwardLeft, 0x1);
}

void fullStop() {
    // digitalWrite(tinkerCADhBridgeFix, LOW);
    digitalWrite(backwardRight, 0x0);
    digitalWrite(forwardRight, 0x0);
    digitalWrite(forwardLeft, 0x0);
    digitalWrite(backwardLeft, 0x0);
    // digitalWrite(rearLEDindicator, LOW);
}

void loop() {
    // Turn the LED on
    digitalWrite(ledPin, 0x1);
    delay(17); // Wait for 1 second (1000 milliseconds)

    // Turn the LED off
    digitalWrite(ledPin, 0x0);
    delay(17); // Wait for 1 second (1000 milliseconds)

    // test
    // digitalWrite(backwardRight, LOW);  // 8
    // digitalWrite(forwardRight, HIGH);   // 9
    // digitalWrite(forwardLeft, HIGH);    // 10
    // digitalWrite(backwardLeft, LOW);   // 11

    // // forwards
    // digitalWrite(backwardRight, LOW);
    // digitalWrite(forwardRight, HIGH);
    // digitalWrite(forwardLeft, HIGH);
    // digitalWrite(backwardLeft, LOW);

    // delay(1000);

    // // backwards()
    // digitalWrite(backwardRight, HIGH);
    // digitalWrite(forwardRight, LOW);
    // digitalWrite(forwardLeft, LOW);
    // digitalWrite(backwardLeft, HIGH);

    // delay(1000);

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
