#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Shape
{
	private:
		float width, length;
	public:
		Rectangle(float _width, float _length);
		float get_Area();
		float get_Perimeter();
};

#endif
