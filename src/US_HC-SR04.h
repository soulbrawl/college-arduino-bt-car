class ultrassonicSensor {

    private:
        // HC-04 variables
        int _trigPin;
        int _echoPin;
        long _duration;
        int _distanceCm;

    public:
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

        // Bluetooth Display (Serial for now)
        void US_Display() {
            Serial.print(_distanceCm);
            Serial.print(" Cm distance");
            Serial.print("                ");
        }
};
ultrassonicSensor US;