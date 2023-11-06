#include <string.h>
#include "pin.h"
#include "commonFunctions.h"

#define SPEED 50 // analog = 0->255

#include "BT_ESP-WROOM-32.h"
// #include "US_HC-SR04.h"
// #include "engine.h"

char c = ' '; // for testing BT module Serial Monitor printing function
// IN HERE - without the header file

void setup() {
    // LED blinking (CONTROL) setup
    pinMode(BUILTIN_LED, OUTPUT);
    digitalWrite(BUILTIN_LED, HIGH);

    Serial.begin(9600); // default=9600
    Serial.println("Arduino is ready");
    // Serial.println("Remember to select Both NL & CR (CRLF in VSCode) in the serial monitor");

    // BT.BT_Setup();
    Serial2.begin(38400);
    Serial.println("BT_Setup OK");

    // engineSetup();
    // ultrasonicSensorSetup();

    // Debugging -- running (only) once the car is started
    // engineTestingRoutine();
    // ultrasonicSensorTestingRoutine();
}

void loop() {
    // LED blinking (CONTROL) test
    // blinkLED();

    // Testing movement proximity restrictions
    // while(runForDuration(3000)) {
    //     forwards();
    // }

    // while(runForDuration(3000)) {
    //     backwards();
    // }

    // Bluetooth Section
    // BT.BT_Loop();
    // BT.BT_Display();
    // char state = BT.c;

    // if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    //     state = Serial.read(); // Reads the data from the serial port
    // }

    // if (state == '0') {
    //     digitalWrite(BUILTIN_LED, LOW); // Turn LED OFF
    //     Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
    //     state = 0;
    // } else if (state == '1') {
    //     digitalWrite(BUILTIN_LED, HIGH);
    //     Serial.println("LED: ON");;
    //     state = 0;
    // }

    if (BTserial.available()) {
        // blinkLED();
        digitalWrite(BUILTIN_LED, LOW);
        c = BTserial.read();
        Serial.write(c); // Print the character received from Bluetooth to the serial monitor
    }

    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available()) {
        blinkLED();
        c = Serial.read();
        BTserial.write(c); // Send the character received from the serial monitor to Bluetooth
    }

    // Debugging -- looping
    // engineTestingRoutine();
    // ultrasonicSensorTestingRoutine();
}
