#ifndef GEOMETRY_LIBRARY_H
#define GEOMETRY_LIBRARY_H

#include "math.h"
#include <array>
// temp lightweight for linear algebra


struct point_t
{
	unsigned long long x;
	unsigned long long y;
	char color;

	friend point_t operator -(const point_t& reduced, const point_t& subtracted);
	friend point_t operator *(const point_t& point, unsigned k);
	friend point_t operator +(const point_t& term_1, const point_t& term_2);
	friend point_t operator /(const point_t& divisible, unsigned divisor);
};


struct vector_t
{
	unsigned long long x;
	unsigned long long y;

	vector_t(point_t start, point_t finish);
	friend unsigned long long dot(vector_t v0, vector_t v1);
};


class RotateMatrix
{
public:
    RotateMatrix() = default;
    RotateMatrix(point_t center, double angle);
private:
    std::array<double, 4>	_matrix;
    point_t					_center;
    double					_angle;
    friend point_t operator * (RotateMatrix m, const point_t& point);
};

#endif //GEOMETRY_LIBRARY_H

