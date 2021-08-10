#pragma once

#include<string>
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
	void reDraw()override;
	std::string toString()override;
	LJRectangle(unsigned int p1x, unsigned int p1y, unsigned int p2x, unsigned int p2y, color_t color, bool isFilled, color_t fillColor);
	static LJRectangle* read(std::ifstream& input);
	static void findError(std::ifstream& input);

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