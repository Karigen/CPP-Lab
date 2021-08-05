#include"Point.h"

unsigned int Point::getPointX()
{
	return pointX;
}

void Point::setPointX(unsigned int pointX)
{
	this->pointX = pointX;
}

unsigned int Point::getPointY()
{
	return pointY;
}

void Point::setPointY(unsigned int pointY)
{
	this->pointY = pointY;
}

Point::Point(unsigned int pointX, unsigned int pointY)
{
	this->pointX = pointX;
	this->pointY = pointY;
}