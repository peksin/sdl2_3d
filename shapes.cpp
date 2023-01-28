#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "shapes.h"
#include "player.h"
#include "math.h"

Line::Line(float x1, float y1, float x2, float y2, SDL_Color color) {
  Line::x1 = x1;
  Line::y1 = y1;
  Line::x2 = x2;
  Line::y2 = y2;
  Line::color = color;
  setLength();
}

void Line::setLength() {
  float lineLength = getDistance(x1, y1, x2, y2);
  length = lineLength;
}


// void drawLine(Screen &screen, float x1, float y1, float x2, float y2) {
//   float dx = x2 - x1;
//   float dy = y2 - y1;
//   float length = std::sqrt(dx * dx + dy * dy);
//   float angle = std::atan2(dy, dx);

//   for (int i = 0; i < length; i++) {
//     screen.pixel(x1 + std::cos(angle) * i, y1 + std::sin(angle) * i);
//   }
// }

void drawLine(SDL_Renderer* renderer, Line* line) {
  SDL_SetRenderDrawColor(renderer, line->color.r, line->color.g, line->color.b, line->color.a);
  SDL_RenderDrawLineF(renderer, line->x1, line->y1, line->x2, line->y2);
}

void drawLines(SDL_Renderer* renderer, std::vector<Line> lines) {
  for (Line line : lines) {
    drawLine(renderer, &line);
  }
}

void drawPixel(SDL_Renderer* renderer, Pixel pixel) {
  SDL_RenderDrawPointF(renderer, pixel.x, pixel.y);
}

std::vector<Line> translateLines(std::vector<Line> lines, float offX, float offY) {
  std::vector<Line> transLines;

  for (Line line : lines) {
    // Translate the line according to the offsets
    line.x1 = line.x1 + offX; 
    line.x2 = line.x2 + offX; 
    line.y1 = line.y1 + offY; 
    line.y2 = line.y2 + offY;

    transLines.push_back(line);
  }

  return transLines;
}

// Rotate the lines according to the angle player is facing
std::vector<Line> rotateLines(std::vector<Line> lines, Pixel anchor, float ogAngle) {
  std::vector<Line> rotatedLines;

  float angle = degToRad(ogAngle);
  //int angle = player->angle;
  
  // The ends of the line
  Pixel a, b;

  Line newLine;
  
 
  for (Line line : lines) {
    a.x = line.x1; a.y = line.y1;
    b.x = line.x2; b.y = line.y2;

    a = rotatePixel(anchor, a, angle);
    b = rotatePixel(anchor, b, angle);

    newLine.x1 = a.x; newLine.y1 = a.y;
    newLine.x2 = b.x; newLine.y2 = b.y;
    newLine.color = line.color;

    rotatedLines.push_back(newLine);
    //std::cerr << rotatedLines.size() << std::endl;

  }

  return rotatedLines;
}

// x1,y1 is the anchor point, x2,y2 rotates
// Takes the angle in degrees
Pixel rotatePixel(Pixel anchorPoint, Pixel mover, float angle) {
  float radAngle = degToRad(angle);
  Pixel rotated;
  Pixel origo;
  origo.x = 0;
  origo.y = 0;

  
  rotated.y = std::cos(radAngle) * mover.x + std::sin(radAngle) * mover.y;
  rotated.x = std::sin(radAngle) * mover.x - std::cos(radAngle) * mover.y;
  float distmover = getDistance(anchorPoint, mover);
  float distRotated = getDistance(anchorPoint, rotated);
  float distOrigo = getDistance(origo, rotated); 

  rotated.y = rotated.y - anchorPoint.y;
  rotated.x = anchorPoint.x - rotated.x;

  return rotated;
}

// // x1,y1 is the anchor point, x2,y2 rotates
// Pixel rotatePixel(Pixel anchorPoint, Pixel mover, float angle) {
//   Pixel rotated;
//   float c; // hypotenuse

//   c = getDistance(anchorPoint, mover);
//   rotated.x = anchorPoint.x - (std::sin(angle) * c);
//   rotated.y = mover.y - (std::cos(angle) * c);
//   return rotated;
// }

Pixel translatePixel(Pixel pixel, float offX, float offY) {
  Pixel translatedPixel;
  translatedPixel.x = pixel.x + offX;
  translatedPixel.y = pixel.y + offY;
  return translatedPixel;
}

