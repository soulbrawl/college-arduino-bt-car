#if defined(DEBUG_MODE) || defined(DEBUG_MODE_ROUTINE_LOOPING_ONLY)
constexpr uint16_t TestDurationMillis = 3000;

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
#endif
