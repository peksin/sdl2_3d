#pragma once

class Line {
  public:
    float x1, x2, y1, y2, length;
    int angle;
    SDL_Color color;
    
    Line() = default;
    Line(float x1, float y1, float x2, float y2, SDL_Color color);

    void setLength();
    //void setAngle();
    //void rotate();
};

//void drawLine(Screen &screen, float x1, float y1, float x2, float y2);
void drawLine(SDL_Renderer* renderer, Line* line);
void drawLines(SDL_Renderer* renderer, std::vector<Line> lines);
std::vector<Line> translateLines(std::vector<Line> lines, float offX, float offY);