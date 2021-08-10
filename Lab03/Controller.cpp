#include<graphics.h>
#include"Controller.h"
#include"Shape.h"
#include"Point.h"
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
#include"Line.h"

Controller::Controller(unsigned int height, unsigned int width)
{
	this->height = height;
	this->width = width;
}

void Controller::open()
{
	initgraph(height, width, 0);
	setbkcolor(WHITE);
	setfont(18, 0, "����");
}

void Controller::clearMenu()
{
	setfillcolor(WHITE);
	bar(0, 0, 1200, 76);
}

void Controller::mainMenu()
{

	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);

	outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");//���˵�
	xyprintf(3, 21, "1.����1��ͼ                 4.����4����figure files.txt Shape��%d Tri��%d", LJRectangle::getNumberOfRectangl() + Circle::getNumberOfCircle() + Triangle::getNumberOfTriangle() + Line::getNumberOfLine(), Triangle::getNumberOfTriangle());
	xyprintf(3, 39, "2.����2�����Ļ             5.����0�˳�                 Rec��%d   Lin��%d", LJRectangle::getNumberOfRectangl(), Line::getNumberOfLine());
	xyprintf(3, 57, "3.����3��ȡfigure files.txt                             Cir��%d", Circle::getNumberOfCircle());
}

void Controller::drawingMenu()
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);

	outtextxy(3, 3, "��ӭ������������ܻ��壬����ݲ˵�ѡ��������еĲ�����");//��ͼ�˵�
	outtextxy(3, 21, "1.����1������   4.����4����");
	outtextxy(3, 39, "2.����2��Բ��");
	outtextxy(3, 57, "3.����3��������");
}

void Controller::readMenu()
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);

	outtextxy(3, 3, "��ȡ�ɹ�");
	outtextxy(3, 21, "�����������");
	getch();
}

void Controller::saveManu()
{
	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);

	outtextxy(3, 3, "����ɹ�");
	outtextxy(3, 21, "�����������");
	getch();
}

void Controller::errorMenu()
{

	setcolor(BLACK);
	line(1, 1, 1198, 1);
	line(1198, 1, 1198, 75);
	line(1198, 75, 1, 75);
	line(1, 75, 1, 1);

	outtextxy(3, 3, "�������");
	outtextxy(3, 21, "�����������");
	getch();
}

void Controller::clearBoard()
{
	setfillcolor(WHITE);
	bar(0, 76, 1200, 700);
}

void Controller::close()
{
	closegraph();
}

unsigned int Controller::getHeight()
{
	return height;
}

void Controller::setHeight(unsigned int height)
{
	this->height = height;
}

unsigned int Controller::getWidth()
{
	return width;
}
void Controller::setWidth(unsigned int width)
{
	this->width = width;
}