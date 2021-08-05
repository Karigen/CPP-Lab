#include"Shape.h"

Shape::Shape() :ptrOfColors(new Color()), colors(*ptrOfColors)
{
	numberOfShape++;
}



Shape::Shape(Shape& shape) :ptrOfColors(new Color(shape.getColors())), colors(*ptrOfColors)
{
	numberOfShape++;
}

Color& Shape::getColors()
{
	return colors;
}

void Shape::setColors(Color colors)
{
	this->colors = colors;
}

int Shape::getNumberOfShape()
{
	return numberOfShape;
}

Shape::~Shape()
{
	delete ptrOfColors;
	numberOfShape--;
}