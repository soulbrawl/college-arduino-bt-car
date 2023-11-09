# college-esp32-bt-rc-car
(2023.2) College project involving a RC car controlled by an ESP32 via Bluetooth using the Dabble Gamepad app (Android & iOS) also featuring 4x Ultrasonic Sensors to prevent crashing.

- BT and Logic Control: **ESP-WROOM-32**
- Ultrasonic Sensor: **HC-SR04** *(check out `docs/`)*
- Gamepad App: ***Dabble*** *(Android & iOS)*

---

# TODO
- Get and Build: **Voltage regulator** for the **ESP32 (12 to 9V)** using a ***LM7809***
	- [ ] LM7809
	- [ ] 100uF Capacitor
	- [ ] 0.1uF Capacitor
- [ ] Set the right pins (`pin.h`)
- [ ] Update/embed (properly) the main images under `media/` to this `README.md`

# DONE
- [x] Figure out how to split the project code into multiple files
  - Writing the basics of the header files:
    - [x] `pin.h`
    - [x] `commonFunctions.h`
    - [x] `US_HC-SR04.h`
    - [x] `engine.h`
  - [x] Get the multiple files working together (at least 'Verifiable')
- [x] Rename all variables of `engineTesting.ino` since they're basically all wrong because I considered the wrong schematics *(credits to @EduardoDepari)*

---

@2023-10-26
- [x] OPTIMIZATION: Ultrasonic Sensor `pulseIn()` duration **timeout**
- [x] FEATURE: (`src/commonFunctions.h`) `runForDuration()` function using `millis()`
  - [x] `while(runForDuration())` for *`testingRoutines()`

@2023-10-30
- [x] FEATURE: `forwards()` - Movement restrictions based on sensors' proximity.

@2023-11-09
- [x] *(tons of refactoring and full migration from Arduino MEGA to ESP32)*
