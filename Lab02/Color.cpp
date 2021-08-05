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

		outtextxy(3, 3, "��ӭ������������ܻ��壬��ѡ��߽���ɫ��");
		outtextxy(3, 21, "1.����1��ɫ 4.����4��ɫ 7.����7��ɫ A.����Aǳ�� D.����Dǳ��   G.����G��ɫ");
		outtextxy(3, 39, "2.����2��ɫ 5.����5��ɫ 8.����8ǳ�� B.����Bǳ�� E.����EǳƷ��");
		outtextxy(3, 57, "3.����3��ɫ 6.����6Ʒ�� 9.����9���� C.����Cǳ�� F.����F��ɫ");

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

			outtextxy(3, 3, "�������");
			outtextxy(3, 21, "�����������");
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

		outtextxy(3, 3, "��ӭ������������ܻ��壬��ѡ�������ɫ��");
		outtextxy(3, 21, "1.����1��ɫ 4.����4��ɫ 7.����7��ɫ A.����Aǳ�� D.����Dǳ��   G.����G��ɫ");
		outtextxy(3, 39, "2.����2��ɫ 5.����5��ɫ 8.����8ǳ�� B.����Bǳ�� E.����EǳƷ��");
		outtextxy(3, 57, "3.����3��ɫ 6.����6Ʒ�� 9.����9���� C.����Cǳ�� F.����F��ɫ");

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

			outtextxy(3, 3, "�������");
			outtextxy(3, 21, "�����������");
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