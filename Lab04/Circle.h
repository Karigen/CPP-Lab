#pragma once

#include<string>
#include"Shape.h"
#include"Point.h"

class Circle :public Shape
{
private:
	Point center;
	unsigned int radius;
	static int numberOfCircle;
public:
	Circle();
	Circle(const unsigned int x, const unsigned int y, const unsigned int radius, const color_t color, const bool isFilled);
	void draw()const override;
	std::string toString()const override;
	double getArea()const override;
	static int getNumberOfCircle();
	static Circle* read(std::ifstream& input);
	static void findError(std::ifstream& input);
	Circle& operator=(const Circle& circle);
	Point& operator[](const char index)override;
	void comparsion(const Shape* shapePtr)override;
	~Circle()override;

	Circle(const Circle& circle);
	Point getCenter()const;
	void setCenter(const Point& center);
	unsigned int getRadius()const;
	void setRadius(const unsigned int radius);
};