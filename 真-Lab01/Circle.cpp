#include<math.h>
#include<graphics.h>
#include"Point.h"
#include"Circle.h"

Circle::Circle() :colors(), centerOfCircle(), pointOfBoundary()//Ϊɶ������������˳��ִ��ί�й���
{
	radius= sqrt((pointOfBoundary.getPointX() - centerOfCircle.getPointX()) * (pointOfBoundary.getPointX() - centerOfCircle.getPointX()) + (pointOfBoundary.getPointY() - centerOfCircle.getPointY()) * (pointOfBoundary.getPointY() - centerOfCircle.getPointY()));
}

void Circle::draw()
{
	setcolor(colors.getColor());
	circle(centerOfCircle.getPointX(), centerOfCircle.getPointY(), radius);
	colors.setFillColor();
	setfillcolor(colors.getFillColor());
	floodfillsurface(centerOfCircle.getPointX(), centerOfCircle.getPointY(), getpixel(centerOfCircle.getPointX(), centerOfCircle.getPointY()));
}

//Color& Circle::getColors()
//{
//	return colors;//���ڵ��÷��ص���������ֵ
//}



Circle::Circle(Color colors, Point centerOfCircle, Point pointOfBoundary, unsigned int radius)
{
	this->colors = colors;
	this->centerOfCircle = centerOfCircle;
	this->pointOfBoundary = pointOfBoundary;
	this->radius = radius;
}

Color Circle::getColors()
{
	return colors;
}

void Circle::setColor(Color colors)
{
	this->colors = colors;
}

Point Circle::getCenterOfCircle()
{
	return centerOfCircle;
}

void Circle::setCenterOfCircle(Point centerOfCircle)
{
	this->centerOfCircle = centerOfCircle;
}

Point Circle::getPointOfBoundary()
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