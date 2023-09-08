#include <iostream>
#include "canvas.h"
#include "shape.h"
#include "matrix.h"

int main()
{
	std::vector<point_t> quad_vertexes = { {1, 1, '*'}, {3, 1, '*'}, {3, 3, '*'}, {1, 3, '*'}};

	const char* canvas_type;

	//CanvasFactory* canvas_factory;
	//if (std::strcmp(canvas_type, "console") == 0)
	//	canvas_factory = new ConsoleCanvas;

	//Canvas * canvas = canvas_factory->create();
	Canvas* canvas = new ConsoleCanvas(10, 10);

	Shape* poly = new Polygon(quad_vertexes);
	poly->rotate((3.14 / 180) * 45);
	poly->draw(canvas);
	canvas->display();
	delete canvas;
}