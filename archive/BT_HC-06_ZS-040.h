// Bluetooth RXD to Arduino Mega pin 11
// Bluetooth TXD to Arduino Mega pin 10
// #define RxD 10
// #define TxD 11
// SoftwareSerial BTSerial(RxD, TxD);
// constexpr uint8_t BT_RX_PIN = 18;
// constexpr uint8_t BT_TX_PIN = 19;

#include <SoftwareSerial.h>
SoftwareSerial BTserial(BT_RX_PIN, BT_TX_PIN);

class bluetoothModule {
    private:

    public:
        char c = ' ';
        void BT_Setup() {
            constexpr uint16_t BT_BAUD_RATE = 38400;
            BTserial.begin(BT_BAUD_RATE); // default=38400
            Serial.print("BTserial started at ");
            Serial.println(BT_BAUD_RATE);
        }

        // Keep communication between the BT module and Arduino Serial Monitor
        void BT_Loop() {
            // Keep reading from HC-06 and send to Arduino Serial Monitor
            if (BTserial.available()) {
                c = BTserial.read();
                Serial.write(c); // Print the character received from Bluetooth to the serial monitor
            }

            // Keep reading from Arduino Serial Monitor and send to HC-06
            if (Serial.available()) {
                c = Serial.read();
                BTserial.write(c); // Send the character received from the serial monitor to Bluetooth
            }
        }

        // Bluetooth Display (Serial for now)
        void BT_Display() {
            Serial.print(BTserial.read());
            Serial.print("\n");
        }
};
bluetoothModule BT;