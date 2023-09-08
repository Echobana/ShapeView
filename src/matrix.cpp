#include "matrix.h"

RotateMatrix::RotateMatrix(point_t center, double angle)
	: _angle(angle)
	, _center(center)
{
	_matrix[0] = cos(angle);
	_matrix[1] = -sin(angle);
	_matrix[2] = sin(angle);
	_matrix[3] = cos(angle);
}

point_t operator*(RotateMatrix m, const point_t& point)
{
	point_t center = m._center;
	double angle = m._angle;
	unsigned x = center.x * (1 - sin(angle)) + point.x + center.y * cos(angle) - point.y;
	unsigned y = center.y * (1 - sin(angle)) + point.y + point.x * cos(angle) - center.x * cos(angle);
	return  { x, y };
}
