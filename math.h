#include <stdio.h>
#include <iostream>
#include <vector>

#include "screen.h"

#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

/* Mathematical helper functions */

float radToDeg(float rad);
float degToRad(float deg);
float getDistance(Pixel a, Pixel b);
float getDistance(float x1, float y1, float x2, float y2);