#pragma once

#include <vector>
#include "math.h"
#include "canvas.h"
#include "geometry.h"
#include "matrix.h"

class Shape
{
public:
	Shape() = default;
	virtual ~Shape() = default;
	virtual void draw(Canvas* canvas) = 0;
	virtual void rotate(double angle) = 0;

public:
	point_t _center;
};

class Polygon : public Shape
{
public:
	Polygon() = default;
	
	Polygon(std::vector<point_t> points);
	
	void rotate(double angle) override;
	void draw(Canvas* canvas) override;
protected:
	void find_center();
private:
	std::vector<point_t> _vertexes;
	point_t find_triangle_center(const point_t& A, const point_t& B, const point_t& C);
};

class Circle : public Shape
{
public:
    Circle() = default;
    Circle(point_t center, unsigned radius);

    void rotate(double angle) override;
    void draw(Canvas* canvas) override;
private:
    unsigned _radius;
    std::vector<point_t> _dots;
};


