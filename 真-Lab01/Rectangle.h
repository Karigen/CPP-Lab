#pragma once

#include"Point.h"
#include"Color.h"

class LJRectangle
{
private:
	Color colors;
	Point p1;
	Point p2;
	Point centralPoint;
public:
	LJRectangle();
	void draw();

	LJRectangle(Color colors, Point p1, Point p2, Point centralPoint);
	Color getColors();
	void setColors(Color colors);
	Point getP1();
	void setP1(Point p1);
	Point getP2();
	void setP2(Point p2);
	Point getCentralPoint();
	void setCentralPoint(Point centralPoint);
};