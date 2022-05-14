#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "screen.h"
#include "player.h"


// A pixel with 3d coordinates 
struct vec3 {
  float x, y, z;
};



// Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int MVMT_SPEED = 1;

Screen::Screen() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
  SDL_RenderSetScale(renderer, 1, 1);

  fullscreen.x = 0;
  fullscreen.y = 0;
  fullscreen.w = SCREEN_WIDTH;
  fullscreen.h = SCREEN_HEIGHT;

  // Set top right viewport size
  topRightViewport.x = SCREEN_WIDTH / 2;
  topRightViewport.y = SCREEN_HEIGHT / 4;
  topRightViewport.w = SCREEN_WIDTH / 3;
  topRightViewport.h = SCREEN_HEIGHT / 3;

  // Set viewport border
  topRightBorder.x = topRightViewport.x - 5;
  topRightBorder.y = topRightViewport.y -5;
  topRightBorder.w = topRightViewport.w + 5;
  topRightBorder.h = topRightViewport.h + 5; 



  rekt.x = 210;
  rekt.y = 210;
  rekt.w = 50;
  rekt.h = 50;
}

void Screen::pixel(float x, float y) {
  points.emplace_back(x, y);
}

void Screen::show(Player* player) {
  // Clear out the screen with black
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  
  /*****************************
  * Draw to fullscreen viewport
  *****************************/

  SDL_RenderSetViewport(renderer, &fullscreen);
  
  // Draw viewport borders
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawRect(renderer, &topRightBorder);
  
  SDL_RenderDrawRect(renderer, &rekt);

  drawShape(player->render());
  
  /****************************
  * Draw to top right viewport
  ****************************/
  SDL_RenderSetViewport(renderer, &topRightViewport);
  SDL_RenderDrawRect(renderer, &rekt);
  drawShape(player->render());


  
  // Draw everything that's been rendered on the viewports
  SDL_RenderPresent(renderer);
}

void Screen::input(Player* player) {
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
        case SDLK_UP: // MOVE FORWARD
          player->walk(MVMT_SPEED);
          break;
        case SDLK_DOWN: // MOVE BACK
          player->walk(-MVMT_SPEED);
          break;
        case SDLK_LEFT: // ROTATE LEFT
          player->rotate(-10);
          break;
        case SDLK_RIGHT: // ROTATE RIGHT
          player->rotate(10);
          break;
        case SDLK_COMMA: // STRAFE LEFT
          player->move(-1, 0);
          break;
        case SDLK_PERIOD: // STRAFE RIGHT
          player->move(1, 0);
          break;
        default:
          break;
      }
    }
  }
}

// Draw a collection of pixels WITHOUT color data
void Screen::drawShape(std::vector<SDL_FPoint> pixels) {
  for (auto& pixel : pixels) {
    SDL_RenderDrawPointF(renderer, pixel.x, pixel.y);
  }
}

// Draw a collecttion of pixels with color data for each pixel
void Screen::drawShape(std::vector<std::pair<SDL_FPoint, SDL_Color>> pixels) {
  for (auto& pixel : pixels) {
    SDL_Color color = pixel.second;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPointF(renderer, pixel.first.x, pixel.first.y);
  }
}