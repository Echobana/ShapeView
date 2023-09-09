#include <iostream>
#include "canvas.h"
#include "shape.h"
#include "canvas_factory.h"
#include "shape_factory.h"
#include "yaml-cpp/yaml.h"
#include "unordered_map"

//#define ADD_FACTORY(NAME) {#NAME, NAMECanvas::create}
//typedef Canvas* (*FactoryType)(unsigned length, unsigned height);
//std::unordered_map<const char*, FactoryType> canvas_register;

int main()
{
    // Reading config file
    YAML::Node config = YAML::LoadFile("config.yaml");

    // Init canvas
	const char* canvas_type = config["CANVAS"]["type"].as<std::string>().data();

	ICanvasFactory* canvas_factory = nullptr;
	if (std::strcmp(canvas_type, "console") == 0)
		canvas_factory = new ConsoleCanvasFactory(10, 10);

    //Canvas* canvas = canvas_register[config["CANVAS"]["type"]].as<std::string>.data());
	Canvas * canvas = canvas_factory->create();

    // Init shape
    IShapeFactory* shapeFactory = nullptr;
    std::string shape_type = config["SHAPE"]["type"].as<std::string>();
    if (shape_type == "polygon")
        shapeFactory = new PolygonFactory(config["POLYGON_PARAMETERS"]);
    else if (shape_type == "circle")
        shapeFactory = new CircleFactory(config["CIRCLE_PARAMETERS"]);

    Shape* shape = shapeFactory->create();

    // Draw shape
    double yaml_angle = config["SHAPE"]["angle"].as<double>() ;
    shape->rotate(yaml_angle * 3.14 / 180);
    shape->draw(canvas);
	canvas->display();

//    delete shape;
//    delete shapeFactory;
//    delete canvas;
//    delete canvas_factory;
}