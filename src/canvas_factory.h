#pragma once
#include "canvas.h"

class ICanvasFactory
{
public:
    virtual ~ICanvasFactory() = default;
    virtual Canvas* create() = 0;
};

class ConsoleCanvasFactory : public ICanvasFactory
{
public:
    ConsoleCanvasFactory(unsigned long long length, unsigned long long height);
    Canvas* create() override;
private:
    unsigned long long _length;
    unsigned long long _height;
};


