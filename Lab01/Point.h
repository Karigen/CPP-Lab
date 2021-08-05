#pragma once

class Point
{
private:
	unsigned int pointX = 0;
	unsigned int pointY = 0;
public:
	Point() = default;
	unsigned int getPointX();
	void setPointX(unsigned int pointX);
	unsigned int getPointY();
	void setPointY(unsigned int pointY);

	Point(unsigned int pointX, unsigned int pointY);
};