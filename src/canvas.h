#pragma once
#include <iostream>
#include <vector>

#include "geometry/geometry.h"

// add adapter classes for graphic libs
class Canvas 
{
public:
	Canvas() = default;
	virtual ~Canvas() = default;
	virtual void display() const = 0;

	virtual void line(point_t start, point_t finish) = 0;
    virtual void draw_pixel(point_t position) = 0;
protected:
	std::vector<point_t> _pixels;

//    // Could be non rectangle shapes???
//    unsigned long long _length;
//    unsigned long long _height;
};

// Custom class to demonstrate
class ConsoleCanvas : public Canvas
{
public:
	ConsoleCanvas() = default;
	ConsoleCanvas(unsigned long long length, unsigned long long height);
	void display() const override;

    // Bresenham's algorithm
	void line(point_t start, point_t finish) override;

    void draw_pixel(point_t position) override;

    // could be usable to create object, change class naming
    static Canvas* create(unsigned length, unsigned height);
private:
	unsigned long long _length;
	unsigned long long _height;
};



