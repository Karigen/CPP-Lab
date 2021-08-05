#pragma once

#include"Point.h"
#include"Color.h"

class Triangle
{
private:
	Color colors;
	Point p1;
	Point p2;
	Point p3;
	Point centralPoint;
public:
	Triangle();
	void draw();

	Triangle(Color colors, Point p1, Point p2, Point p3, Point centralPoint);
	Color getColors();
	void setColors(Color colors);
	Point getP1();
	void setP1(Point p1);
	Point getP2();
	void setP2(Point p2);
	Point getP3();
	void setP3(Point p3);
	Point getCentralPoint();
	void setCentralPoint(Point centralPoint);
};