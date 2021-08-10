#pragma once

#include<graphics.h>

class Color
{
private:
	color_t color;
	bool isFilled;
public:
	Color();
	Color(const bool isFilled);
	Color(const color_t color, const bool isFilled);
	bool getIsFilled()const;
	color_t getColor()const;
	bool operator==(const Color colors)const;
	bool operator!=(const Color colors)const;
	unsigned int operator[](const char index);
	Color& operator++();
	Color operator++(int dummy);
	Color& operator--();
	Color operator--(int dummy);
	~Color() = default;
	
	Color(const Color& color);
	void setColor(const color_t color);
	void setIsFilled(const bool isFilled);
};