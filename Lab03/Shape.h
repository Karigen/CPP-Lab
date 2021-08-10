#pragma once

#include<string>
#include"Color.h"

class Shape
{
private:
	static int numberOfShape;
protected:
	Color* ptrOfColors;
	Color colors;
	char shapeID;
public:
	Shape();
	virtual void draw() = 0;
	virtual void reDraw() = 0;
	virtual std::string toString() = 0;
	Shape(color_t color, bool isFilled, color_t fillColor);

	Shape(Shape& shape);
	Color& getColors();
	void setColors(Color colors);
	static int getNumberOfShape();
	virtual ~Shape();
};