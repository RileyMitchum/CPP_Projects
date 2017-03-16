#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
	private:
		float area;
		float perimeter;

	public:
		Shape();
		virtual float get_Area() = 0;
		float get_Perimeter();
};

#endif
