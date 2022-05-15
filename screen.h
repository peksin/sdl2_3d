#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "player.h"
#include "camera.h"
#include "shapes.h"

#pragma once


struct Pixel {
  float x; float y;
};

class Screen {
  public:
    SDL_Event e;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<SDL_FPoint> points;
    Camera camera;

    // Line testLine;
    std::vector<Line> lines;

    // Create a viewports
    SDL_Rect topRightViewport;
    SDL_Rect topRightBorder;

    

    Screen();

    //void pixel(float x, float y);
    void show(Player* player);
    void input(Player* player);
    void drawShape(std::vector<SDL_FPoint> pixels);
    void drawShape(std::vector<std::pair<SDL_FPoint, SDL_Color>> pixels);
};