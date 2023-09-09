#include "canvas_factory.h"

ConsoleCanvasFactory::ConsoleCanvasFactory(unsigned long long length, unsigned long long height)
    : _length(length)
    , _height(height){}

Canvas *ConsoleCanvasFactory::create()
{
    return new ConsoleCanvas(_length, _height);
}