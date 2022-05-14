#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "screen.h"

// A pixel with 3d coordinates 
struct vec3 {
  float x, y, z;
};


// Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

Screen::Screen() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
  SDL_RenderSetScale(renderer, 1, 1);

  rekt.x = 210;
  rekt.y = 210;
  rekt.w = 50;
  rekt.h = 50;
}

void Screen::pixel(float x, float y) {
  points.emplace_back(x, y);
}

void Screen::show() {
  // Clear out the screen with black
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  
  // Draw with red
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  for (auto& point : points) {
    SDL_RenderDrawPointF(renderer, point.x, point.y);
  }

  SDL_RenderDrawLineF(renderer, 150, 150, 250, 290);


  SDL_RenderDrawRect(renderer, &rekt);
  
  SDL_RenderPresent(renderer);
}

void Screen::input() {
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      SDL_DestroyRenderer(renderer);
      SDL_DestroyWindow(window);
      SDL_Quit();
      exit(0);
    }

    if (e.type == SDL_KEYDOWN) {
      std::cerr << "Button pressed: ";
      std::cerr << SDL_GetKeyName(e.key.keysym.sym) << std::endl;
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          moveRect(&rekt, 0, 10);
          break;
        default:
          break;
      }
    }
  }
}

void Screen::moveRect(SDL_Rect* rectangle, int dx, int dy) {
  std::cerr << rectangle->x << " " << rectangle->y << std::endl;
  rectangle->x += dx;
  rectangle->y += dy; 

  std::cerr << rectangle->x << " " << rectangle->y << std::endl;  
} 