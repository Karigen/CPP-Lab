#include<filesystem>
#include<fstream>
#include<iostream>
#include<graphics.h>
#include"Line.h"

Line::Line() :Shape(), p1(), p2()
{
	colors.setIsFilled(false);
	shapeID = '4';
	numberOfLine++;
}

void Line::draw()
{
	setcolor(colors.getColor());
	line(p1.getPointX(), p1.getPointY(), p2.getPointX(), p2.getPointY());
}

void Line::reDraw()
{
	setcolor(colors.getColor());
	line(p1.getPointX(), p1.getPointY(), p2.getPointX(), p2.getPointY());
}

std::string Line::toString()
{
	return "4\n" + std::to_string(p1.getPointX()) + " " + std::to_string(p1.getPointY()) + " " + std::to_string(p2.getPointX()) + " " + std::to_string(p2.getPointY()) + "\n" + std::to_string(this->getColors().getColor()) + " " + std::to_string(this->getColors().getIsFilled()) + " " + std::to_string(this->getColors().getFillColor()) + "\n";
}

Line::Line(unsigned int p1x, unsigned int p1y, unsigned int p2x, unsigned int p2y, color_t color, bool isFilled, color_t fillColor) :Shape(color, isFilled, fillColor), p1(p1x, p1y), p2(p2x, p2y)
{
	shapeID = '4';
	numberOfLine++;
}

Line* Line::read(std::ifstream& input)
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
	Line* linePtr = new Line(p1x, p1y, p2x, p2y, color, isFilled, fillColor);
	return linePtr;
}

void Line::findError(std::ifstream& input)
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



Line::Line(Color colors, Point p1, Point p2)
{
	this->colors = colors;
	this->p1 = p1;
	this->p2 = p2;
	shapeID = '4';
	numberOfLine++;
}

Line::Line(Line& line) :Shape(line), p1(line.getP1()), p2(line.getP2())
{
	this->p1 = line.getP1();
	this->p2 = line.getP2();
	shapeID = '4';
	numberOfLine++;
}

Point& Line::getP1()
{
	return p1;
}

void Line::setP1(Point p1)
{
	this->p1 = p1;
}

int Line::getNumberOfLine()
{
	return numberOfLine;
}

Point& Line::getP2()
{
	return p2;
}

void Line::setP2(Point p2)
{
	this->p2 = p2;
}

Line::~Line()
{
	numberOfLine--;
}