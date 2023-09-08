#pragma once
#include <array>
#include "math.h"
#include "geometry.h"

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