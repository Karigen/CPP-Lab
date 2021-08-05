#pragma once

#include"Shape.h"
#include"Point.h"

class LJRectangle :public Shape
{
private:
	Point p1;
	Point p2;
	Point centralPoint;
	static int numberOfRectangl;
public:
	LJRectangle();
	void draw()override;

	LJRectangle(Color colors, Point p1, Point p2, Point centralPoint);
	LJRectangle(LJRectangle& rectangle);
	Point& getP1();
	void setP1(Point p1);
	Point& getP2();
	void setP2(Point p2);
	Point& getCentralPoint();
	void setCentralPoint(Point centralPoint);
	static int getNumberOfRectangl();
	~LJRectangle()override;
};