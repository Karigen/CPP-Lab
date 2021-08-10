#include<filesystem>
#include<fstream>
#include<iostream>
#include<math.h>
#include<graphics.h>
#include"Point.h"
#include"Circle.h"

Circle::Circle() :Shape(), center()
{
	Point boundary{};
	radius = static_cast<unsigned int>(sqrt((boundary.getX() - center.getX()) * (boundary.getX() - center.getX()) + (boundary.getY() - center.getY()) * (boundary.getY() - center.getY())));
	shapeID = '2';
	numberOfCircle++;
}

void Circle::draw()const
{
	if (ptrOfColors->getIsFilled() == true)
	{
		setcolor(ptrOfColors->getColor());
		setfillcolor(ptrOfColors->getColor());
		fillellipse(center.getX(), center.getY(), radius, radius);
	}
	else
	{
		setcolor(ptrOfColors->getColor());
		circle(center.getX(), center.getY(), radius);
	}
}


std::string Circle::toString()const
{
	return "2\n" + std::to_string(center.getX()) + " " + std::to_string(center.getY()) + " " + std::to_string(radius) + "\n" + std::to_string(ptrOfColors->getColor()) + " " + std::to_string(ptrOfColors->getIsFilled()) + "\n";
}

double Circle::getArea()const
{
	return PI * radius * radius;
}

Circle::Circle(const unsigned int x, const unsigned int y, const unsigned int radius, const color_t color, const bool isFilled) :Shape(color, isFilled), center(x, y)
{
	this->radius = radius;
	shapeID = '2';
	numberOfCircle++;
}

Circle* Circle::read(std::ifstream& input)
{
	std::string sx, sy, sradius, scolor, sisFilled;
	input >> sx >> sy >> sradius >> scolor >> sisFilled;
	unsigned int x = stoi(sx), y = stoi(sy), radius = stoi(sradius);
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
	Circle* circlePtr = new Circle(x, y, radius, color, isFilled);
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
	if (count != 1)
		throw false;
	input.seekg(pt);
}

int Circle::getNumberOfCircle()
{
	return numberOfCircle;
}

Circle& Circle::operator=(const Circle& circle)
{
	*(this->ptrOfColors) = *(circle.ptrOfColors);
	this->center = circle.center;
	this->radius = circle.radius;
	return *this;
}

Point& Circle::operator[](const char index)
{
	if (index == '0')
		return center;
	else
		throw std::out_of_range("out of range");
}

void Circle::comparsion(const Shape* shapePtr)
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
		xyprintf(540, 21, "center(%d,%d)", (*this)['0']['0'], (*this)['0']['1']);
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
				Circle copy{ 0,0,0,0,0 };
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

Circle::~Circle()
{
	numberOfCircle--;
}



Circle::Circle(const Circle& circle):Shape(circle),center(circle.center)
{
	this->radius = circle.radius;
	numberOfCircle++;
}

Point Circle::getCenter()const
{
	return center;
}

void Circle::setCenter(const Point& center)
{
	this->center = center;
}

unsigned int Circle::getRadius()const
{
	return radius;
}

void Circle::setRadius(const unsigned int radius)
{
	this->radius = radius;
}