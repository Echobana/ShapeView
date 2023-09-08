#include <iostream>
#include "canvas.h"
#include "shape.h"
#include "matrix.h"

int main()
{
	std::vector<point_t> quad_vertexes = { {1, 1, '*'}, {3, 1, '*'}, {3, 3, '*'}, {1, 3, '*'}};
	//std::vector<point_t> quad_vertexes = { {1, 1, '*'}, {4, 1, '*'}, {6, 3, '*'}, {6, 5, '*'}, {4, 7, '*'}, {3, 7, '*'}, {3, 3, '*' } };
	//std::vector<point_t> vertexes = { {6, 5, '*'}, {4, 7, '*'} };
	//std::vector<point_t> quad_vertexes = { {1, 1, '*'}, {3, 1, '*'}, {3, 3, '*'}, {1, 3, '*'}};
	Canvas* canvas = new ConsoleCanvas(10, 10);

	Shape* poly = new Polygon(quad_vertexes);
	poly->rotate({ 2, 2 }, (3.14 / 180) * 45);
	poly->draw(canvas);
	//canvas->line(vertexes[0], vertexes[1]);
	canvas->display();
	delete canvas;
}