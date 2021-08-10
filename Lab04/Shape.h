#pragma once

#include<string>
#include"Color.h"
#include"Point.h"

class Shape
{
private:
	static int numberOfShape;
protected:
	Color* ptrOfColors;
	char shapeID;
public:
	Shape();
	Shape(const bool isFilled);
	Shape(const color_t color, const bool isFilled);
	virtual void draw()const = 0;
	virtual std::string toString()const = 0;
	virtual double getArea()const = 0;
	static int getNumberOfShape();
	bool operator<(const Shape* shapePtr)const;
	bool operator>(const Shape* shapePtr)const;
	bool operator<=(const Shape* shapePtr)const;
	bool operator>=(const Shape* shapePtr)const;
	bool operator==(const Shape* shapePtr)const;
	bool operator!=(const Shape* shapePtr)const;
	virtual Point& operator[](const char index) = 0;
	virtual void comparsion(const Shape* shapePtr) = 0;
	void colorDetail();
	virtual ~Shape();

	Shape(const Shape& shape);
	Color* getPtrOfColors()const;
	void setPtrOfColors(Color* ptrOfColors);
	char getShapeID()const;
	void setShapeID(const char shapeID);
};