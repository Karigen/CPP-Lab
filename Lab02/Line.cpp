#include"Line.h"

Line::Line() :Shape(), p1(), p2()
{
	colors.setIsFilled(false);
	numberOfLine++;
}

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
	numberOfLine++;
}

Line::Line(Line& line) :Shape(line), p1(line.getP1()), p2(line.getP2())
{
	this->p1 = line.getP1();
	this->p2 = line.getP2();
	numberOfLine++;
}

Point& Line::getP1()
{
	return p1;
}

void Line::setP1(Point p1)
{
	this->p1 = p1;
}

int Line::getNumberOfLine()
{
	return numberOfLine;
}

Point& Line::getP2()
{
	return p2;
}

void Line::setP2(Point p2)
{
	this->p2 = p2;
}

Line::~Line()
{
	numberOfLine--;
}