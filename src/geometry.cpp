#include "geometry.h"

point_t operator-(const _point_t& reduced, const _point_t& subtracted)
{
	return { reduced.x - subtracted.x, reduced.y - subtracted.y };
}
