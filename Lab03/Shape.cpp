#include"Shape.h"

Shape::Shape() :ptrOfColors(new Color()), colors(*ptrOfColors)
{
	numberOfShape++;
}

Shape::Shape(color_t color, bool isFilled, color_t fillColor) : ptrOfColors(new Color(color, isFilled, fillColor)), colors(*ptrOfColors)
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