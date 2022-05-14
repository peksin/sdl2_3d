#include "math.h"

float radToDeg(float radians) {
  float degrees = (radians * 180) / M_PI;
  return degrees;
}

float degToRad(float degrees) {
  float radians = (degrees * M_PI) / 180;
  return radians;
}