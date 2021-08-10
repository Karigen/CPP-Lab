#include<utility>
#include<vector>
#include<graphics.h>
#include<filesystem>
#include<fstream>
#include<iostream>
#include<string>
#include<stdexcept>
#include"Controller.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"Line.h"

Controller controller{ 1200,700 };

int Shape::numberOfShape = 0;
int LJRectangle::numberOfRectangl = 0;
int Circle::numberOfCircle = 0;
int Triangle::numberOfTriangle = 0;
int Line::numberOfLine = 0;

int main()
{
	controller.open();//�򿪻���
	std::vector<Shape*> shapePtrArr;
	for (char mainChoice, detailChoice; is_run;)//��ѭ��
	{
		controller.clearMenu();
		mainChoice = controller.mainMenu();
		if (mainChoice == '1')//��ҳ�棺����ͼ
		{
			for (char drawingChoice; is_run; delay_fps(60))
			{
				controller.clearMenu();
				drawingChoice = controller.drawingMenu();
				if (drawingChoice == '1')//��ҳ�棺����ͼ��������
				{
					Shape* shapePtr = new LJRectangle();
					shapePtr->draw();
					detailChoice =controller.detailMenu();
					if (detailChoice == '1')//��ҳ�棺����ͼ�������Σ�����ɫϸ�ڵ���
					{
						controller.clearMenu();
						shapePtr->colorDetail();
					}
					else if (shapePtrArr.size() != 0 && detailChoice == '2')//��ҳ�棺����ͼ�������Σ�������һͼ�αȽ�
					{
						controller.clearMenu();
						shapePtr->comparsion(shapePtrArr.back());
					}
					else if (detailChoice == '0')//��ҳ�棺����ͼ�������Σ����˳�
						;
					else
					{
						controller.clearMenu();
						controller.errorMenu();
					}
					shapePtrArr.push_back(shapePtr);
					break;
				}
				else if (drawingChoice == '2')//��ҳ�棺����ͼ����Բ��
				{
					Shape* shapePtr = new Circle();
					shapePtr->draw();
					detailChoice = controller.detailMenu();
					if (detailChoice == '1')//��ҳ�棺����ͼ����Բ�Σ�����ɫϸ�ڵ���
					{
						controller.clearMenu();
						shapePtr->colorDetail();
					}
					else if (shapePtrArr.size() != 0 && detailChoice == '2')//��ҳ�棺����ͼ����Բ�Σ�������һͼ�αȽ�
					{
						controller.clearMenu();
						shapePtr->comparsion(shapePtrArr.back());
					}
					else if (detailChoice == '0')//��ҳ�棺����ͼ����Բ�Σ����˳�
						;
					else
					{
						controller.clearMenu();
						controller.errorMenu();
					}
					shapePtrArr.push_back(shapePtr);
					break;
				}
				else if (drawingChoice == '3')//��ҳ�棺����ͼ����������
				{
					Shape* shapePtr = new Triangle();
					shapePtr->draw();
					detailChoice = controller.detailMenu();
					if (detailChoice == '1')//��ҳ�棺����ͼ���������Σ�����ɫϸ�ڵ���
					{
						controller.clearMenu();
						shapePtr->colorDetail();
					}
					else if (shapePtrArr.size() != 0 && detailChoice == '2')//��ҳ�棺����ͼ���������Σ�������һͼ�αȽ�
					{
						controller.clearMenu();
						shapePtr->comparsion(shapePtrArr.back());
					}
					else if (detailChoice == '0')//��ҳ�棺����ͼ���������Σ����˳�
						;
					else
					{
						controller.clearMenu();
						controller.errorMenu();
					}
					shapePtrArr.push_back(shapePtr);
					break;
				}
				else if (drawingChoice == '4')//��ҳ�棺����ͼ������
				{
					Shape* shapePtr = new Line(false);
					shapePtr->draw();
					detailChoice = controller.detailMenu();
					if (detailChoice == '1')//��ҳ�棺����ͼ�����ߣ�����ɫϸ�ڵ���
					{
						controller.clearMenu();
						shapePtr->colorDetail();
					}
					else if (shapePtrArr.size() != 0 && detailChoice == '2')//��ҳ�棺����ͼ�����ߣ�������һͼ�αȽ�
					{
						controller.clearMenu();
						shapePtr->comparsion(shapePtrArr.back());
					}
					else if (detailChoice == '0')//��ҳ�棺����ͼ�����ߣ����˳�
						;
					else
					{
						controller.clearMenu();
						controller.errorMenu();
					}
					shapePtrArr.push_back(shapePtr);
					break;
				}
				else//��ҳ�棺����ͼ�����������
				{
					controller.clearMenu();
					controller.errorMenu();
				}
			}
		}
		else if (mainChoice == '2')//��ҳ�棺������
		{
			controller.clearBoard();
			while (!shapePtrArr.empty())
			{
				delete shapePtrArr.back();
				shapePtrArr.back() = nullptr;
				shapePtrArr.pop_back();
			}
		}
		else if (mainChoice == '3')//��ҳ�棺����ȡ�ļ�
		{
			std::filesystem::path p{ "figure files.txt" };
			std::ifstream input{ p };
			while (!input.eof())
			{
				char shapeID = '0';
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
					rectanglePtr->draw();
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
					circlePtr->draw();
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
					trianglePtr->draw();
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
					linePtr->draw();
					shapePtrArr.push_back(linePtr);
				}
				else;
			}
			controller.clearMenu();
			controller.readMenu();
		}
		else if (mainChoice == '4')//��ҳ�棺�������ļ�
		{
			std::filesystem::path p{ "figure files.txt" };
			std::ofstream output{ p };
			for (Shape* i : shapePtrArr)
				output << i->toString();
			controller.clearMenu();
			controller.saveMenu();
		}
		else if (mainChoice == '0')//��ҳ�棺���˳�
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