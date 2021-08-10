#pragma once

#include<string>
#include"Shape.h"
#include"Point.h"

class Triangle :public Shape
{
private:
	Point p1;
	Point p2;
	Point p3;
	Point centralPoint;
	static int numberOfTriangle;
public:
	Triangle();
	void draw()override;
	void reDraw()override;
	std::string toString()override;
	Triangle(unsigned int p1x, unsigned int p1y, unsigned int p2x, unsigned int p2y, unsigned int p3x, unsigned int p3y, color_t color, bool isFilled, color_t fillColor);
	static Triangle* read(std::ifstream& input);
	static void findError(std::ifstream& input);

	Triangle(Color colors, Point p1, Point p2, Point p3, Point centralPoint);
	Triangle(Triangle& triangle);
	Point& getP1();
	void setP1(Point p1);
	Point& getP2();
	void setP2(Point p2);
	Point& getP3();
	void setP3(Point p3);
	Point& getCentralPoint();
	void setCentralPoint(Point centralPoint);
	static int getNumberOfTriangle();
	~Triangle()override;
};