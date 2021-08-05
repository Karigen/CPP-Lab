#pragma once

#include"Point.h"
#include"Color.h"

class LJRectangle
{
private:
	Point p1;
	Point p2;
	Color colors;
public:
	LJRectangle() = default;
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

	void setColors(Color colors)
	{
		this->colors = colors;
	}*/
};