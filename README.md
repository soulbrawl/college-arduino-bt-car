# college-arduino-bt-rc-car
***(2023.2)*** College project involving a RC car controlled by an Arduino MEGA 2560 via Bluetooth using the HC-05 module and the [Dabble](https://ai.thestempedia.com/docs/dabble-app/getting-started-with-dabble/) app [Gamepad Module](https://ai.thestempedia.com/docs/dabble-app/gamepad-module/) [Android & iOS]) also featuring 4x Ultrasonic Sensors to prevent crashing.

- Logic Control: **Arduino MEGA 2560**
- BT: **HC-05 Module**
- Ultrasonic Sensor: **HC-SR04** *(check out `docs/`)*
- Phone BT app: ***[Dabble](https://ai.thestempedia.com/docs/dabble-app/getting-started-with-dabble/)*** [(Gamepad module)](https://ai.thestempedia.com/docs/dabble-app/gamepad-module/) *(Android & iOS)*

---

# TODO
- [ ] Set the right pins (`pin.h`)
- [ ] (maybe) Update/embed (properly) the main images under `media/` to this `README.md`

---

# DONE
- [x] Figure out how to *split the project code into multiple files **(headers)***
  - Writing the basics of the header files:
    - [x] `pin.h`
    - [x] `commonFunctions.h`
    - [x] `US_HC-SR04.h`
    - [x] `engine.h`
  - [x] Get the multiple files working together (at least 'Verifiable')
- [x] Rename all variables of `engineTesting.ino` since they're basically all wrong because I considered the wrong schematics *(credits to @EduardoDepari)*

## *@2023-10-26*
- [x] OPTIMIZATION: Ultrasonic Sensor `pulseIn()` duration **timeout**
- [x] FEATURE: (`src/commonFunctions.h`) `runForDuration()` function using `millis()`
  - [x] `while(runForDuration())` for `*testingRoutines()`

## *@2023-10-30*
- [x] FEATURE: `forwards()` - Movement restrictions based on sensors' proximity.

## *@2023-11-09*
- [x] *(tons of **refactoring** and **full migration from Arduino MEGA to ESP32**)*
- [x] Build: **Voltage regulator** for the **ESP32 (12 to 5V)** using a ***LM7805***
	- [x] Redoing of *power* circuits/**solderings** considering the migration above *(credits to @EduardoDepari and [@KaykyNakagawa](https://github.com/Kcioban))*

## *@2023-11-10*
- [x] Improved **data types** (`uint*_t`)
- [x] Usage of `constexpr` instead of `#define`
- [x] Added **proper debugging** modes
	- `DEBUG_MODE`
	- `DEBUG_MODE_ROUTINE_LOOPING_ONLY`

## *@2023-11-14*
- [x] Improved debugging modes
- [x] migrated back to Arduino due to college supply problems
- [x] FEATURE: added BOOST mode

---

## Remaining credits to...

- [@Rhyan](https://github.com/overtakerstrat) for all the 3D stuff
