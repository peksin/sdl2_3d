#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "player.h"
#include "math.h"

Player::Player() {
  x = 400;
  y = 200;
  angle = 0; // degrees
  length = 10;
}

// Draw the player character (line)
std::vector<SDL_FPoint> Player::render() {
  std::vector<SDL_FPoint> pixels;
  SDL_FPoint pixel;

  float radAngle = degToRad(angle);

  for (int i = 0; i < length; i++) {
    pixel.x = x + std::cos(radAngle) * i;
    pixel.y = y + std::sin(radAngle) * i;
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
  angle += dAngle;
}