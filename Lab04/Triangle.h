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
	static int numberOfTriangle;
public:
	Triangle();
	Triangle(const unsigned int p1x, const unsigned int p1y, const unsigned int p2x, const unsigned int p2y, const unsigned int p3x, const unsigned int p3y, const color_t color, const bool isFilled);
	void draw()const override;
	std::string toString()const override;
	double getArea()const;
	static Triangle* read(std::ifstream& input);
	static void findError(std::ifstream& input);
	static int getNumberOfTriangle();
	Triangle& operator=(const Triangle& triangle);
	Point& operator[](const char index)override;
	void comparsion(const Shape* shapePtr)override;
	~Triangle()override;

	Triangle(const Triangle& triangle);
	Point getP1()const;
	void setP1(const Point p1);
	Point getP2()const;
	void setP2(const Point p2);
	Point getP3()const;
	void setP3(const Point p3);
};