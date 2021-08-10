#include<filesystem>
#include<fstream>
#include<iostream>
#include<math.h>
#include<graphics.h>
#include"Point.h"
#include"Circle.h"

Circle::Circle() :Shape(), centerOfCircle(), pointOfBoundary()
{
	radius = static_cast<unsigned int>(sqrt((pointOfBoundary.getPointX() - centerOfCircle.getPointX()) * (pointOfBoundary.getPointX() - centerOfCircle.getPointX()) + (pointOfBoundary.getPointY() - centerOfCircle.getPointY()) * (pointOfBoundary.getPointY() - centerOfCircle.getPointY())));
	shapeID = '2';
	numberOfCircle++;
}

void Circle::draw()
{
	setcolor(colors.getColor());
	circle(centerOfCircle.getPointX(), centerOfCircle.getPointY(), radius);
	getColors().setFillColor();
	setfillcolor(colors.getFillColor());
	floodfillsurface(centerOfCircle.getPointX(), centerOfCircle.getPointY(), getpixel(centerOfCircle.getPointX(), centerOfCircle.getPointY()));
}

void Circle::reDraw()
{
	setcolor(colors.getColor());
	circle(centerOfCircle.getPointX(), centerOfCircle.getPointY(), radius);
	setfillcolor(colors.getFillColor());
	floodfillsurface(centerOfCircle.getPointX(), centerOfCircle.getPointY(), getpixel(centerOfCircle.getPointX(), centerOfCircle.getPointY()));
}

std::string Circle::toString()
{
	return "2\n" + std::to_string(centerOfCircle.getPointX()) + " " + std::to_string(centerOfCircle.getPointY()) + " " + std::to_string(getRadius()) + "\n" + std::to_string(this->getColors().getColor()) + " " + std::to_string(this->getColors().getIsFilled()) + " " + std::to_string(this->getColors().getFillColor()) + "\n";
}

Circle::Circle(unsigned int centerx, unsigned int centery, unsigned int radius, color_t color, bool isFilled, color_t fillColor) :Shape(color, isFilled, fillColor), centerOfCircle(centerx, centery), pointOfBoundary(0, 0)
{
	this->radius = radius;
	shapeID = '2';
	numberOfCircle++;
}

Circle* Circle::read(std::ifstream& input)
{
	std::string scenterx, scentery, sradius, scolor, sisFilled, sfillColor;
	input >> scenterx >> scentery >> sradius >> scolor >> sisFilled >> sfillColor;
	unsigned int centerx = stoi(scenterx), centery = stoi(scentery), radius = stoi(sradius);
	color_t color, fillColor;
	bool isFilled = stoi(sisFilled);
	try
	{
		color = stoi(scolor);
		fillColor = stoi(sfillColor);
		if (color != BLACK && color != BLUE && color != GREEN && color != CYAN && color != RED && color != MAGENTA && color != BROWN && color != LIGHTGRAY && color != DARKGRAY && color != LIGHTBLUE && color != LIGHTGREEN && color != LIGHTCYAN && color != LIGHTRED && color != LIGHTMAGENTA && color != YELLOW && color != WHITE)
			throw std::exception();
	}
	catch (std::exception)
	{
		color = BLACK;
		isFilled = true;
		fillColor = BLACK;
	}
	Circle* circlePtr = new Circle(centerx, centery, radius, color, isFilled, fillColor);
	return circlePtr;
}

void Circle::findError(std::ifstream& input)
{
	std::string s;
	int count = 0;
	int pt = input.tellg();
	input.get();
	std::getline(input, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			count++;
	}
	if (count != 2)
	{
		std::getline(input, s);
		throw false;
	}
	count = 0;
	std::getline(input, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			count++;
	}
	if (count != 2)
		throw false;
	input.seekg(pt);
}



Circle::Circle(Color colors, Point centerOfCircle, Point pointOfBoundary, unsigned int radius)
{
	this->colors = colors;
	this->centerOfCircle = centerOfCircle;
	this->pointOfBoundary = pointOfBoundary;
	this->radius = radius;
	shapeID = '2';
	numberOfCircle++;
}

Circle::Circle(Circle& circle) :Shape(circle), centerOfCircle(circle.getCenterOfCircle()), pointOfBoundary(circle.getPointOfBoundary())
{
	this->radius = circle.getRadius();
	shapeID = '2';
	numberOfCircle++;
}

Point& Circle::getCenterOfCircle()
{
	return centerOfCircle;
}

void Circle::setCenterOfCircle(Point centerOfCircle)
{
	this->centerOfCircle = centerOfCircle;
}

Point& Circle::getPointOfBoundary()
{
	return pointOfBoundary;
}

void Circle::setPointOfBoundary(Point pointOfBoundary)
{
	this->pointOfBoundary = pointOfBoundary;
}

unsigned int Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(unsigned int radius)
{
	this->radius = radius;
}

int Circle::getNumberOfCircle()
{
	return numberOfCircle;
}

Circle::~Circle()
{
	numberOfCircle--;
}