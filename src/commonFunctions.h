void blinkLED() {
    // Turn the LED on (HIGH) for 1 second.
    digitalWrite(BUILTIN_LED, HIGH);
    delay(300);

    // Turn the LED off (LOW) for 1 second.
    digitalWrite(BUILTIN_LED, LOW);
    delay(300);
}

bool runForDuration(unsigned long timeInMilliseconds) {
    static unsigned long functionStartTime;
    static bool functionActive = false;

    if (!functionActive) {
        functionStartTime = millis();
        // Function is not active, start it
        functionActive = true;
    }

    unsigned long currentTime = millis();

    if (currentTime - functionStartTime < timeInMilliseconds) {
        // Function is still active
        return true;
    } else {
        // Function duration has elapsed, reset and deactivate
        functionActive = false;
        return false;
    }
}
