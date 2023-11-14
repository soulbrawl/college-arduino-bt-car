#ifdef US_ACTIVE

class UltrasonicSensor {
    private:
        // HC-04 variables
        uint8_t _trigPin;
        uint8_t _echoPin;
        long _duration;
        char _id[3]; // Assuming IDs are two characters plus null terminator

        // In C++, non-static data members cannot be declared as constexpr directly within the class definition,
        // unless they are also `static`. If these constants are intended to be the same for all instances of the class
        // and do not depend on instance-specific information, you can make them `static`.
        static constexpr uint16_t PulseInTimeoutMicros = 24000;
        static constexpr uint16_t MaxRange = 400;

    public:
        // Constructor
        // No need for Destructing since I'm not using pointers in any Constructor
        UltrasonicSensor(const char id[3]) { // not recommended to use `constexpr` on function parameters
            // Copy characters from the provided id to the _id array
            strncpy(_id, id, sizeof(_id) - 1);
            // Ensure null termination
            _id[sizeof(_id) - 1] = '\0';
        }

        uint16_t _distanceCm;

        void US_Setup(uint8_t trigPin, uint8_t echoPin) {
            // HC-04 variables
            _trigPin = trigPin;
            _echoPin = echoPin;

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
            _duration = pulseIn(_echoPin, HIGH, PulseInTimeoutMicros);

            // Calculating the distance
            _distanceCm = _duration * 0.034 / 2;

            if (_distanceCm == 0) _distanceCm = MaxRange;
        }

        #if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
        void US_Display() {
            Serial.print(_id);
            Serial.print(": ");
            Serial.print(_distanceCm);
            Serial.print(" Cm distance");
            Serial.print("\n");
        }
        #endif
};

// creating each Ultrasonic Sensor class/object
UltrasonicSensor ultrasonicSensors[4] = {
    UltrasonicSensor("FL"),
    UltrasonicSensor("FR"),
    UltrasonicSensor("BL"),
    UltrasonicSensor("BR")
};

void ultrasonicSensorSetup() {
    ultrasonicSensors[0].US_Setup(US_FL_TRIG_PIN, US_FL_ECHO_PIN);
    ultrasonicSensors[1].US_Setup(US_FR_TRIG_PIN, US_FR_ECHO_PIN);
    ultrasonicSensors[2].US_Setup(US_BL_TRIG_PIN, US_BL_ECHO_PIN);
    ultrasonicSensors[3].US_Setup(US_BR_TRIG_PIN, US_BR_ECHO_PIN);
}

#if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
void ultrasonicSensorTestingRoutine() {
    for (int i = 0; i < 4; i++) {
        while (runForDuration(TestDurationMillis)) {
            ultrasonicSensors[i].US_Loop();
            ultrasonicSensors[i].US_Display();
        }
    }
}
#endif

#endif // US_ACTIVE