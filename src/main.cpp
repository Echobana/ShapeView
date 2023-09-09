#include <iostream>
#include "canvas.h"
#include "shape.h"
#include "shape_factory.h"
#include "yaml-cpp/yaml.h"
#include "canvas_console.h"
#include "map"

// total mess with types
// TODO: create conversion space_point-to-pixel

#define ADD_FACTORY(NAME) {#NAME, Canvas##NAME::create}

typedef Canvas* (*FactoryType)(unsigned length, unsigned height);
std::map<std::string, FactoryType> canvas_register = {
        ADD_FACTORY(Console)
};

int main()
{

    // Reading config file
    YAML::Node config;
    try {
        config = YAML::LoadFile("config.yaml");
    } catch (const YAML::BadFile& ex)
    {
        std::cerr << "Parameters file is not found" << std::endl;
        std::cerr << ex.what();
        return -1;
    }


    // Init canvas
	std::string canvas_type = config["CANVAS"]["type"].as<std::string>();
    unsigned long long length = config["CANVAS"]["length"].as<int>();
    unsigned long long height = config["CANVAS"]["height"].as<int>();
    Canvas* canvas = canvas_register[canvas_type](length, height);

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
    if (yaml_angle != 0)
        shape->rotate(yaml_angle * 3.14 / 180);
    shape->draw(canvas);
	canvas->display();

    std::cout << "Shape area: " << shape->get_area() << std::endl;
//    delete shape;
//    delete shapeFactory;
//    delete canvas;
//    delete canvas_factory;
}