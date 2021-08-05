#include"Line.h"

Line::Line() :colors(), p1(), p2() {};

void Line::draw()
{
	setcolor(colors.getColor());
	line(p1.getPointX(), p1.getPointY(), p2.getPointX(), p2.getPointY());
}



Line::Line(Color colors, Point p1, Point p2)
{
	this->colors = colors;
	this->p1 = p1;
	this->p2 = p2;
}

Color Line::getColors()
{
	return colors;
}

void Line::setColors(Color colors)
{
	this->colors = colors;
}

Point Line::getP1()
{
	return p1;
}

void Line::setP1(Point p1)
{
	this->p1 = p1;
}

Point Line::getP2()
{
	return p2;
}

void Line::setP2(Point p2)
{
	this->p2 = p2;
}