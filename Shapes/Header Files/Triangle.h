#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Shape
{
	private:
		float base, height;
	public:
		Triangle(float _base, float _height);
		float get_Area();
};

#endif