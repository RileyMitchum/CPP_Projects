#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"

using namespace std;

Square :: Square(float side) : Rectangle (side, side)
{
}