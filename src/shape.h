#pragma once

#include <vector>
#include "math.h"
#include "canvas.h"
#include "geometry/geometry.h"

class Shape
{
public:
	Shape() = default;
	virtual ~Shape() = default;
	virtual void draw(Canvas* canvas) = 0;
	virtual void rotate(double angle);
    unsigned get_area() const;
protected:
	point_t _center;
    unsigned _area;
};

class Polygon : public Shape
{
public:
	Polygon() = default;
	
	explicit Polygon(std::vector<point_t> points);
	
	void rotate(double angle) override;
	void draw(Canvas* canvas) override;
protected:
	void find_center();
private:
	std::vector<point_t> _vertexes; // vector to point_t*
	point_t find_triangle_center(const point_t& A, const point_t& B, const point_t& C);
};

class Circle : public Shape
{
public:
    Circle() = default;
    Circle(point_t center, unsigned radius);

    void draw(Canvas* canvas) override;
private:
    unsigned _radius;
    std::vector<point_t> _dots;
};


