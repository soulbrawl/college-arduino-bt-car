// #define DEBUG_MODE // Uncomment to enable (general [BT, etc.]) debugging
// #define DEBUG_MODE_ROUTINE_LOOPING_ONLY // Uncomment to enable testingRoutine looping

#define ENGINE_ACTIVE
#define US_ACTIVE // Ultrasonic Sensors

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>



// Using `#define` textually REPLACES (like a macro) the value precompiling (or during compiling, not sure)
// thus using less memory than creating `const int` variables.
// Actually in this case, using `constexpr` is even better due to Type Safety and Compile-Time optimizations.
// check out more about the info above: https://chat.openai.com/share/491c1281-0e4d-4130-83fe-ee9a1a6c0dc7

#if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
constexpr uint8_t BUILTIN_LED = 13; // ESP32 = pin 2
#endif

#ifdef ENGINE_ACTIVE
constexpr uint8_t ENGINE_FL = 11; // verde
constexpr uint8_t ENGINE_FR = 8; // amarelo
constexpr uint8_t ENGINE_BL = 10; // azul pequeno
constexpr uint8_t ENGINE_BR = 9; // azul grande
#endif

#ifdef US_ACTIVE
constexpr uint8_t US_FL_TRIG_PIN = 26;
constexpr uint8_t US_FL_ECHO_PIN = 28;
constexpr uint8_t US_FR_TRIG_PIN = 31;
constexpr uint8_t US_FR_ECHO_PIN = 30;
constexpr uint8_t US_BL_TRIG_PIN = 52;
constexpr uint8_t US_BL_ECHO_PIN = 53;
constexpr uint8_t US_BR_TRIG_PIN = 50;
constexpr uint8_t US_BR_ECHO_PIN = 51;
#endif



#if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
constexpr uint16_t TestDurationMillis = 2000;

void blinkLED() {
    // Turn the LED on (HIGH) for 1 second.
    digitalWrite(BUILTIN_LED, HIGH);
    delay(300);

    // Turn the LED off (LOW) for 1 second.
    digitalWrite(BUILTIN_LED, LOW);
    delay(300);
}

bool runForDuration(uint64_t timeInMilliseconds) {
    static uint64_t functionStartTime;
    static bool functionActive = false;

    if (!functionActive) {
        functionStartTime = millis();
        // Function is not active, start it
        functionActive = true;
    }

    uint64_t currentTime = millis();

    if (currentTime - functionStartTime < timeInMilliseconds) {
        // Function is still active
        return true;
    } else {
        // Function duration has elapsed, reset and deactivate
        functionActive = false;
        return false;
    }
}
#endif // defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)



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



#ifdef ENGINE_ACTIVE
// `speed` is declared here in this specific position considering headers below use it.
// uint8_t: 8-bit unsigned integer. Its range is typically from 0 to 255.
uint8_t speed = 60; // analog = 0 to 255

constexpr uint8_t SafeDistance = 10;

void stop() {
    digitalWrite(ENGINE_FL, LOW);
    digitalWrite(ENGINE_FR, LOW);
    digitalWrite(ENGINE_BL, LOW);
    digitalWrite(ENGINE_BR, LOW);
}

void engineSetup() {
    pinMode(ENGINE_FL, OUTPUT);
    pinMode(ENGINE_FR, OUTPUT);
    pinMode(ENGINE_BL, OUTPUT);
    pinMode(ENGINE_BR, OUTPUT);
    stop();
}

void forwards() {
    #ifdef US_ACTIVE
    ultrasonicSensors[0].US_Loop();
    ultrasonicSensors[1].US_Loop();

    if (ultrasonicSensors[0]._distanceCm > SafeDistance &&
        ultrasonicSensors[1]._distanceCm > SafeDistance) {
        analogWrite(ENGINE_FL, speed);
        analogWrite(ENGINE_FR, speed);
        digitalWrite(ENGINE_BL, LOW);
        digitalWrite(ENGINE_BR, LOW);
    } else {
        stop();
    }
    #endif

    #ifndef US_ACTIVE
    analogWrite(ENGINE_FL, speed);
    analogWrite(ENGINE_FR, speed);
    digitalWrite(ENGINE_BL, LOW);
    digitalWrite(ENGINE_BR, LOW);
    #endif
}

void backwards() {
    #ifdef US_ACTIVE
    ultrasonicSensors[2].US_Loop();
    ultrasonicSensors[3].US_Loop();

    if (ultrasonicSensors[2]._distanceCm > SafeDistance &&
        ultrasonicSensors[3]._distanceCm > SafeDistance) {
        digitalWrite(ENGINE_FL, LOW);
        digitalWrite(ENGINE_FR, LOW);
        analogWrite(ENGINE_BL, speed);
        analogWrite(ENGINE_BR, speed);
    } else {
        stop();
    }
    #endif

    #ifndef US_ACTIVE
    digitalWrite(ENGINE_FL, LOW);
    digitalWrite(ENGINE_FR, LOW);
    analogWrite(ENGINE_BL, speed);
    analogWrite(ENGINE_BR, speed);
    #endif
}

void turnRight() {
    analogWrite(ENGINE_FL, speed);
    digitalWrite(ENGINE_FR, LOW);
    digitalWrite(ENGINE_BL, LOW);
    analogWrite(ENGINE_BR, speed);
}

void turnLeft() {
    digitalWrite(ENGINE_FL, LOW);
    analogWrite(ENGINE_FR, speed);
    analogWrite(ENGINE_BL, speed);
    digitalWrite(ENGINE_BR, LOW);
}

