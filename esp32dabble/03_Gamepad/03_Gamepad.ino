/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("RC-Car_dabble");       //set bluetooth name of your device
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  // Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    Serial.println('F');
  }

  if (GamePad.isDownPressed())
  {
    Serial.println('B');
  }

  if (GamePad.isLeftPressed())
  {
    Serial.println('L');
  }

  if (GamePad.isRightPressed())
  {
    Serial.println('R');
  }

  // if (GamePad.isSquarePressed())
  // {
  //   Serial.write('F'); // boost?
  // }

  // if (GamePad.isCirclePressed())
  // {
  //   Serial.write('F'); // increaseSpeed
  // }

  // if (GamePad.isCrossPressed())
  // {
  //   Serial.write('F'); // decreaseSpeed
  // }

  // if (GamePad.isTrianglePressed())
  // {
  //   Serial.write('F');
  // }

  // if (GamePad.isStartPressed())
  // {
  //   Serial.write('F');
  // }

  // if (GamePad.isSelectPressed())
  // {
  //   Serial.write('F');
  // }
}
