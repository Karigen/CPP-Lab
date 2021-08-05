#pragma once

#include<graphics.h>

class Color
{
private:
	color_t color;
	bool isFilled;
	color_t fillColor;
public:
	Color() = default;
	color_t getColor();
	color_t getFillColor();
	void setColor();
	void setFillColor();
	void fill();

	Color(color_t color, color_t fillColor);
};