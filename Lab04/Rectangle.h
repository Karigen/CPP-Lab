#pragma once

#include<string>
#include"Shape.h"
#include"Point.h"

class LJRectangle :public Shape
{
private:
	Point p1;
	Point p2;
	static int numberOfRectangl;
public:
	LJRectangle();
	LJRectangle(const unsigned int p1x, const unsigned int p1y, const unsigned int p2x, const unsigned int p2y, const color_t color, const bool isFilled);
	void draw()const override;
	std::string toString()const override;
	double getArea()const override;
	static int getNumberOfRectangl();
	static LJRectangle* read(std::ifstream& input);
	static void findError(std::ifstream& input);
	LJRectangle& operator=(const LJRectangle& rectangle);
	Point& operator[](const char index)override;
	void comparsion(const Shape* shapePtr)override;
	~LJRectangle()override;

	LJRectangle(const LJRectangle& rectangle);
	Point getP1()const;
	void setP1(const Point p1);
	Point getP2()const;
	void setP2(const Point p2);
};