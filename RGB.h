/*
 * RGB.h - Library to facilitate use of RGB LEds.
 * Author: MeZN
 * Date: 13 December, 2020
*/

#ifndef RGB_H_
#define RGB_H_

#include"Arduino.h"


struct Color {
  uint8_t redValue;
  uint8_t greenValue;
  uint8_t blueValue;
};


class RGB {
  private:
  uint8_t redPin, greenPin, bluePin;    //Red, green and blue LED pins of the RGB LED.
  bool commonCathode;                   //True if LED is common cathode(common ground). False if LED common anode(common Vcc).

  public:
  static inline const Color RED = {255,0,0}, GREEN = {0,255,0}, BLUE = {0,0,255},
                     WHITE = {255, 255, 255}, GREY = {128,128,128}, YELLOW = {255,255,0},
                     CYAN = {0,255,255}, PURPLE = {127,0,255}, PINK = {255,0,255};
  
  RGB(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, bool commonCathode);   //Constructor.

  void turnOff();       //Turns off the LED entirely.
  void lightRGB(uint8_t redValue, uint8_t greenValue, uint8_t blueValue);   //lights the LED using RGB values.
  void lightRGB(Color color);       //Lights the LED using struct Color variable.
};


#endif
