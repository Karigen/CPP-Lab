#pragma once

#include"Point.h"
#include"Color.h"

class Line
{
private:
	Color colors;
	Point p1;
	Point p2;
public:
	Line();
	void draw();

	Line(Color colors, Point p1, Point p2);
	Color getColors();
	void setColors(Color colors);
	Point getP1();
	void setP1(Point p1);
	Point getP2();
	void setP2(Point p2);
};