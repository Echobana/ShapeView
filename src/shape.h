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
	virtual void rotate(point_t center, double angle) = 0;
protected:
	virtual void find_center() = 0;
public:
	point_t _center;
};

class Polygon : public Shape
{
public:
	Polygon() = default;
	
	Polygon(std::vector<point_t> points);
	
	void rotate(point_t center, double angle) override;
	void draw(Canvas* canvas) override;
protected:
	void find_center() override;
private:
	std::vector<point_t> _vertexes;
	point_t find_triangle_center(const point_t& A, const point_t& B, const point_t& C);
};


