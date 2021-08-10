#include<filesystem>
#include<fstream>
#include<iostream>
#include<graphics.h>
#include"Triangle.h"

Triangle::Triangle() :Shape(), p1(), p2(), p3()
{
	shapeID = '3';
	numberOfTriangle++;
}

void Triangle::draw()const
{
	if (ptrOfColors->getIsFilled() == true)
	{
		setcolor(ptrOfColors->getColor());
		line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
		line(p2.getX(), p2.getY(), p3.getX(), p3.getY());
		line(p3.getX(), p3.getY(), p1.getX(), p1.getY());
		Point center((p1.getX() + p2.getX() + p3.getX()) / 3, (p1.getY() + p2.getY() + p3.getY()) / 3);
		setfillcolor(ptrOfColors->getColor());
		floodfillsurface(center.getX(), center.getY(), getpixel(center.getX(), center.getY()));
	}
	else
	{
		setcolor(ptrOfColors->getColor());
		line(p1.getX(), p1.getY(), p2.getX(), p2.getY());
		line(p2.getX(), p2.getY(), p3.getX(), p3.getY());
		line(p3.getX(), p3.getY(), p1.getX(), p1.getY());
	}
}

std::string Triangle::toString()const
{
	return "3\n" + std::to_string(p1.getX()) + " " + std::to_string(p1.getY()) + " " + std::to_string(p2.getX()) + " " + std::to_string(p2.getY()) + " " + std::to_string(p3.getX()) + " " + std::to_string(p3.getY()) + "\n" + std::to_string(ptrOfColors->getColor()) + " " + std::to_string(ptrOfColors->getIsFilled()) + "\n";
}

double Triangle::getArea()const
{
	double a = sqrt((this->p1.getX() - this->p2.getX()) * (this->p1.getX() - this->p2.getX()) + (this->p1.getY() - this->p2.getY()) * (this->p1.getY() - this->p2.getY()));
	double b = sqrt((this->p2.getX() - this->p3.getX()) * (this->p2.getX() - this->p3.getX()) + (this->p2.getY() - this->p3.getY()) * (this->p2.getY() - this->p3.getY()));
	double c = sqrt((this->p3.getX() - this->p1.getX()) * (this->p3.getX() - this->p1.getX()) + (this->p3.getY() - this->p1.getY()) * (this->p3.getY() - this->p1.getY()));
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));//利用海伦公式计算三角形面积
}

Triangle::Triangle(unsigned int p1x, unsigned int p1y, unsigned int p2x, unsigned int p2y, unsigned int p3x, unsigned int p3y, color_t color, bool isFilled) :Shape(color, isFilled), p1(p1x, p1y), p2(p2x, p2y), p3(p3x, p3y)
{
	shapeID = '3';
	numberOfTriangle++;
}

Triangle* Triangle::read(std::ifstream& input)
{
	std::string sp1x, sp1y, sp2x, sp2y, sp3x, sp3y, scolor, sisFilled;
	char c = '0';
	input >> sp1x >> sp1y >> sp2x >> sp2y >> sp3x >> sp3y >> scolor >> sisFilled;
	unsigned int p1x = stoi(sp1x), p1y = stoi(sp1y), p2x = stoi(sp2x), p2y = stoi(sp2y), p3x = stoi(sp3x), p3y = stoi(sp3y);
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
	Triangle* trianglePtr = new Triangle(p1x, p1y, p2x, p2y, p3x, p3y, color, isFilled);
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
	if (count != 1)
		throw false;
	input.seekg(pt);
}

int Triangle::getNumberOfTriangle()
{
	return numberOfTriangle;
}

Triangle& Triangle::operator=(const Triangle& triangle)
{
	*(this->ptrOfColors) = *(triangle.ptrOfColors);
	this->p1 = triangle.p1;
	this->p2 = triangle.p2;
	this->p3 = triangle.p3;
	return *this;
}

Point& Triangle::operator[](const char index)
{
	if (index == '0')
		return p1;
	else if (index == '1')
		return p2;
	else if (index == '2')
		return p3;
	else
		throw std::out_of_range("out of range");
}

void Triangle::comparsion(const Shape* shapePtr)
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
	//outtextxy(540, 3, "请输入想查询的点：");
	try
	{
		xyprintf(540, 21, "p1(%d,%d),p2(%d,%d),p3(%d,%d)", (*this)['0']['0'], (*this)['0']['1'], (*this)['1']['0'], (*this)['1']['1'], (*this)['2']['1'], (*this)['2']['1']);
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
				Triangle copy{ 0,0,0,0,0,0,0,0 };
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

Triangle::~Triangle()
{
	numberOfTriangle--;
}



Triangle::Triangle(const Triangle& triangle):Shape(triangle)
{
	
	this->p1 = triangle.p1;
	this->p2 = triangle.p2;
	this->p3 = triangle.p3;
}

Point Triangle::getP1()const
{
	return p1;
}

void Triangle::setP1(const Point p1)
{
	this->p1 = p1;
}

Point Triangle::getP2()const
{
	return p2;
}

void Triangle::setP2(const Point p2)
{
	this->p2 = p2;
}

Point Triangle::getP3()const
{
	return p3;
}

void Triangle::setP3(const Point p2)
{
	this->p3 = p3;
}