#pragma once
#include "canvas.h"

// Custom class to demonstrate
class CanvasConsole : public Canvas
{
public:
    CanvasConsole() = default;
    CanvasConsole(unsigned long long length, unsigned long long height);
    void display() const override;

    // Bresenham's algorithm
    void line(point_t start, point_t finish) override;

    void draw_pixel(point_t position) override;

    static Canvas* create(unsigned length, unsigned height);
private:
    std::vector<point_t> _pixels;
    unsigned long long _length;
    unsigned long long _height;
};
