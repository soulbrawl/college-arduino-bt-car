# college-arduino-bt-car
College project involving a RC car controlled by an Arduino MEGA via Bluetooth also featuring Ultrasonic Sensors to prevent crashing.

- Ultrasonic Sensor: **HC-SR04** *(check out `docs/`)*
- Bluetooth Module: **ZS-040 (HC-05)** *(check out `docs/`)*
	- Our specific chip: https://www.hc01.com/goods/640e91920be12d0114404c96
	- https://www.martyncurrey.com/arduino-and-HC-05-zs-040/
		- *"There are several slightly different versions of the HC-05, however, all seem to use the same firmware and have the same AT commands."*
		- *"The Bluetooth module the ZS-040 is based on, the EGBT-046S, is a 3.3V device. The HC-05 breakout board has a 3.3v regulator that allows a larger input voltage to be used, in the range of 3.6 to 6 volts. The RX pin can still only accept 3.3V though. This means a voltage divider is required to connect to a 5V Arduino. **A simple voltage divider can be created using 2 resistors. I am using a 1K ohm resistor and a 2K ohm resistor.** The Arduino will read 3.3V as a HIGH so the HC-05 TX pin can be connected directly to the Arduino."*
		- https://ohmslawcalculator.com/voltage-divider-calculator
			- (media/HC-05_ZS-040_02.png)
	- https://www.alldatasheet.net/datasheet-pdf/pdf/1253161/ETC1/ZS-040.html
	- *"The **small push button switch, when closed, connects pin 34 to vcc which allows you to enter AT mode**."*
	- (media/HC-05_ZS-040_01.png)

---

# TODO
- [ ] FIX the duplicity of `.vscode/*` files considering running on Linux AND Windows
- [ ] Update/embed (properly) the main images under `media/` to this `README.md`

# DONE
- [x] Figure out how to split the project code into multiple files
  - Writing the basics of the header files:
    - [x] `pin.h`
    - [x] `commonFunctions.h`
    - [x] `BT_HC-05_ZS-040.h`
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
