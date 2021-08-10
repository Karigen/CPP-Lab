#pragma once

#include<string>
#include"Shape.h"
#include"Point.h"

class Line :public Shape
{
private:
	Point p1;
	Point p2;
	static int numberOfLine;
public:
	Line() = delete;
	Line(const bool isFilled);
	Line(const unsigned int p1x, const unsigned int p1y, const unsigned int p2x, const unsigned int p2y, const color_t color, const bool isFilled);
	void draw()const override;
	std::string toString()const override;
	double getArea()const override;
	static int getNumberOfLine();
	static Line* read(std::ifstream& input);
	static void findError(std::ifstream& input);
	Line& operator=(const Line& line);
	Point& operator[](const char index)override;
	void comparsion(const Shape* shapePtr)override;
	~Line()override;

	Line(const Line& line);
	Point getP1()const;
	void setP1(const Point p1);
	Point getP2()const;
	void setP2(const Point p2);
};