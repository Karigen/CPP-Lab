#include<graphics.h>
#include"Color.h"

Color::Color()
{
	setfillcolor(WHITE);
	bar(0, 0, 1200, 76);

	char a;
	do
	{
		setfillcolor(WHITE);
		bar(0, 0, 1200, 76);

		setcolor(BLACK);
		line(1, 1, 1198, 1);
		line(1198, 1, 1198, 75);
		line(1198, 75, 1, 75);
		line(1, 75, 1, 1);

		outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请选择边界颜色：");
		outtextxy(3, 21, "1.输入1黑色 4.输入4青色 7.输入7棕色 A.输入A浅蓝 D.输入D浅红   G.输入G白色");
		outtextxy(3, 39, "2.输入2蓝色 5.输入5红色 8.输入8浅灰 B.输入B浅绿 E.输入E浅品红");
		outtextxy(3, 57, "3.输入3绿色 6.输入6品红 9.输入9暗灰 C.输入C浅青 F.输入F黄色");

		a = getch();

		switch (a)
		{
		case '1':this->color = BLACK; break;
		case '2':this->color = BLUE; break;
		case '3':this->color = GREEN; break;
		case '4':this->color = CYAN; break;
		case '5':this->color = RED; break;
		case '6':this->color = MAGENTA; break;
		case '7':this->color = BROWN; break;
		case '8':this->color = LIGHTGRAY; break;
		case '9':this->color = DARKGRAY; break;
		case 'A':this->color = LIGHTBLUE; break;
		case 'B':this->color = LIGHTGREEN; break;
		case 'C':this->color = LIGHTCYAN; break;
		case 'D':this->color = LIGHTRED; break;
		case 'E':this->color = LIGHTMAGENTA; break;
		case 'F':this->color = YELLOW; break;
		case 'G':this->color = WHITE; break;
		default:
			setfillcolor(WHITE);
			bar(0, 0, 1200, 76);

			setcolor(BLACK);
			line(1, 1, 1198, 1);
			line(1198, 1, 1198, 75);
			line(1198, 75, 1, 75);
			line(1, 75, 1, 1);

			outtextxy(3, 3, "输入错误");
			outtextxy(3, 21, "按任意键继续");
			getch();
		}
	} while (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9' && a != 'A' && a != 'B' && a != 'C' && a != 'D' && a != 'E' && a != 'F' && a != 'G');
}

color_t Color::getColor()
{
	return color;
}

color_t Color::getFillColor()
{
	return fillColor;
}

void Color::setFillColor()
{
	setfillcolor(WHITE);
	bar(0, 0, 1200, 76);

	char a;
	do
	{
		setfillcolor(WHITE);
		bar(0, 0, 1200, 76);

		setcolor(BLACK);
		line(1, 1, 1198, 1);
		line(1198, 1, 1198, 75);
		line(1198, 75, 1, 75);
		line(1, 75, 1, 1);

		outtextxy(3, 3, "欢迎进入杨宇航的秘密画板，请选择填充颜色：");
		outtextxy(3, 21, "1.输入1黑色 4.输入4青色 7.输入7棕色 A.输入A浅蓝 D.输入D浅红   G.输入G白色");
		outtextxy(3, 39, "2.输入2蓝色 5.输入5红色 8.输入8浅灰 B.输入B浅绿 E.输入E浅品红");
		outtextxy(3, 57, "3.输入3绿色 6.输入6品红 9.输入9暗灰 C.输入C浅青 F.输入F黄色");

		a = getch();

		switch (a)
		{
		case '1':this->fillColor = BLACK; break;
		case '2':this->fillColor = BLUE; break;
		case '3':this->fillColor = GREEN; break;
		case '4':this->fillColor = CYAN; break;
		case '5':this->fillColor = RED; break;
		case '6':this->fillColor = MAGENTA; break;
		case '7':this->fillColor = BROWN; break;
		case '8':this->fillColor = LIGHTGRAY; break;
		case '9':this->fillColor = DARKGRAY; break;
		case 'A':this->fillColor = LIGHTBLUE; break;
		case 'B':this->fillColor = LIGHTGREEN; break;
		case 'C':this->fillColor = LIGHTCYAN; break;
		case 'D':this->fillColor = LIGHTRED; break;
		case 'E':this->fillColor = LIGHTMAGENTA; break;
		case 'F':this->fillColor = YELLOW; break;
		case 'G':this->fillColor = WHITE; break;
		default:
			setfillcolor(WHITE);
			bar(0, 0, 1200, 76);

			setcolor(BLACK);
			line(1, 1, 1198, 1);
			line(1198, 1, 1198, 75);
			line(1198, 75, 1, 75);
			line(1, 75, 1, 1);

			outtextxy(3, 3, "输入错误");
			outtextxy(3, 21, "按任意键继续");
			getch();
		}
	} while (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9' && a != 'A' && a != 'B' && a != 'C' && a != 'D' && a != 'E' && a != 'F' && a != 'G');
	if (fillColor == WHITE)
		isFilled = false;
	else
		isFilled = true;
}

void Color::setIsFilled(bool isFilled)
{
	this->isFilled = isFilled;
}



Color::Color(color_t color, bool isFilled, color_t fillColor)
{
	this->color = color;
	this->isFilled = isFilled;
	this->fillColor = fillColor;
}

Color::Color(Color& color)
{
	this->color = color.getColor();
	this->isFilled = color.getIsFilled();
	this->fillColor = color.getFillColor();
}

void Color::setColor(color_t color)
{
	this->color - color;
}

bool Color::getIsFilled()
{
	return isFilled;
}

Color::~Color()
{}