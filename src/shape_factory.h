#pragma once
#include "shape.h"
#include "yaml-cpp/yaml.h"

class IShapeFactory
{
public:
    virtual ~IShapeFactory() = default;
    explicit IShapeFactory(const YAML::Node& parameters);
    virtual Shape* create() = 0;

protected:
    YAML::Node init_parameters;
};

class PolygonFactory : public IShapeFactory
{
public:
    explicit PolygonFactory(const YAML::Node& parameters);
    Shape* create() override;
};

class CircleFactory : public IShapeFactory
{
public:
    explicit CircleFactory(const YAML::Node& parameters);
    Shape* create() override;
};
