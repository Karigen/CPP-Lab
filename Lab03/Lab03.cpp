#include<utility>
#include<vector>
#include<graphics.h>
#include<filesystem>
#include<fstream>
#include<iostream>
#include<string>
#include"Controller.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"Line.h"

Controller controller{ 1200,700 };

int Shape::numberOfShape = 0;
int Point::numberOfPoint = 0;
int LJRectangle::numberOfRectangl = 0;
int Circle::numberOfCircle = 0;
int Triangle::numberOfTriangle = 0;
int Line::numberOfLine = 0;

void draw(Shape* shapePtr);

int main()
{
	controller.open();//�򿪻���
	std::vector<Shape*> shapePtrArr;
	for (char a; is_run;)//��ѭ��
	{
		controller.clearMenu();
		controller.mainMenu();
		a = getch();
		if (a == '1')//��ҳ�棺����ͼ
		{
			for (char b; is_run; delay_fps(60))
			{
				controller.clearMenu();
				controller.drawingMenu();
				b = getch();
				if (b == '1')//��ҳ�棺����ͼ��������
				{
					LJRectangle* rectanglePtr = new LJRectangle();
					draw(rectanglePtr);
					shapePtrArr.push_back(rectanglePtr);
					break;
				}
				else if (b == '2')//��ҳ�棺����ͼ����Բ��
				{
					Circle* circlePtr = new Circle();
					draw(circlePtr);
					shapePtrArr.push_back(circlePtr);
					break;
				}
				else if (b == '3')//��ҳ�棺����ͼ����������
				{
					Triangle* trianglePtr = new Triangle();
					draw(trianglePtr);
					shapePtrArr.push_back(trianglePtr);
					break;
				}
				else if (b == '4')//��ҳ�棺����ͼ������
				{
					Line* linePtr = new Line();
					draw(linePtr);
					shapePtrArr.push_back(linePtr);
					break;
				}
				else//��ҳ�棺����ͼ�����������
				{
					controller.clearMenu();
					controller.errorMenu();
				}
			}
		}
		else if (a == '2')//��ҳ�棺������
		{
			controller.clearBoard();
			while (!shapePtrArr.empty())
			{
				delete shapePtrArr.back();
				shapePtrArr.back() = nullptr;
				shapePtrArr.pop_back();
			}
		}
		else if (a == '3')//��ҳ�棺����ȡ�ļ�
		{
			std::filesystem::path p{ "figure files.txt" };
			std::ifstream input{ p };
			while (!input.eof())
			{
				char shapeID /*= '0'*/;
				input >> shapeID;
				if (shapeID == '1')//��ҳ�棺����ȡ�ļ���������
				{
					try
					{
						LJRectangle::findError(input);
					}
					catch (bool)
					{
						continue;
					}
					LJRectangle* rectanglePtr = LJRectangle::read(input);
					rectanglePtr->reDraw();
					shapePtrArr.push_back(rectanglePtr);
				}
				else if (shapeID == '2')//��ҳ�棺����ȡ�ļ�����Բ��
				{
					try
					{
						Circle::findError(input);
					}
					catch (bool)
					{
						continue;
					}
					Circle* circlePtr = Circle::read(input);
					circlePtr->reDraw();
					shapePtrArr.push_back(circlePtr);
				}
				else if (shapeID == '3')//��ҳ�棺����ȡ�ļ�����������
				{
					try
					{
						Triangle::findError(input);
					}
					catch (bool)
					{
						continue;
					}
					Triangle* trianglePtr = Triangle::read(input);
					trianglePtr->reDraw();
					shapePtrArr.push_back(trianglePtr);
				}
				else if (shapeID == '4')//��ҳ�棺����ȡ�ļ�������
				{
					try
					{
						Line::findError(input);
					}
					catch (bool)
					{
						continue;
					}
					Line* linePtr = Line::read(input);
					linePtr->reDraw();
					shapePtrArr.push_back(linePtr);
				}
				else;
			}
			controller.clearMenu();
			controller.readMenu();
		}
		else if (a == '4')//��ҳ�棺�������ļ�
		{
			std::filesystem::path p{ "figure files.txt" };
			std::ofstream output{ p };
			for (Shape* i : shapePtrArr)
				output << i->toString();
			controller.clearMenu();
			controller.saveManu();
		}
		else if (a == '0')//��ҳ�棺���˳�
		{
			while (!shapePtrArr.empty())//���Shape* vector
			{
				delete shapePtrArr.back();
				shapePtrArr.back() = nullptr;
				shapePtrArr.pop_back();
			}
			break;
		}
		else//��ҳ�棺���������
		{
			controller.clearMenu();
			controller.errorMenu();
		}
	}
	controller.close();//�رջ���
	return 0;
}

void draw(Shape* shapePtr)
{
	shapePtr->draw();
}