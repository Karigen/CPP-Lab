#include<graphics.h>
#include"Triangle.h"

Triangle::Triangle() :colors(), p1(), p2(), p3(), centralPoint((p1.getPointX() + p2.getPointX() + p3.getPointX()) / 3, (p1.getPointY() + p2.getPointY() + p3.getPointY()) / 3) {}

void Triangle::draw()
{
	setcolor(colors.getColor());
	line(p1.getPointX(), p1.getPointY(), p2.getPointX(), p2.getPointY());
	line(p2.getPointX(), p2.getPointY(), p3.getPointX(), p3.getPointY());
	line(p3.getPointX(), p3.getPointY(), p1.getPointX(), p1.getPointY());
	colors.setFillColor();
	setfillcolor(colors.getFillColor());
	floodfillsurface(centralPoint.getPointX(), centralPoint.getPointY(), getpixel(centralPoint.getPointX(), centralPoint.getPointY()));
}



Triangle::Triangle(Color colors, Point p1, Point p2, Point p3, Point centralPoint)
{
	this->colors = colors;
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->centralPoint = centralPoint;
}

Color Triangle::getColors()
{
	return colors;
}

void Triangle::setColors(Color colors)
{
	this->colors = colors;
}

Point Triangle::getP1()
	{
		return p1;
	}

	void Triangle::setP1(Point p1)
	{
		this->p1 = p1;
	}

	Point Triangle::getP2()
	{
		return p2;
	}

	void Triangle::setP2(Point p2)
	{
		this->p2 = p2;
	}

	Point Triangle::getP3()
	{
		return p3;
	}

	void Triangle::setP3(Point p3)
	{
		this->p3 = p3;
	}

	Point Triangle::getCentralPoint()
	{
		return centralPoint;
	}

	void Triangle::setCentralPoint(Point centralPoint)
	{
		this->centralPoint = centralPoint;
	}