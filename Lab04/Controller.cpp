#include<graphics.h>
#include"Controller.h"
#include"Shape.h"
#include"Point.h"
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
#include"Line.h"

Controller::Controller(const unsigned int height, const unsigned int width)
{
	this->height = height;
	this->width = width;
}

void Controller::open()const
{
	initgraph(height, width, 0);
	setbkcolor(WHITE);
	setfont(18, 0, "����");
}

void Controller::clearMenu()const
{
	setfillcolor(WHITE);
	bar(0, 0, 1200, 76);
}

void Controller::clearBoard()const
{
	setfillcolor(WHITE);
	bar(0, 76, 1200, 700);
}

char Controller::mainMenu()const
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);

	setfontbkcolor(WHITE);
	outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");
	outtextxy(3, 21, "��ͼ");
	outtextxy(3, 39, "�����Ļ");
	outtextxy(3, 57, "��ȡfigure files.txt");
	outtextxy(180, 21, "����figure files.txt");
	outtextxy(180, 39, "�˳�");
	xyprintf(540, 21, "Sha:%d", Shape::getNumberOfShape());
	xyprintf(540, 39, "Rec:%d", LJRectangle::getNumberOfRectangl());
	xyprintf(540, 57, "Cir:%d", Circle::getNumberOfCircle());
	xyprintf(720, 21, "Tri:%d", Triangle::getNumberOfTriangle());
	xyprintf(720, 39, "Lin:%d", Line::getNumberOfLine());
	int x = 0, y = 0;
	for (bool isClear = true; is_run; delay_fps(60))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
		{
			msg = getmouse();
		}
		mousepos(&x, &y);

		if (x <= 39 && x >= 3 && y <= 36 && y >= 21)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(3, 21, "��ͼ");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '1';
			}
		}
		else if (x <= 75 && x >= 3 && y <= 54 && y >= 42)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(3, 39, "�����Ļ");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '2';
			}
		}
		else if (x <= 183 && x >= 3 && y <= 75 && y >= 60)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(3, 57, "��ȡfigure files.txt");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '3';
			}
		}
		else if (x <= 360 && x >= 180 && y <= 36 && y >= 21)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(180, 21, "����figure files.txt");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '4';
			}
		}
		else if (x <= 216 && x >= 180 && y <= 54 && y >= 42)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(180, 39, "�˳�");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '0';
			}
		}
		else if (isClear == false)
		{
			setfontbkcolor(WHITE);
			setcolor(BLACK);
			outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");//���˵�
			outtextxy(3, 21, "��ͼ");
			outtextxy(3, 39, "�����Ļ");
			outtextxy(3, 57, "��ȡfigure files.txt");
			outtextxy(180, 21, "����figure files.txt");
			outtextxy(180, 39, "�˳�");
			xyprintf(540, 21, "Sha:%d", Shape::getNumberOfShape());
			xyprintf(540, 39, "Rec:%d", LJRectangle::getNumberOfRectangl());
			xyprintf(540, 57, "Cir:%d", Circle::getNumberOfCircle());
			xyprintf(720, 21, "Tri:%d", Triangle::getNumberOfTriangle());
			xyprintf(720, 39, "Lin:%d", Line::getNumberOfLine());
			isClear = true;
		}
	}
}

char Controller::drawingMenu()const
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);

	setfontbkcolor(WHITE);
	outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");
	outtextxy(3, 21, "����");
	outtextxy(3, 39, "Բ��");
	outtextxy(3, 57, "������");
	outtextxy(180, 21, "��");
	int x = 0, y = 0;
	for (bool isClear = true; is_run; delay_fps(60))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
		{
			msg = getmouse();
		}
		mousepos(&x, &y);

		if (x <= 39 && x >= 3 && y <= 36 && y >= 21)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(3, 21, "����");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '1';
			}
		}
		else if (x <= 39 && x >= 3 && y <= 54 && y >= 42)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(3, 39, "Բ��");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '2';
			}
		}
		else if (x <= 57 && x >= 3 && y <= 75 && y >= 60)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(3, 57, "������");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '3';
			}
		}
		else if (x <= 198 && x >= 180 && y <= 36 && y >= 21)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(180, 21, "��");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '4';
			}
		}
		else if (isClear == false)
		{
			setfontbkcolor(WHITE);
			setcolor(BLACK);
			outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");
			outtextxy(3, 21, "����");
			outtextxy(3, 39, "Բ��");
			outtextxy(3, 57, "������");
			outtextxy(180, 21, "��");
			isClear = true;
		}
	}
}

void Controller::readMenu()const
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);
	setfontbkcolor(WHITE);
	outtextxy(3, 3, "��ȡ�ɹ�");
	outtextxy(3, 21, "�����������");
	getch();
}

void Controller::saveMenu()const
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);
	setfontbkcolor(WHITE);
	outtextxy(3, 3, "����ɹ�");
	outtextxy(3, 21, "�����������");
	getch();
}


void Controller::errorMenu()const
{

	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);
	setfontbkcolor(WHITE);
	outtextxy(3, 3, "�������");
	outtextxy(3, 21, "�����������");
	getch();
}

char Controller::detailMenu()const
{
	setfontbkcolor(WHITE);
	setcolor(BLACK);
	outtextxy(480, 39, "��ɫϸ�ڵ���");
	outtextxy(480, 57, "��һͼ�αȽ�");
	outtextxy(700, 3, "�˳�");
	int x = 0, y = 0;
	for (bool isClear = true; is_run; delay_fps(60))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
		{
			msg = getmouse();
		}
		mousepos(&x, &y);

		if (x <= 590 && x >= 480 && y <= 54 && y >= 39)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(480, 39, "��ɫϸ�ڵ���");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '1';
			}
		}
		else if (x <= 590 && x >= 480 && y <= 75 && y >= 60)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(480, 57, "��һͼ�αȽ�");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '2';
			}
		}
		else if (x <= 736 && x >= 700 && y <= 21 && y >= 3)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(700, 3, "�˳�");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				return '0';
			}
		}
		else if (isClear == false)
		{
			setfontbkcolor(WHITE);
			setcolor(BLACK);
			outtextxy(480, 39, "��ɫϸ�ڵ���");//���˵�
			outtextxy(480, 57, "��һͼ�αȽ�");
			outtextxy(700, 3, "�˳�");
			isClear = true;
		}
	}
}

void Controller::close()const
{
	closegraph();
}



unsigned int Controller::getHeight()const
{
	return height;
}

void Controller::setHeight(const unsigned int height)
{
	this->height = height;
}

unsigned int Controller::getWidth()const
{
	return width;
}

void Controller::setWidth(const unsigned int width)
{
	this->width = width;
}