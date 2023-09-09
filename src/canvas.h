#pragma once
#include <iostream>
#include <vector>
#include "geometry/geometry.h"

// add adapter classes for graphic libs
// should be Singletone???
class Canvas 
{
public:
	Canvas() = default;
	virtual ~Canvas() = default;
	virtual void display() const = 0;

	virtual void line(point_t start, point_t finish) = 0;
    virtual void draw_pixel(point_t position) = 0;


//    // Could be non rectangle shapes???
//    unsigned long long _length;
//    unsigned long long _height;
};




