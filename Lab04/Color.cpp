#include<graphics.h>
#include<stdexcept>
#include"Color.h"

Color::Color()
{
	setfillcolor(WHITE);
	bar(0, 0, 1200, 76);
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);
	setfontbkcolor(WHITE);
	outtextxy(3, 3, "请选择颜色:                                          当前颜色为：");
	outtextxy(3, 21, "                                                     请选择是否填充：  是 or   否");
	for (int i = 112; i < 473; i++)
	{
		setcolor(hsl2rgb(i, 1, 0.5));
		line(i, 4, i, 72);
	}
	setcolor(BLACK);
	rectangle(630, 24, 642, 36);
	setcolor(BLACK);
	rectangle(700, 24, 712, 36);

	int x = 0, y = 0;
	for (bool needClear = false, isChoose = false; is_run; delay_fps(60))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
		{
			msg = getmouse();
		}
		mousepos(&x, &y);
		if (x <= 473 && x >= 112 && y <= 72 && y >= 4 && isChoose == false)
		{
			setfillcolor(getpixel(x, y));
			bar(590, 6, 602, 18);
			needClear = true;
			if (msg.is_left() && msg.is_down())
			{
				color = getpixel(msg.x, msg.y);
				needClear = false;
				isChoose = true;
			}
		}
		else if (needClear == true)
		{
			setfillcolor(WHITE);
			bar(590, 6, 602, 18);
		}//填充
		else if (msg.is_left() && msg.is_down() && msg.x <= 642 && msg.x >= 630 && msg.y <= 36 && msg.y >= 24 && isChoose == true)
		{
			setfillcolor(BLACK);
			bar(633, 27, 639, 33);
			isFilled = true;
			break;
		}
		else if (msg.is_left() && msg.is_down() && msg.x <= 712 && msg.x >= 700 && msg.y <= 36 && msg.y >= 24 && isChoose == true)
		{
			setfillcolor(BLACK);
			bar(703, 27, 709, 33);
			isFilled = false;
			break;
		}
	}
}

Color::Color(const bool isFilled)
{
	setfillcolor(WHITE);
	bar(0, 0, 1200, 76);
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);
	setfontbkcolor(WHITE);
	outtextxy(3, 3, "请选择颜色:                                          当前颜色为：");
	for (int i = 112; i < 473; i++)
	{
		setcolor(hsl2rgb(i, 1, 0.5));
		line(i, 4, i, 72);
	}

	//颜色类型构造函数2.0
	for (bool needChoose = true; is_run; delay_fps(60))
	{
		//交互--痛苦鼠标
		mouse_msg msg = { 0 };
		while (mousemsg())
		{
			msg = getmouse();
		}//选择颜色
		if (msg.x <= 473 && msg.x >= 112 && msg.y <= 72 && msg.y >= 4 && needChoose == true)
		{
			setfillcolor(getpixel(msg.x, msg.y));
			bar(590, 6, 602, 18);
			if (msg.is_left() && msg.is_down())
			{
				color = getpixel(msg.x, msg.y);
				this->isFilled = isFilled;
				break;
			}
		}
	}
}

Color::Color(const color_t color, const bool isFilled)
{
	this->color = color;
	this->isFilled = isFilled;
}

color_t Color::getColor()const
{
	return color;
}

bool Color::getIsFilled()const
{
	return isFilled;
}

bool Color::operator==(const Color colors)const
{
	if (this->color == colors.color)
		return true;
	else
		return false;
}

bool Color::operator!=(const Color colors)const
{
	if (this->color == colors.color)
		return false;
	else
		return true;
}

unsigned int Color::operator[](const char index)
{
	if (index == '0')
		return EGEGET_R(this->color);
	else if (index == '1')
		return EGEGET_G(this->color);
	else if (index == '2')
		return EGEGET_B(this->color);
	else
		throw std::out_of_range("out of range");
}

Color& Color::operator++()
{
	unsigned int R = EGEGET_R(this->color), G = EGEGET_G(this->color), B = EGEGET_B(this->color);
	if (R < 255)
		R++;
	if (G < 255)
		G++;
	if (B < 255)
		B++;
	this->color = EGERGB(R, G, B);
	return *this;
}

Color Color::operator++(int dummy)
{
	Color temp = *this;
	unsigned int R = EGEGET_R(this->color), G = EGEGET_G(this->color), B = EGEGET_B(this->color);
	if (R < 255)
		R++;
	if (G < 255)
		G++;
	if (B < 255)
		B++;
	this->color = EGERGB(R, G, B);
	return temp;
}

Color& Color::operator--()
{
	unsigned int R = EGEGET_R(this->color), G = EGEGET_G(this->color), B = EGEGET_B(this->color);
	if (R > 0)
		R--;
	if (G > 0)
		G--;
	if (B > 0)
		B--;
	this->color = EGERGB(R, G, B);
	return *this;
}

Color Color::operator--(int dummy)
{
	Color temp = *this;
	unsigned int R = EGEGET_R(this->color), G = EGEGET_G(this->color), B = EGEGET_B(this->color);
	if (R > 0)
		R--;
	if (G > 0)
		G--;
	if (B > 0)
		B--;
	this->color = EGERGB(R, G, B);
	return temp;
}



Color::Color(const Color& color)
{
	this->color = color.color;
	this->isFilled = color.isFilled;
}

void Color::setColor(const color_t color)
{
	this->color = color;
}

void Color::setIsFilled(const bool isFilled)
{
	this->isFilled = isFilled;
}