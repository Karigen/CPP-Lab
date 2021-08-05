#pragma once

#include"Point.h"
#include"Color.h"

class Circle
{
private:
	Point centerOfCircle;
	unsigned int radius;
	Color colors;
public:
	Circle() = default;
	void draw();
	Color getColors();

	Point getCenterOfCircle()
	{
		return centerOfCircle;
	}

	void setCenterOfCircle(Point centerOfCircle)
	{
		this->centerOfCircle = centerOfCircle;
	}

	unsigned int getRadius()
	{
		return radius;
	}

	void setRadius(unsigned int radius)
	{
		this->radius = radius;
	}

	void setColor(Color colors)
	{
		this->colors = colors;
	}
};