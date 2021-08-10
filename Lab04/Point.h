#pragma once

class Point
{
private:
	int x;
	int y;
public:
	Point();
	Point(const unsigned int x, const unsigned int y);
	int getX()const;
	int getY()const;
	Point operator+(const Point point)const;
	bool operator==(const Point point)const;
	bool operator!=(const Point point)const;
	int& operator[](const char index);
	~Point() = default;

	Point(const Point& point);
	void setX(const unsigned int x);
	void setY(const unsigned int y);
};