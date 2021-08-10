#pragma once

#include<graphics.h>

class Color
{
private:
	color_t color;
	bool isFilled;
	color_t fillColor = WHITE;
public:
	Color();
	color_t getColor();
	color_t getFillColor();
	void setFillColor();
	void setIsFilled(bool isFilled);

	Color(color_t color, bool isFilled, color_t fillColor);
	Color(Color& color);
	void setColor(color_t color);
	bool getIsFilled();
	~Color();
};