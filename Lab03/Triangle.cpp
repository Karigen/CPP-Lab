#include<filesystem>
#include<fstream>
#include<iostream>
#include<graphics.h>
#include"Triangle.h"

Triangle::Triangle() :Shape(), p1(), p2(), p3(), centralPoint((p1.getPointX() + p2.getPointX() + p3.getPointX()) / 3, (p1.getPointY() + p2.getPointY() + p3.getPointY()) / 3)
{
	shapeID = '3';
	numberOfTriangle++;
}

void Triangle::draw()
{
	setcolor(colors.getColor());
	line(p1.getPointX(), p1.getPointY(), p2.getPointX(), p2.getPointY());
	line(p2.getPointX(), p2.getPointY(), p3.getPointX(), p3.getPointY());
	line(p3.getPointX(), p3.getPointY(), p1.getPointX(), p1.getPointY());
	colors.setFillColor();
	setfillcolor(colors.getFillColor());
	floodfillsurface(centralPoint.getPointX(), centralPoint.getPointY(), getpixel(centralPoint.getPointX(), centralPoint.getPointY()));
}

void Triangle::reDraw()
{
	setcolor(colors.getColor());
	line(p1.getPointX(), p1.getPointY(), p2.getPointX(), p2.getPointY());
	line(p2.getPointX(), p2.getPointY(), p3.getPointX(), p3.getPointY());
	line(p3.getPointX(), p3.getPointY(), p1.getPointX(), p1.getPointY());
	setfillcolor(colors.getFillColor());
	floodfillsurface(centralPoint.getPointX(), centralPoint.getPointY(), getpixel(centralPoint.getPointX(), centralPoint.getPointY()));
}

std::string Triangle::toString()
{
	return "3\n" + std::to_string(p1.getPointX()) + " " + std::to_string(p1.getPointY()) + " " + std::to_string(p2.getPointX()) + " " + std::to_string(p2.getPointY()) + " " + std::to_string(p3.getPointX()) + " " + std::to_string(p3.getPointY()) + "\n" + std::to_string(this->getColors().getColor()) + " " + std::to_string(this->getColors().getIsFilled()) + " " + std::to_string(this->getColors().getFillColor()) + "\n";
}

Triangle::Triangle(unsigned int p1x, unsigned int p1y, unsigned int p2x, unsigned int p2y, unsigned int p3x, unsigned int p3y, color_t color, bool isFilled, color_t fillColor) :Shape(color, isFilled, fillColor), p1(p1x, p1y), p2(p2x, p2y), p3(p3x, p3y), centralPoint((p1.getPointX() + p2.getPointX() + p3.getPointX()) / 3, (p1.getPointY() + p2.getPointY() + p3.getPointY()) / 3)
{
	shapeID = '3';
	numberOfTriangle++;
}

Triangle* Triangle::read(std::ifstream& input)
{
	std::string sp1x, sp1y, sp2x, sp2y, sp3x, sp3y, scolor, sisFilled, sfillColor;
	char c = '0';
	input >> sp1x >> sp1y >> sp2x >> sp2y >> sp3x >> sp3y >> scolor >> sisFilled >> sfillColor;
	unsigned int p1x = stoi(sp1x), p1y = stoi(sp1y), p2x = stoi(sp2x), p2y = stoi(sp2y), p3x = stoi(sp3x), p3y = stoi(sp3y);
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
	Triangle* trianglePtr = new Triangle(p1x, p1y, p2x, p2y, p3x, p3y, color, isFilled, fillColor);
	return trianglePtr;
}

void Triangle::findError(std::ifstream& input)
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
	if (count != 5)
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



Triangle::Triangle(Color colors, Point p1, Point p2, Point p3, Point centralPoint)
{
	this->colors = colors;
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->centralPoint = centralPoint;
	shapeID = '3';
	numberOfTriangle++;
}

Triangle::Triangle(Triangle& triangle) :Shape(triangle), p1(triangle.getP1()), p2(triangle.getP2()), p3(triangle.getP3()), centralPoint(triangle.getCentralPoint())
{
	shapeID = '3';
	numberOfTriangle++;
}

Point& Triangle::getP1()
{
	return p1;
}

void Triangle::setP1(Point p1)
{
	this->p1 = p1;
}

Point& Triangle::getP2()
{
	return p2;
}

void Triangle::setP2(Point p2)
{
	this->p2 = p2;
}

Point& Triangle::getP3()
{
	return p3;
}

void Triangle::setP3(Point p3)
{
	this->p3 = p3;
}

Point& Triangle::getCentralPoint()
{
	return centralPoint;
}

void Triangle::setCentralPoint(Point centralPoint)
{
	this->centralPoint = centralPoint;
}

int Triangle::getNumberOfTriangle()
{
	return numberOfTriangle;
}

Triangle::~Triangle()
{
	numberOfTriangle--;
}