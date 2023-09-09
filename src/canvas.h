#pragma once
#include <iostream>
#include <vector>

#include "geometry.h"


class Canvas 
{
public:
	Canvas() = default;
	virtual ~Canvas() = default;
	virtual void display() const = 0;

	virtual void line(point_t start, point_t finish) = 0;
protected:
	std::vector<point_t> _pixels;
};

class ConsoleCanvas : public Canvas
{
public:
	ConsoleCanvas() = default;
	ConsoleCanvas(unsigned long long length, unsigned long long height);
	void display() const override;
	void line(point_t start, point_t finish) override;
private:
	unsigned long long _length;
	unsigned long long _height;
};



