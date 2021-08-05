#pragma once

class Point
{
private:
	unsigned int pointX = 0;
	unsigned int pointY = 0;
public:
	Point();
	unsigned int getPointX();
	unsigned int getPointY();

	Point(unsigned int pointX, unsigned int pointY);
	void setPointX(unsigned int pointX);
	void setPointY(unsigned int pointY);
};