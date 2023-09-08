#pragma once
#include "shape.h"

class LineAlgorithm
{
public:
	virtual ~LineAlgorithm() = default;
protected:
	LineAlgorithm() = default;
private:

};

class BresenhamLineAlgorithm : public LineAlgorithm
{
private:
	
};