#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#pragma once


class Player {
  public:
    float x;
    float y;
    int angle;
    int length;

    Player();
    std::vector<std::pair<SDL_FPoint, SDL_Color>> render(float x_off = 0, float y_off = 0, int paramAngle = 0);
    void move(float dx, float dy);
    void walk(int speed);
    void rotate(int dAngle);


};