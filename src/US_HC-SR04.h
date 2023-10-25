class UltrasonicSensor {

    private:
        // HC-04 variables
        int _trigPin;
        int _echoPin;
        long _duration;
        int _distanceCm;
        String _id;

    public:
        UltrasonicSensor(String id) {
            _id = id;
        }

        void US_Setup(int trigPin, int echoPin) {
            // HC-04 variables
            long duration;
            int distance;

            _trigPin = trigPin;
            _echoPin = echoPin;
            _duration = duration;
            _distanceCm = distance;

            //HC-SR04 setup
            pinMode(_trigPin, OUTPUT);
            pinMode(_echoPin , INPUT);
        }

        //HC-SR04 Loop
        void US_Loop() {
            // Clears the trigPin
            digitalWrite(_trigPin, LOW);
            delayMicroseconds(2);

            // Sets the trigPin on HIGH state for 10 micro seconds
            digitalWrite(_trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(_trigPin, LOW);

            // Reads the echoPin, returns the sound wave travel time in microseconds
            _duration = pulseIn(_echoPin, HIGH);

            // Calculating the distance
            _distanceCm = _duration * 0.034 / 2;
        }

        // THINKING: maybe this function can be integrated in the one above (US_Loop)
        //           although I don't know if it's the best option/implementation resource-wise
        //           maybe it would create some overhead or something
        int US_Distance() {
            return _distanceCm;
        }

        // THINKING: Integrating this function above as well?
        // Bluetooth Display (Serial Monitor for now)
        void US_Display() {
            Serial.print(_id);
            Serial.print(_distanceCm);
            Serial.print(" Cm distance");
            Serial.print("\n");
            // Serial.print("                "); // or using a Display module
        }
};

// creating each Ultrasonic Sensor class/object
UltrasonicSensor ultrasonicSensors[] = {
    UltrasonicSensor("FL"),
    UltrasonicSensor("FR"),
    UltrasonicSensor("BL"),
    UltrasonicSensor("BR")
};
// UltrasonicSensor US_FL;
// UltrasonicSensor US_FR;
// UltrasonicSensor US_BL;
// UltrasonicSensor US_BR;

void ultrasonicSensorSetup() {
    ultrasonicSensors[0].US_Setup(US_FL_TRIG_PIN, US_FL_ECHO_PIN);
    US_FR.US_Setup(US_FR_TRIG_PIN, US_FR_ECHO_PIN);
    US_BL.US_Setup(US_BL_TRIG_PIN, US_BL_ECHO_PIN);
    US_BR.US_Setup(US_BR_TRIG_PIN, US_BR_ECHO_PIN);

    // US_FL.US_Setup(US_FL_TRIG_PIN, US_FL_ECHO_PIN);
    // US_FR.US_Setup(US_FR_TRIG_PIN, US_FR_ECHO_PIN);
    // US_BL.US_Setup(US_BL_TRIG_PIN, US_BL_ECHO_PIN);
    // US_BR.US_Setup(US_BR_TRIG_PIN, US_BR_ECHO_PIN);
}

String sensorNames[] = {"FL", "FR", "BL", "BR"};

void ultrasonicSensorTestingRoutine() {

    for (int i = 0; i < 4; i++) {
        ultrasonicSensors[i].US_Loop();
        Serial.print(sensorNames[i] + ": ");
        ultrasonicSensors[i].US_Display();
    }


    US_FL.US_Loop();
    Serial.print("FL: ");
    US_FL.US_Display();

    US_FR.US_Loop();
    Serial.print("FR: ");
    US_FR.US_Display();

    US_BL.US_Loop();
    Serial.print("BL: ");
    US_BL.US_Display();

    US_BR.US_Loop();
    Serial.print("BR: ");
    US_BR.US_Display();
}
