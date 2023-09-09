#include "shape_factory.h"
#include "geometry.h"

Shape *PolygonFactory::create() {
    std::vector<unsigned> xs = init_parameters["vertexes"]["x"].as<std::vector<unsigned >>();
    std::vector<unsigned> ys = init_parameters["vertexes"]["y"].as<std::vector<unsigned >>();
    std::vector<point_t> vertexes(xs.size());

    for (auto it = xs.begin(); it != xs.end(); ++it)
    {
        auto id = std::distance(xs.begin(), it);
        vertexes[id] = {xs[id], ys[id]};
    }
    return new Polygon(vertexes);
}


Shape *CircleFactory::create() {
    std::pair<unsigned, unsigned > center = init_parameters["center"].as<std::pair<unsigned, unsigned >>();
    return new Circle({center.first, center.second}, init_parameters["radius"].as<unsigned>());
}

IShapeFactory::IShapeFactory(const YAML::Node &parameters)
    : init_parameters(parameters) {}

CircleFactory::CircleFactory(const YAML::Node &parameters) : IShapeFactory(parameters)
{

}

PolygonFactory::PolygonFactory(const YAML::Node &parameters) : IShapeFactory(parameters) {

}
