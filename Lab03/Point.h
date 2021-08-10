#pragma once

class Point
{
private:
	unsigned int pointX;
	unsigned int pointY;
	static int numberOfPoint;
public:
	Point();
	unsigned int getPointX();
	unsigned int getPointY();

	Point(unsigned int pointX, unsigned int pointY);
	Point(Point& point);
	void setPointX(unsigned int pointX);
	void setPointY(unsigned int pointY);
	static int getNumberOfPoint();
	~Point();
};