#include<graphics.h>
#include<stdexcept>
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
			this->x = msg.x;
			this->y = msg.y;
			break;
		}
	}
}

Point::Point(const unsigned int x, const unsigned int y)
{
	this->x = x;
	this->y = y;
}

int Point::getX()const
{
	return x;
}

int Point::getY()const
{
	return y;
}

Point Point::operator+(const Point point)const
{
	return Point((this->x + point.x)/2, (this->y + point.y)/2);
}

bool Point::operator==(const Point point)const
{
	if (this->x == point.x && this->y == point.y)
		return true;
	else
		return false;
}

bool Point::operator!=(const Point point)const
{
	if (this->x == point.x && this->y == point.y)
		return false;
	else
		return true;
}

int& Point::operator[](const char index)
{
	if (index == '0')
		return x;
	else if (index == '1')
		return y;
	else
		throw std::out_of_range("out of range");
}



Point::Point(const Point& point)
{
	this->x = point.x;
	this->y = point.y;
}

void Point::setX(const unsigned int x)
{
	this->x = x;
}

void Point::setY(const unsigned int y)
{
	this->y = y;
}