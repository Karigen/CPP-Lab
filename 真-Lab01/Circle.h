#pragma once

#include"Point.h"
#include"Color.h"

class Circle
{
private:
	Color colors;
	Point centerOfCircle;
	Point pointOfBoundary;
	unsigned int radius;
public:
	Circle();
	void draw();

	Circle(Color colors, Point centerOfCircle, Point pointOfBoundary, unsigned int radius);
	Color getColors();
	void setColor(Color colors);
	Point getCenterOfCircle();
	void setCenterOfCircle(Point centerOfCircle);
	Point getPointOfBoundary();
	void setPointOfBoundary(Point pointOfBoundary);
	unsigned int getRadius();
	void setRadius(unsigned int radius);
};