#if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
void (*engineMovementFunctions[5])() = {forwards, backwards, turnLeft, turnRight, stop};

void engineTestingRoutine() {
    for (uint8_t i = 0; i < 5; i++) {
        while (runForDuration(TestDurationMillis)) {
            engineMovementFunctions[i]();
        }
    }
}
#endif

#endif // ENGINE_ACTIVE



constexpr uint8_t MIN_SPEED = 60; // analog = 0 to 255
constexpr uint8_t MAX_SPEED = 225; // analog = 0 to 255

// uint32_t: 32-bit unsigned integer (long)
uint32_t boostStartTime = 0;
uint32_t boostDuration = 1000; // (ms)
bool boostActive = false; // boost management flag

void setup() {
    #if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
    pinMode(BUILTIN_LED, OUTPUT);
    digitalWrite(BUILTIN_LED, HIGH);
    #endif

    Serial.begin(115200); // make sure your Serial Monitor is also set at this baud rate.
    Dabble.begin(9600); // (Serial3 [RX3/TX3 on Arduino]) Enter baudrate of your bluetooth module.

    #if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY) // running (only) once the car is started
    Serial.println("HC-05 is ready");
    Serial.println("*Remember to select baud rate and both NL & CR (CRLF in VSCode)");
    #endif

    #ifdef ENGINE_ACTIVE
    engineSetup();
    #endif

    #ifdef US_ACTIVE
    ultrasonicSensorSetup();
    #endif

    #ifdef DEBUG_MODE // running (only) once the car is started
    #ifdef ENGINE_ACTIVE
    engineTestingRoutine();
    #endif
    #ifdef US_ACTIVE
    ultrasonicSensorTestingRoutine();
    #endif
    #endif // DEBUG_MODE
}

void loop() {
    #ifdef DEBUG_MODE_ROUTINE_LOOPING_ONLY // looping indefinitely
    #ifdef ENGINE_ACTIVE
    engineTestingRoutine();
    #endif
    #ifdef US_ACTIVE
    ultrasonicSensorTestingRoutine();
    #endif
    #endif // DEBUG_MODE_ROUTINE_LOOPING_ONLY

    #ifndef DEBUG_MODE_ROUTINE_LOOPING_ONLY
    // The function below is used to refresh data obtained from smartphone.
    // Hence calling this function is mandatory in order to get data properly from your mobile.
    Dabble.processInput();

    #ifdef DEBUG_MODE // Serial Monitor debugging
    Serial.print("(DEBUG_MODE) ");
    #ifdef ENGINE_ACTIVE
    Serial.print("ENGINE: ON // ");
    #endif
    #ifndef ENGINE_ACTIVE
    Serial.print("ENGINE: OFF // ");
    #endif
    #ifdef US_ACTIVE
    Serial.print("US: ON // ");
    #endif
    #ifndef US_ACTIVE
    Serial.print("US: OFF // ");
    #endif
    Serial.print("speed = ");
    Serial.print(speed);
    Serial.print(" // KeyPressed: ");
    #endif // DEBUG_MODE

    if (!GamePad.isUpPressed() &&
        !GamePad.isDownPressed() &&
        !GamePad.isLeftPressed() &&
        !GamePad.isRightPressed()) {
        #ifdef ENGINE_ACTIVE
        stop();
        #endif
        #ifdef DEBUG_MODE
        Serial.println("NO direction pressed -> stop()");
        #endif
    }

    if (GamePad.isUpPressed()) {
        #ifdef ENGINE_ACTIVE
        forwards();
        #endif
        #ifdef DEBUG_MODE
        Serial.println("F -> forwards()");
        #endif
    }

    if (GamePad.isDownPressed()) {
        #ifdef ENGINE_ACTIVE
        backwards();
        #endif
        #ifdef DEBUG_MODE
        Serial.println("B -> backwards()");
        #endif
    }

    if (GamePad.isLeftPressed()) {
        #ifdef ENGINE_ACTIVE
        turnLeft();
        #endif
        #ifdef DEBUG_MODE
        Serial.println("L -> turnLeft()");
        #endif
    }

    if (GamePad.isRightPressed()) {
        #ifdef ENGINE_ACTIVE
        turnRight();
        #endif
        #ifdef DEBUG_MODE
        Serial.println("R -> turnRight()");
        #endif
    }

    if (GamePad.isCirclePressed()) {
        if (speed < MAX_SPEED) speed += 1;
        delay(5);
        #ifdef DEBUG_MODE
        Serial.print("Circle -> INCREASE speed by 1");
        #endif
    }

    if (GamePad.isCrossPressed()) {
        if (speed > MIN_SPEED) speed -= 1;
        delay(5);
        #ifdef DEBUG_MODE
        Serial.print("Cross -> DECREASE speed by 1");
        #endif
    }

    if (GamePad.isTrianglePressed()) {
        boostStartTime = millis();
        speed = MAX_SPEED;
        boostActive = true;
        #ifdef DEBUG_MODE
        Serial.print("Triangle -> MAX_SPEED");
        #endif
    } else if (millis() - boostStartTime >= boostDuration) {
        if (boostActive) speed = MIN_SPEED;
        boostActive = false;
    }

    if (GamePad.isSquarePressed()) {
        speed = MIN_SPEED;
        #ifdef DEBUG_MODE
        Serial.print("Square -> MIN_SPEED");
        #endif
    }

    Serial.println();
    #endif // !DEBUG_MODE_ROUTINE_LOOPING_ONLY
}
