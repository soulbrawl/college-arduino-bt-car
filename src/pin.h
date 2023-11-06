// DELETE/COMMENT when VERIFYING/UPLOADING the includes below
// -- poor fix for VSCode syntax highlighting BUG
// #define SPEED 50 // analog = 0->255

// Using `#define` REPLACES (like a macro) the value precompiling (or during compiling, not sure)
// thus using less memory than creating `const int` variables.
#define BUILTIN_LED 13

// Bluetooth RXD to Arduino Mega pin 11
// Bluetooth TXD to Arduino Mega pin 10
// #define RxD 10
// #define TxD 11
// SoftwareSerial BTSerial(RxD, TxD);
#define BT_RX_PIN 15
#define BT_TX_PIN 14

#define ENGINE_FL 11
#define ENGINE_FR 8
#define ENGINE_BL 10
#define ENGINE_BR 9

#define US_FL_TRIG_PIN 52 // 11
#define US_FL_ECHO_PIN 53 // 10
#define US_FR_TRIG_PIN 50
#define US_FR_ECHO_PIN 51
#define US_BL_TRIG_PIN 48
#define US_BL_ECHO_PIN 49
#define US_BR_TRIG_PIN 46
#define US_BR_ECHO_PIN 47
