#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "player.h"
#include "math.h"

Player::Player() {
  x = 200;
  y = 200;
  angle = 0; // degrees
  length = 10;
}

// Draw the player character (line)
std::vector<std::pair<SDL_FPoint, SDL_Color>> Player::render(float x_off, float y_off, int paramAngle) {
  std::vector<std::pair<SDL_FPoint, SDL_Color>> pixels;
  std::pair<SDL_FPoint, SDL_Color> pixel;

  float radAngle;
  if (paramAngle != 0) {
    radAngle = degToRad(paramAngle);
  } else {
    radAngle = degToRad(Player::angle);
  }

  SDL_Color color;
  color.r = 255;
  color.g = 255;
  color.b = 255;
  color.a = SDL_ALPHA_OPAQUE;

  // Make the first pixel white
  pixel.first.x = (x + std::cos(radAngle)) - x_off;
  pixel.first.y = (y + std::sin(radAngle)) - y_off;
  pixel.second = color;
  pixels.push_back(pixel);

  // Switch back to red
  color.g = 0;
  color.b = 0;
  pixel.second = color;

  // Start from second pixel because the first is already made
  for (int i = 2; i < length; i++) {
    pixel.first.x = (x + std::cos(radAngle) * i) - x_off;
    pixel.first.y = (y + std::sin(radAngle) * i) - y_off;
    pixels.push_back(pixel);
  }
  return pixels;
}

// Moves the player on the grid
void Player::move(float dx, float dy) {
  x += dx;
  y += dy;
}

// Moves the player forward and backward according
// to the direction he's facing
// Use negative speed to move backward
void Player::walk(int speed) {
  float radAngle = degToRad(angle);
  x += std::cos(radAngle) * speed;
  y += std::sin(radAngle) * speed;
}

void Player::rotate(int dAngle) {
  int newAngle = Player::angle + dAngle;
  newAngle = fmod(newAngle, 360);
  if ( newAngle < 0) {
    newAngle += 360;
  }

  Player::angle = newAngle;
}