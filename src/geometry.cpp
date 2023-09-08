#include "geometry.h"



point_t operator-(const point_t& reduced, const point_t& subtracted)
{
	point_t res = { reduced.x - subtracted.x, reduced.y - subtracted.y };
	return res;
}

point_t operator*(const point_t& point, unsigned k)
{
	point_t res = { k * point.x, k * point.y };
	return res;
}

point_t operator+(const point_t& term_1, const point_t& term_2)
{
	point_t res = { term_1.x + term_2.x, term_1.y + term_2.y };
	return res;
}


point_t operator/(const point_t& divisible, unsigned divisor)
{
	point_t res = { divisible.x / divisor, divisible.y / divisor };
	return res;
}



unsigned long long dot(vector_t v0, vector_t v1)
{
	return v0.x * v1.y - v0.y * v1.x;
}

vector_t::vector_t(point_t start, point_t finish)
	: x(finish.x - start.x)
	, y(finish.y - start.y) {}


