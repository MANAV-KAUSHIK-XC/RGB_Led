#include"Arduino.h"
#include"RGB.h"

RGB::RGB(uint8_t redPin, uint8_t greenPin, uint8_t bluePin, bool commonCathode) {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  this->redPin = redPin;
  this->greenPin = greenPin;
  this->bluePin = bluePin;
  this->commonCathode = commonCathode;

  turnOff();
}

void RGB::turnOff() {
  if(commonCathode) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  else {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  }
}

void RGB::lightRGB(uint8_t redValue, uint8_t greenValue, uint8_t blueValue) {
  if(commonCathode) {
    analogWrite(redPin, redValue);
    analogWrite(greenPin, greenValue);
    analogWrite(bluePin, blueValue);
  }
  else {
    analogWrite(redPin, 255-redValue);
    analogWrite(greenPin, 255-greenValue);
    analogWrite(bluePin, 255-blueValue);
  }
}

void RGB::lightRGB(Color color) {
  if(commonCathode) {
    analogWrite(redPin, color.redValue);
    analogWrite(greenPin, color.greenValue);
    analogWrite(bluePin, color.blueValue);
  }
  else {
    analogWrite(redPin, 255 - color.redValue);
    analogWrite(greenPin, 255 - color.greenValue);
    analogWrite(bluePin, 255 - color.blueValue);
  }
}
