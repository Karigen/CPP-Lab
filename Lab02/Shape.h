#pragma once

#include"Color.h"

class Shape
{
private:
	static int numberOfShape;
protected:
	Color* ptrOfColors;
	Color colors;
public:
	Shape();
	virtual void draw() = 0;

	Shape(Shape& shape);
	Color& getColors();
	void setColors(Color colors);
	static int getNumberOfShape();
	virtual ~Shape();
};