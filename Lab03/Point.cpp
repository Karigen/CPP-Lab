#include<graphics.h>
#include"Point.h"

Point::Point()
{
	for (; is_run; delay_fps(60))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
		{
			msg = getmouse();
		}
		if (msg.is_left() && msg.is_down())
		{
			this->pointX = msg.x;
			this->pointY = msg.y;
			break;
		}
	}
	numberOfPoint++;
}

unsigned int Point::getPointX()
{
	return pointX;
}

unsigned int Point::getPointY()
{
	return pointY;
}



Point::Point(unsigned int pointX, unsigned int pointY)
{
	this->pointX = pointX;
	this->pointY = pointY;
	numberOfPoint++;
}

Point::Point(Point& point)
{
	this->pointX = point.getPointX();
	this->pointY = point.getPointY();
	numberOfPoint++;
}

void Point::setPointX(unsigned int pointX)
{
	this->pointX = pointX;
}

void Point::setPointY(unsigned int pointY)
{
	this->pointY = pointY;
}

int Point::getNumberOfPoint()
{
	return numberOfPoint;
}

Point::~Point()
{
	numberOfPoint--;
}