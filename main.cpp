#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "main.h"
#include "screen.h"
#include "shapes.h"
#include "player.h"


int main(int argc, char* args[]) {
  Screen screen;
  Player player;
  // player.draw(screen);
  //drawLine(screen, 0, 0, 300, 300);

  while (true) {
    screen.show(&player);
    screen.input(&player);
  }
  return 0;
}