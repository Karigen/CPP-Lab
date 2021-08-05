#pragma once

#include"Shape.h"
#include"Point.h"

class Line :public Shape
{
private:
	Point p1;
	Point p2;
	static int numberOfLine;
public:
	Line();
	void draw()override;

	Line(Color colors, Point p1, Point p2);
	Line(Line& line);
	Point& getP1();
	void setP1(Point p1);
	Point& getP2();
	void setP2(Point p2);
	static int getNumberOfLine();
	~Line()override;
};