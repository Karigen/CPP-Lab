#include<filesystem>
#include<fstream>
#include<iostream>
#include<string>
#include<graphics.h>
#include"Point.h"
#include"Rectangle.h"

LJRectangle::LJRectangle() :Shape(), p1(), p2(), centralPoint((p1.getPointX() + p2.getPointX()) / 2, (p1.getPointY() + p2.getPointY()) / 2)
{
	shapeID = '1';
	numberOfRectangl++;
}

void LJRectangle::draw()
{
	setcolor(colors.getColor());
	rectangle(p1.getPointX(), p1.getPointY(), p2.getPointX(), p2.getPointY());
	colors.setFillColor();
	setfillcolor(colors.getFillColor());
	floodfillsurface(centralPoint.getPointX(), centralPoint.getPointY(), getpixel(centralPoint.getPointX(), centralPoint.getPointY()));
}

void LJRectangle::reDraw()
{
	setcolor(colors.getColor());
	rectangle(p1.getPointX(), p1.getPointY(), p2.getPointX(), p2.getPointY());
	setfillcolor(colors.getFillColor());
	floodfillsurface(centralPoint.getPointX(), centralPoint.getPointY(), getpixel(centralPoint.getPointX(), centralPoint.getPointY()));
}

std::string LJRectangle::toString()
{
	return "1\n" + std::to_string(p1.getPointX()) + " " + std::to_string(p1.getPointY()) + " " + std::to_string(p2.getPointX()) + " " + std::to_string(p2.getPointY()) + "\n" + std::to_string(this->getColors().getColor()) + " " + std::to_string(this->getColors().getIsFilled()) + " " + std::to_string(this->getColors().getFillColor()) + "\n";
}

LJRectangle::LJRectangle(unsigned int p1x, unsigned int p1y, unsigned int p2x, unsigned int p2y, color_t color, bool isFilled, color_t fillColor) :Shape(color, isFilled, fillColor), p1(p1x, p1y), p2(p2x, p2y), centralPoint((p1.getPointX() + p2.getPointX()) / 2, (p1.getPointY() + p2.getPointY()) / 2)
{
	shapeID = '1';
	numberOfRectangl++;
}

LJRectangle* LJRectangle::read(std::ifstream& input)
{
	std::string sp1x, sp1y, sp2x, sp2y, scolor, sisFilled, sfillColor;
	input >> sp1x >> sp1y >> sp2x >> sp2y >> scolor >> sisFilled >> sfillColor;
	unsigned int p1x = stoi(sp1x), p1y = stoi(sp1y), p2x = stoi(sp2x), p2y = stoi(sp2y);
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
	LJRectangle* rectanglePtr = new LJRectangle(p1x, p1y, p2x, p2y, color, isFilled, fillColor);
	return rectanglePtr;
}

void LJRectangle::findError(std::ifstream& input)
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
	if (count != 3)
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



LJRectangle::LJRectangle(Color colors, Point p1, Point p2, Point centralPoint)
{
	this->colors = colors;
	this->p1 = p1;
	this->p2 = p2;
	this->centralPoint = centralPoint;
	shapeID = '1';
	numberOfRectangl++;
}

LJRectangle::LJRectangle(LJRectangle& rectangle) :Shape(rectangle), p1(rectangle.getP1()), p2(rectangle.getP2()), centralPoint(rectangle.getCentralPoint())
{
	shapeID = '1';
	numberOfRectangl++;
}

Point& LJRectangle::getP1()
{
	return p1;
}

void LJRectangle::setP1(Point p1)
{
	this->p1 = p1;
}

Point& LJRectangle::getP2()
{
	return p2;
}

void LJRectangle::setP2(Point p2)
{
	this->p2 = p2;
}

Point& LJRectangle::getCentralPoint()
{
	return centralPoint;
}

void LJRectangle::setCentralPoint(Point centralPoint)
{
	this->centralPoint = centralPoint;
}

int LJRectangle::getNumberOfRectangl()
{
	return numberOfRectangl;
}

LJRectangle::~LJRectangle()
{
	numberOfRectangl--;
}