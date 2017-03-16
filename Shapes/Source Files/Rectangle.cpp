#include <iostream>
#include "Shape.h"
#include "Rectangle.h"

using namespace std;

Rectangle :: Rectangle(float _width, float _length)
{
	width = _width;
	length = _length;
}

float Rectangle :: get_Area()
{
	return width*length;
}

float Rectangle :: get_Perimeter()
{
	return 2*(length+width);
}