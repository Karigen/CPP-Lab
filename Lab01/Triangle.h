#pragma once

#include"Point.h"
#include"Color.h"

class Triangle
{
private:
	Point p1;
	Point p2;
	Point p3;
	Color colors;
public:
	Triangle() = default;
	void draw();
	Color getColors();

	/*Point getP1()
	{
		return p1;
	}

	void setP1(Point p1)
	{
		this->p1 = p1;
	}

	Point getP2()
	{
		return p2;
	}

	void setP1(Point p2)
	{
		this->p2 = p2;
	}

	Point getP3()
	{
		return p3;
	}

	void setP1(Point p3)
	{
		this->p3 = p3;
	}

	void setColors(Color colors)
	{
		this->colors = colors;
	}*/
};