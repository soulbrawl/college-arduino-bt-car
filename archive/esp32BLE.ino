#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

BLEServer* pServer;
BLEService* pService;
BLECharacteristic* pCharacteristic;

void setup() {
  Serial.begin(115200);

  BLEDevice::init("RC_Car"); // Set your device name here
  pServer = BLEDevice::createServer();
  pService = pServer->createService(BLEUUID("ae3adb52-96a8-4852-b4bb-be887c380d3f")); // Set your service UUID here
  pCharacteristic = pService->createCharacteristic(BLEUUID("ae3adb52-96a8-4852-b4bb-be887c380d3f"), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);

  pCharacteristic->setCallbacks(new CharacteristicCallbacks());

  pService->start();
  BLEAdvertising* pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
}

void loop() {
  // Your ESP32 code here
}

class CharacteristicCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic* pCharacteristic) {
    std::string value = pCharacteristic->getValue();
    if (value.length() == 0) {
      return;
    }

    // Forward the received command to the Arduino Mega via Serial
    Serial.println(value.c_str());
  }
};
