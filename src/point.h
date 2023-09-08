#pragma once

typedef struct _point_t
{
	unsigned long long x;
	unsigned long long y;
	char color;

	//friend point_t operator -(const point_t& reduced, const point_t& subtracted);
} point_t;

//typedef struct _point_vector_t
//{
//	point_t* data;
//	unsigned long long size;
//} point_vector_t;