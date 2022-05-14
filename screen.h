#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

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
    void show();
    void input();
    void moveRect(SDL_Rect* rectangle, int dx, int dy);
};