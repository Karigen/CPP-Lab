#pragma once

#include<graphics.h>

class Color
{
private:
	color_t color;
	bool isFilled;
	color_t fillColor;
public:
	Color();
	color_t getColor();
	color_t getFillColor();
	void setFillColor();

	Color(color_t color, bool isFilled, color_t fillColor);
	void setColor(color_t color);
	bool getIsFilled();
	void setIsFilled(bool isFilled);
};