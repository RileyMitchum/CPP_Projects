#include <iostream>
#include "Shape.h"
#include "Triangle.h"

using namespace std;

Triangle :: Triangle(float _base, float _height)
{
	base = _base;
	height = _height;
}

float Triangle :: get_Area()
{
	return 0.5*base*height;
}