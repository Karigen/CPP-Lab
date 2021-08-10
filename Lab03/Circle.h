#pragma once

#include<string>
#include"Shape.h"
#include"Point.h"

class Circle :public Shape
{
private:
	Point centerOfCircle;
	Point pointOfBoundary;
	unsigned int radius;
	static int numberOfCircle;
public:
	Circle();
	void draw()override;
	void reDraw()override;
	std::string toString()override;
	Circle(unsigned int centerx, unsigned int centery, unsigned int radius, color_t color, bool isFilled, color_t fillColor);
	static Circle* read(std::ifstream& input);
	static void findError(std::ifstream& input);

	Circle(Color colors, Point centerOfCircle, Point pointOfBoundary, unsigned int radius);
	Circle(Circle& circle);
	Point& getCenterOfCircle();
	void setCenterOfCircle(Point centerOfCircle);
	Point& getPointOfBoundary();
	void setPointOfBoundary(Point pointOfBoundary);
	unsigned int getRadius();
	void setRadius(unsigned int radius);
	static int getNumberOfCircle();
	~Circle()override;
};