#include "canvas.h"
#include "geometry.h"

ConsoleCanvas::ConsoleCanvas(unsigned long long length, unsigned long long height)
	: _length(length)
	, _height(height) 
{
	_pixels.resize(_length * _height);
	for (int i = 0; i < _length * _height; ++i)
		_pixels[i] = point_t{ i % _length, i / length, ' ' };
}

void ConsoleCanvas::line(point_t start, point_t finish)
{
	if (start.x > finish.x)
		std::swap(start, finish);	

	if (start.x == finish.x)
	{
		if (start.y > finish.y)
			std::swap(start, finish);
		unsigned x = start.x;
		for (unsigned y = start.y; y <= finish.y; ++y)
		{
			_pixels[x + y * _length].color = '*';
		}
		return;
	}

	unsigned long long delta_x = finish.x - start.x;
	delta_x = delta_x > 0 ? delta_x : -delta_x;

	unsigned long long delta_y = finish.y - start.y;
	delta_y = delta_y > 0 ? delta_y : -delta_y;

	unsigned long long error = 0;
	unsigned long long deltaerr = delta_y + 1;

	unsigned long long y = start.y;
	unsigned long long dir_y = finish.y - start.y;

	dir_y = dir_y > 0 ? 1 : -1;

	if (start.y > finish.y)
		dir_y = -dir_y;

	for (unsigned long long x = start.x; x <= finish.x; ++x)
	{
		_pixels[x + y * _length].color = '*';
		error += deltaerr;
		if (error >= delta_x + 1)
		{
			y = y + dir_y;
			error -= delta_x + 1;
		}
	}
}

void ConsoleCanvas::display() const
{
	for (int i = 0; i < _pixels.size(); ++i)
	{
		std::cout << _pixels[i].color;
		if (_pixels[i].x == _length - 1)
			std::cout << std::endl;
	}
}

void ConsoleCanvas::draw_pixel(point_t position) {
    _pixels[position.x + position.y * _length].color = '*';
}



