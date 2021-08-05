#include<utility>
#include<vector>
#include<graphics.h>
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
	controller.open();
	std::vector<Shape*> shapePtrArr;
	for (char a; is_run;)//画图循环
	{
		controller.clearMenu();
		controller.mainMenu();
		a = getch();
		if (a == '1')//画
		{
			for (char b; is_run; delay_fps(60))
			{
				controller.clearMenu();
				controller.drawingMenu();
				b = getch();
				if (b == '1')//矩形
				{
					LJRectangle* rectanglePtr = new LJRectangle();
					draw(rectanglePtr);
					shapePtrArr.push_back(rectanglePtr);
					break;
				}
				else if (b == '2')//圆形
				{
					Circle* circlePtr = new Circle();
					draw(circlePtr);
					shapePtrArr.push_back(circlePtr);
					break;
				}
				else if (b == '3')//三角形
				{
					Triangle* trianglePtr = new Triangle();
					draw(trianglePtr);
					shapePtrArr.push_back(trianglePtr);
					break;
				}
				else if (b == '4')//线
				{
					Line* linePtr = new Line();
					draw(linePtr);
					shapePtrArr.push_back(linePtr);
					break;
				}
				else
				{
					controller.clearMenu();
					controller.errorMenu();
				}
			}
		}
		else if (a == '2')//清屏
		{
			controller.clearBoard();
			while (!shapePtrArr.empty())
			{
				delete shapePtrArr.back();
				shapePtrArr.back() = nullptr;
				shapePtrArr.pop_back();
			}
		}
		else if (a == '0')//退出
		{
			while (!shapePtrArr.empty())
			{
				delete shapePtrArr.back();
				shapePtrArr.back() = nullptr;
				shapePtrArr.pop_back();
			}
			break;
		}
		else
		{
			controller.clearMenu();
			controller.errorMenu();
		}
	}
	controller.close();
	return 0;
}

void draw(Shape* shapePtr)
{
	shapePtr->draw();
}