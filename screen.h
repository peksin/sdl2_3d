#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "player.h"

#pragma once



class Screen {
  public:
    SDL_Event e;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<SDL_FPoint> points;
    // Define a rectangle
    SDL_Rect rekt;

    Screen();

    void pixel(float x, float y);
    void show(Player* player);
    void input(Player* player);
    void drawShape(std::vector<SDL_FPoint> pixels);
};