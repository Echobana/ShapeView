#include <iostream>
#include "canvas.h"
#include "shape.h"
#include "matrix.h"
#include "canvas_factory.h"

int main()
{
	const char* canvas_type = "console";

	ICanvasFactory* canvas_factory = nullptr;
	if (std::strcmp(canvas_type, "console") == 0)
		canvas_factory = new ConsoleCanvasFactory(10, 10);

	Canvas * canvas = canvas_factory->create();

    std::vector<point_t> quad_vertexes = { {1, 1},
                                           {3, 1},
                                           {3, 3},
                                           {1, 3}};

	Shape* poly = new Polygon(quad_vertexes);
	poly->rotate((3.14 / 180) * 45);

    Shape* circle = new Circle({5, 5}, 4);

	circle->draw(canvas);
	canvas->display();
	delete canvas;
}