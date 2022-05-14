#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#pragma once

class Camera {
  public:
    float x;
    float y;
    float angle;

    Camera();
};