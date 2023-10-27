#include <SoftwareSerial.h>
SoftwareSerial BTserial(BT_RX_PIN, BT_TX_PIN);



class bluetoothModule {

    private:

    public:
        void BT_Setup() {
            BTserial.begin(38400); // default=38400
            Serial.println("BTserial started at 38400");
        }

        // Keep communication between the BT module and Arduino Serial Monitor
        void BT_Loop() {
            // Keep reading from HC-06 and send to Arduino Serial Monitor
            if (BTserial.available()) {
                Serial.write(BTserial.read());
            }

            // Keep reading from Arduino Serial Monitor and send to HC-06
            if (Serial.available()) {
                BTserial.write(Serial.read());
            }
        }

        // Bluetooth Display (Serial for now)
        // void BT_Display() {
        //     Serial.print(BTserial.read());
        //     Serial.print("                ");
        // }
};
bluetoothModule BT;