#include <iostream>
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"

using namespace std;

void square()
{
	float length;

	cout << "Enter the length of the sides of the square. \n";
	cin >> length;

	system("cls");
	Square firstSquare(length);
	
	cout << " Area is " << firstSquare.get_Area() << "\n\n";
	cout << " Perimeter is " << firstSquare.get_Perimeter() << "\n\n";
}

void rectangle()
{
	float length, width;

	cout << "Enter the length rectangle. \n";
	cin >> length;

	system("cls");
	cout << "Enter the width rectangle. \n";
	cin >> width;

	system("cls");
	Rectangle firstRectangle(length, width);
	
	cout << " Area is " << firstRectangle.get_Area() << "\n\n";
	cout << " Perimeter is " << firstRectangle.get_Perimeter() << "\n\n";
}

void triangle()
{
	float base, height;

	cout << "Enter the base of the triangle. \n";
	cin >> base;

	system("cls");
	cout << "Enter the height of the triangle. \n";
	cin >> height;

	system("cls");
	Triangle firstTriangle(base, height);

	cout << " Area is " << firstTriangle.get_Area() << "\n\n";
}

int selectShape()
{
	int selection;

	cout << "Select a shape! \n";
	cout << "  (1) Square \n";
	cout << "  (2) Rectangle \n";
	cout << "  (3) Triangle \n";
	cout << "  (9) Exit \n";
	cin >> selection;
	
	system("cls");
	
	return selection;
}

void main()
{
	int selection = selectShape();	

	switch(selection)
	{
		case 1 : square();
			break;
		case 2 : rectangle();
			break;
		case 3 : triangle();
			break;
		case 9 : return;
			break;
		default : selectShape();
	}
	main();
}
