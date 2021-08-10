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
	controller.open();//打开画板
	std::vector<Shape*> shapePtrArr;
	for (char mainChoice, detailChoice; is_run;)//主循环
	{
		controller.clearMenu();
		mainChoice = controller.mainMenu();
		if (mainChoice == '1')//主页面：：画图
		{
			for (char drawingChoice; is_run; delay_fps(60))
			{
				controller.clearMenu();
				drawingChoice = controller.drawingMenu();
				if (drawingChoice == '1')//主页面：：画图：：矩形
				{
					Shape* shapePtr = new LJRectangle();
					shapePtr->draw();
					detailChoice =controller.detailMenu();
					if (detailChoice == '1')//主页面：：画图：：矩形：：颜色细节调控
					{
						controller.clearMenu();
						shapePtr->colorDetail();
					}
					else if (shapePtrArr.size() != 0 && detailChoice == '2')//主页面：：画图：：矩形：：与上一图形比较
					{
						controller.clearMenu();
						shapePtr->comparsion(shapePtrArr.back());
					}
					else if (detailChoice == '0')//主页面：：画图：：矩形：：退出
						;
					else
					{
						controller.clearMenu();
						controller.errorMenu();
					}
					shapePtrArr.push_back(shapePtr);
					break;
				}
				else if (drawingChoice == '2')//主页面：：画图：：圆形
				{
					Shape* shapePtr = new Circle();
					shapePtr->draw();
					detailChoice = controller.detailMenu();
					if (detailChoice == '1')//主页面：：画图：：圆形：：颜色细节调控
					{
						controller.clearMenu();
						shapePtr->colorDetail();
					}
					else if (shapePtrArr.size() != 0 && detailChoice == '2')//主页面：：画图：：圆形：：与上一图形比较
					{
						controller.clearMenu();
						shapePtr->comparsion(shapePtrArr.back());
					}
					else if (detailChoice == '0')//主页面：：画图：：圆形：：退出
						;
					else
					{
						controller.clearMenu();
						controller.errorMenu();
					}
					shapePtrArr.push_back(shapePtr);
					break;
				}
				else if (drawingChoice == '3')//主页面：：画图：：三角形
				{
					Shape* shapePtr = new Triangle();
					shapePtr->draw();
					detailChoice = controller.detailMenu();
					if (detailChoice == '1')//主页面：：画图：：三角形：：颜色细节调控
					{
						controller.clearMenu();
						shapePtr->colorDetail();
					}
					else if (shapePtrArr.size() != 0 && detailChoice == '2')//主页面：：画图：：三角形：：与上一图形比较
					{
						controller.clearMenu();
						shapePtr->comparsion(shapePtrArr.back());
					}
					else if (detailChoice == '0')//主页面：：画图：：三角形：：退出
						;
					else
					{
						controller.clearMenu();
						controller.errorMenu();
					}
					shapePtrArr.push_back(shapePtr);
					break;
				}
				else if (drawingChoice == '4')//主页面：：画图：：线
				{
					Shape* shapePtr = new Line(false);
					shapePtr->draw();
					detailChoice = controller.detailMenu();
					if (detailChoice == '1')//主页面：：画图：：线：：颜色细节调控
					{
						controller.clearMenu();
						shapePtr->colorDetail();
					}
					else if (shapePtrArr.size() != 0 && detailChoice == '2')//主页面：：画图：：线：：与上一图形比较
					{
						controller.clearMenu();
						shapePtr->comparsion(shapePtrArr.back());
					}
					else if (detailChoice == '0')//主页面：：画图：：线：：退出
						;
					else
					{
						controller.clearMenu();
						controller.errorMenu();
					}
					shapePtrArr.push_back(shapePtr);
					break;
				}
				else//主页面：：画图：：输入错误
				{
					controller.clearMenu();
					controller.errorMenu();
				}
			}
		}
		else if (mainChoice == '2')//主页面：：清屏
		{
			controller.clearBoard();
			while (!shapePtrArr.empty())
			{
				delete shapePtrArr.back();
				shapePtrArr.back() = nullptr;
				shapePtrArr.pop_back();
			}
		}
		else if (mainChoice == '3')//主页面：：读取文件
		{
			std::filesystem::path p{ "figure files.txt" };
			std::ifstream input{ p };
			while (!input.eof())
			{
				char shapeID = '0';
				input >> shapeID;
				if (shapeID == '1')//主页面：：读取文件：：矩形
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
				else if (shapeID == '2')//主页面：：读取文件：：圆形
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
				else if (shapeID == '3')//主页面：：读取文件：：三角形
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
				else if (shapeID == '4')//主页面：：读取文件：：线
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
		else if (mainChoice == '4')//主页面：：储存文件
		{
			std::filesystem::path p{ "figure files.txt" };
			std::ofstream output{ p };
			for (Shape* i : shapePtrArr)
				output << i->toString();
			controller.clearMenu();
			controller.saveMenu();
		}
		else if (mainChoice == '0')//主页面：：退出
		{
			while (!shapePtrArr.empty())//清空Shape* vector
			{
				delete shapePtrArr.back();
				shapePtrArr.back() = nullptr;
				shapePtrArr.pop_back();
			}
			break;
		}
		else//主页面：：输入错误
		{
			controller.clearMenu();
			controller.errorMenu();
		}
	}
	controller.close();//关闭画板
	return 0;
}