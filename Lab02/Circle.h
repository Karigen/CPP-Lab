#pragma once

#include"Shape.h"
#include"Point.h"

class Circle :public Shape
{
private:
	Point centerOfCircle;
	Point pointOfBoundary;
	unsigned int radius;
	static int numberOfCircle;
public:
	Circle();
	void draw()override;

	Circle(Color colors, Point centerOfCircle, Point pointOfBoundary, unsigned int radius);
	Circle(Circle& circle);
	Point& getCenterOfCircle();
	void setCenterOfCircle(Point centerOfCircle);
	Point& getPointOfBoundary();
	void setPointOfBoundary(Point pointOfBoundary);
	unsigned int getRadius();
	void setRadius(unsigned int radius);
	static int getNumberOfCircle();
	~Circle()override;
};