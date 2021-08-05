#include<math.h>
#include<graphics.h>
#include"Point.h"
#include"Circle.h"

Circle::Circle() :Shape(), centerOfCircle(), pointOfBoundary()
{
	radius = static_cast<unsigned int>(sqrt((pointOfBoundary.getPointX() - centerOfCircle.getPointX()) * (pointOfBoundary.getPointX() - centerOfCircle.getPointX()) + (pointOfBoundary.getPointY() - centerOfCircle.getPointY()) * (pointOfBoundary.getPointY() - centerOfCircle.getPointY())));
	numberOfCircle++;
}

void Circle::draw()
{
	setcolor(colors.getColor());
	circle(centerOfCircle.getPointX(), centerOfCircle.getPointY(), radius);
	colors.setFillColor();
	setfillcolor(colors.getFillColor());
	floodfillsurface(centerOfCircle.getPointX(), centerOfCircle.getPointY(), getpixel(centerOfCircle.getPointX(), centerOfCircle.getPointY()));
}



Circle::Circle(Color colors, Point centerOfCircle, Point pointOfBoundary, unsigned int radius)
{
	this->colors = colors;
	this->centerOfCircle = centerOfCircle;
	this->pointOfBoundary = pointOfBoundary;
	this->radius = radius;
	numberOfCircle++;
}

Circle::Circle(Circle& circle) :Shape(circle), centerOfCircle(circle.getCenterOfCircle()), pointOfBoundary(circle.getPointOfBoundary())
{
	this->radius = circle.getRadius();
	numberOfCircle++;
}

Point& Circle::getCenterOfCircle()
{
	return centerOfCircle;
}

void Circle::setCenterOfCircle(Point centerOfCircle)
{
	this->centerOfCircle = centerOfCircle;
}

Point& Circle::getPointOfBoundary()
{
	return pointOfBoundary;
}

void Circle::setPointOfBoundary(Point pointOfBoundary)
{
	this->pointOfBoundary = pointOfBoundary;
}

unsigned int Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(unsigned int radius)
{
	this->radius = radius;
}

int Circle::getNumberOfCircle()
{
	return numberOfCircle;
}

Circle::~Circle()
{
	numberOfCircle--;
}