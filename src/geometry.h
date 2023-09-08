#pragma once

struct point_t
{
	unsigned long long x;
	unsigned long long y;
	char color;

	friend point_t operator -(const point_t& reduced, const point_t& subtracted);
	friend point_t operator *(const point_t& point, unsigned k);
	friend point_t operator +(const point_t& term_1, const point_t& term_2);

};


struct vector_t
{
	unsigned long long x;
	unsigned long long y;

	vector_t(point_t start, point_t finish);
	friend unsigned long long dot(vector_t v0, vector_t v1);
};

//typedef struct _point_vector_t
//{
//	point_t* data;
//	unsigned long long size;
//} point_vector_t;