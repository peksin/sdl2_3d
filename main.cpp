#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "main.h"
#include "screen.h"
#include "shapes.h"

int main(int argc, char* args[]) {
  Screen screen;
  screen.pixel(200, 200);

  drawLine(screen, 0, 0, 300, 300);





  while (true) {
    screen.show();
    screen.input();
  }
  return 0;
}

//   while (!quit) {
//     SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
//     SDL_RenderFillRect(renderer, &rekt);
//     SDL_RenderDrawLine(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, 360);
//     while (SDL_PollEvent(&event) != 0) {





//       }
//       // User requests quit
//       if (event.type == SDL_QUIT) {
//         quit = true;
//       }
//     }
//   SDL_RenderPresent(renderer);
//   }

// }

// void moveRekt(SDL_Rect* rectangle, int x, int y) {


// }