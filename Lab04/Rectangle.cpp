#include<filesystem>
#include<fstream>
#include<iostream>
#include<string>
#include<graphics.h>
#include"Point.h"
#include"Rectangle.h"

LJRectangle::LJRectangle() :Shape(), p1(), p2()
{
	shapeID = '1';
	numberOfRectangl++;
}

void LJRectangle::draw()const
{
	if (ptrOfColors->getIsFilled() == true)
	{
		setfillcolor(ptrOfColors->getColor());
		bar(p1.getX(), p1.getY(), p2.getX(), p2.getY());
	}
	else
	{
		setcolor(ptrOfColors->getColor());
		rectangle(p1.getX(), p1.getY(), p2.getX(), p2.getY());
	}
}

std::string LJRectangle::toString()const
{
	return "1\n" + std::to_string(p1.getX()) + " " + std::to_string(p1.getY()) + " " + std::to_string(p2.getX()) + " " + std::to_string(p2.getY()) + "\n" + std::to_string(ptrOfColors->getColor()) + " " + std::to_string(ptrOfColors->getIsFilled()) + "\n";
}

double LJRectangle::getArea()const
{
	return static_cast<double>(abs(this->p1.getX() - this->p2.getX()) * abs(this->p1.getY() - this->p2.getY()));
}

LJRectangle::LJRectangle(const unsigned int p1x, const unsigned int p1y, const unsigned int p2x, const unsigned int p2y, const color_t color, const bool isFilled) :Shape(color, isFilled), p1(p1x, p1y), p2(p2x, p2y)
{
	shapeID = '1';
	numberOfRectangl++;
}

LJRectangle* LJRectangle::read(std::ifstream& input)
{
	std::string sp1x, sp1y, sp2x, sp2y, scolor, sisFilled;
	input >> sp1x >> sp1y >> sp2x >> sp2y >> scolor >> sisFilled;
	unsigned int p1x = stoi(sp1x), p1y = stoi(sp1y), p2x = stoi(sp2x), p2y = stoi(sp2y);
	color_t color;
	bool isFilled = stoi(sisFilled);
	try
	{
		color = stoi(scolor);
	}
	catch (std::exception)
	{
		color = BLACK;
		isFilled = false;
	}
	LJRectangle* rectanglePtr = new LJRectangle(p1x, p1y, p2x, p2y, color, isFilled);
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
	if (count != 1)
		throw false;
	input.seekg(pt);
}

int LJRectangle::getNumberOfRectangl()
{
	return numberOfRectangl;
}

LJRectangle& LJRectangle::operator=(const LJRectangle& rectangle)
{
	*(this->ptrOfColors) = *(rectangle.ptrOfColors);
	this->p1 = rectangle.p1;
	this->p2 = rectangle.p2;
	return *this;
}

Point& LJRectangle::operator[](const char index)
{
	if (index == '0')
		return p1;
	else if (index == '1')
		return p2;
	else
		throw std::out_of_range("out of range");
}

void LJRectangle::comparsion(const Shape* shapePtr)
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);
	setfontbkcolor(WHITE);
	xyprintf(3, 3, "S2<S1:%d", *this < shapePtr);
	xyprintf(3, 21, "S2>S1:%d", *this > shapePtr);
	xyprintf(3, 39, "S2<=S1:%d", *this <= shapePtr);
	xyprintf(3, 57, "S2>=S1:%d", *this >= shapePtr);
	xyprintf(180, 3, "S2＝S1:%d", *this == shapePtr);
	xyprintf(180, 21, "S2≠S1:%d", *this != shapePtr);
	outtextxy(180, 39, "再建一个相同的");
	try
	{
		xyprintf(540, 21, "p1(%d,%d),p2(%d,%d)", (*this)['0']['0'], (*this)['0']['1'], (*this)['1']['0'], (*this)['1']['1']);
	}
	catch (const std::exception&)
	{
		setfillcolor(WHITE);
		bar(0, 0, 1200, 76);
		setcolor(BLACK);
		line(1, 1, 1198, 1);
		line(1198, 1, 1198, 75);
		line(1198, 75, 1, 75);
		line(1, 75, 1, 1);
		setfontbkcolor(WHITE);
		outtextxy(3, 3, "输入错误");
		outtextxy(3, 21, "按任意键继续");
		getch();
		setfillcolor(WHITE);
		bar(0, 0, 1200, 76);
	}
	
	outtextxy(540, 57, "退出");
	xyprintf(900, 3, "color2=color1:%d", *(this->ptrOfColors) == *(shapePtr->getPtrOfColors()));
	xyprintf(900, 21, "color2≠color1:%d", *(this->ptrOfColors) != *(shapePtr->getPtrOfColors()));

	int x = 0, y = 0;
	for (bool isClear = true; is_run; delay_fps(60))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
		{
			msg = getmouse();
		}
		mousepos(&x, &y);

		if (x <= 306 && x >= 180 && y <= 57 && y >= 39)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(180, 39, "再建一个相同的");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				LJRectangle copy{ 0,0,0,0,0,0 };
				copy = *this;
				setfontbkcolor(WHITE);
				setcolor(BLACK);
				outtextxy(180, 57, "再建成功");
			}
		}
		else if (x <= 576 && x >= 540 && y <= 75 && y >= 57)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(540, 57, "退出");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				break;
			}
		}
		else if (isClear == false)
		{
			setfontbkcolor(WHITE);
			setcolor(BLACK);
			outtextxy(180, 39, "再建一个相同的");
			outtextxy(540, 57, "退出");
			isClear = true;
		}
	}
}

LJRectangle::~LJRectangle()
{
	numberOfRectangl--;
}



LJRectangle::LJRectangle(const LJRectangle& rectangle):Shape(rectangle)
{
	this->p1 = rectangle.p1;
	this->p2 = rectangle.p2;
}

Point LJRectangle::getP1()const
{
	return p1;
}

void LJRectangle::setP1(const Point p1)
{
	this->p1 = p1;
}

Point LJRectangle::getP2()const
{
	return p2;
}

void LJRectangle::setP2(const Point p2)
{
	this->p2 = p2;
}