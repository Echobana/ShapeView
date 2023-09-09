#include "shape.h"

Polygon::Polygon(std::vector<point_t> points)
	: _vertexes(points)
{
	find_center();
}


void Polygon::rotate(double angle)
{
	RotateMatrix m = RotateMatrix(_center, angle);
	
	for (auto& vertex : _vertexes)
		vertex = m * vertex;
}

void Polygon::draw(Canvas* canvas)
{
	for (auto it = _vertexes.begin(); it != _vertexes.end() - 1; ++it)
		canvas->line(it[0], it[1]);

	canvas->line(*_vertexes.rbegin(), *_vertexes.begin());
}

void Polygon::find_center()
{
	const point_t& start = _vertexes[0];
	unsigned total_area = 0;
	point_t total_area_x_center = { 0, 0 };
	for (auto it = _vertexes.begin() + 1; it != _vertexes.end() - 1; ++it)
	{
		const auto& second = it[0];
		const auto& third = it[1];

		vector_t v0(start, second);
		vector_t v1(start, third);

		unsigned area = dot(v0, v1);
		total_area += area;
		
		point_t triangle_center = find_triangle_center(start, second, third);
		auto x = triangle_center * area;
		total_area_x_center = total_area_x_center + triangle_center * area;
	}
	_center = total_area_x_center / total_area;
}

point_t Polygon::find_triangle_center(const point_t& A, const point_t& B, const point_t& C)
{
	return {(A.x + B.x + C.x) / 3, (A.y + B.y + C.y) / 3};
}


Circle::Circle(point_t center, unsigned int radius)
    : _radius(radius)
{
    _center = center;
    int x = 0;
    int y = _radius;
    int delta = 1 - 2 * _radius;
    int error = 0;

    while (y >= x)
    {
        _dots.push_back(point_t{_center.x + x, _center.y + y});
        _dots.push_back(point_t{_center.x + x, _center.y - y});
        _dots.push_back(point_t{_center.x - x, _center.y + y});
        _dots.push_back(point_t{_center.x - x, _center.y - y});
        _dots.push_back(point_t{_center.x + y, _center.y + x});
        _dots.push_back(point_t{_center.x + y, _center.y - x});
        _dots.push_back(point_t{_center.x - y, _center.y + x});
        _dots.push_back(point_t{_center.x - y, _center.y - x});

        error = 2 * (delta + y) - 1;
        if ((delta < 0) && (error <=0))
        {
            delta += 2 * ++x + 1;
            continue;
        }
        if ((delta > 0) && (error > 0))
        {
            delta -= 2 * --y + 1;
            continue;
        }
        delta += 2 * (++x - --y);
    }
}

void Circle::rotate(double angle) {}

void Circle::draw(Canvas *canvas) {
    for (auto it = _dots.begin(); it != _dots.end() - 1; ++it)
        canvas->line(it[0], it[1]);
}
