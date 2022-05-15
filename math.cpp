#include "math.h"

float radToDeg(float radians) {
  float degrees = (radians * 180) / M_PI;
  return degrees;
}

float degToRad(float degrees) {
  float radians = (degrees * M_PI) / 180;
  return radians;
}

float getDistance(Pixel a, Pixel b) {
  return std::sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

float getDistance(float x1, float y1, float x2, float y2) {
  return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}