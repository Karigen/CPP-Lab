#include<graphics.h>
#include"Point.h"
#include"Rectangle.h"

LJRectangle::LJRectangle() :colors(), p1(), p2(), centralPoint((p1.getPointX() + p2.getPointX()) / 2, (p1.getPointY() + p2.getPointY()) / 2) {}

void LJRectangle::draw()
{
	setcolor(colors.getColor());
	rectangle(p1.getPointX(), p1.getPointY(), p2.getPointX(), p2.getPointY());
	colors.setFillColor();
	setfillcolor(colors.getFillColor());
	floodfillsurface(centralPoint.getPointX(), centralPoint.getPointY(), getpixel(centralPoint.getPointX(), centralPoint.getPointY()));
}



LJRectangle::LJRectangle(Color colors, Point p1, Point p2, Point centralPoint)
{
	this->colors = colors;
	this->p1 = p1;
	this->p2 = p2;
	this->centralPoint = centralPoint;
}
Color LJRectangle::getColors()
{
	return colors;
}

void LJRectangle::setColors(Color colors)
{
	this->colors = colors;
}

Point LJRectangle::getP1()
{
	return p1;
}

void LJRectangle::setP1(Point p1)
{
	this->p1 = p1;
}

Point LJRectangle::getP2()
{
	return p2;
}

void LJRectangle::setP2(Point p2)
{
	this->p2 = p2;
}

Point LJRectangle::getCentralPoint()
{
	return centralPoint;
}

void LJRectangle::setCentralPoint(Point centralPoint)
{
	this->centralPoint = centralPoint;
}