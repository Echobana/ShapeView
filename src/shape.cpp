#include "shape.h"



Polygon::Polygon(std::vector<point_t> points)
{
	_vertexes.resize(points.size());
	for (int i = 0; i < points.size(); ++i)
		_vertexes[i] = points[i];
}


void Polygon::rotate(point_t center, double angle)
{
	RotateMatrix m = RotateMatrix(center, angle);
	
	for (auto& vertex : _vertexes)
		vertex = m * vertex;
}

void Polygon::draw(Canvas* canvas)
{
	for (auto it = _vertexes.begin(); it != _vertexes.end() - 1; ++it)
		canvas->line(*it, it[1]);

	canvas->line(*_vertexes.rbegin(), _vertexes[0]);
}

void Polygon::find_center()
{
}

point_t Polygon::find_triangle_center(const point_t& A, const point_t& B, const point_t& C)
{
	return point_t();
}


