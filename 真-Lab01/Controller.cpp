#include<graphics.h>
#include"Controller.h"

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
	outtextxy(3, 21, "1.����1��ͼ");
	outtextxy(3, 39, "2.����2�����Ļ");
	outtextxy(3, 57, "3.����0�˳�");
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