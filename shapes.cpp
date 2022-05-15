#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "shapes.h"
#include "screen.h"
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

std::vector<Line> translateLines(std::vector<Line> lines, float offX, float offY) {
  std::vector<Line> transLines;

  for (Line line : lines) {
    line.x1 = line.x1 + offX; 
    line.x2 = line.x2 + offX; 
    line.y1 = line.y1 + offY; 
    line.y2 = line.y2 + offY;
    transLines.push_back(line);
  }

  return transLines;
}

