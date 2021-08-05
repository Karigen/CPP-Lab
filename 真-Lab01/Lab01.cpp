#include<graphics.h>
#include"Controller.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"Line.h"

Controller controller{ 1200,700 };

/*
3.1.创建新类
定义一个抽象的几何形状类。这个抽象类作为所有类的父类工作
其他具体几何形状类(不包括类，如“颜色”)。有一个纯粹的虚拟
函数draw()在这个抽象类中。“draw()”函数用于绘制你的几何形状
在图形窗口中。
注意 : 您还需要将geometry类的公共属性移动到
基类。例如，几何类的边界颜色。
3.2。修改现有的类
1)重构实验1中的几何形状类，使其继承上述
抽象类。
2)在每个类中添加一个复制构造函数和析构函数。
3)为每个类添加一个静态成员变量，以计算相应的存活对象。
为上述计数器变量添加一个静态getter函数。
4)在每个类中定制析构函数，以显示类中活动的对象。
3.3。创建和销毁对象
任何几何形状类中的“color”成员必须使用“new”操作符和创建
用“删除”操作符销毁。几何形状课的其他成员可能是
使用new / delete创建 / 销毁，或仅定义为生命周期被自动管理的堆栈对象 / 变量。
注意，当一个几何形状对象中的“color”成员被创建 / 销毁时
"new/delete"，你应该在几何的复制构造函数 / 析构函数中进行"深层复制"
形状类。
任何几何形状对象都应该用“新建”创建，用“删除”销毁。
3.4。绘制几何图形
在实验1中，您的程序将获得用户输入的形状数据，然后绘制这些数据
图形窗口中的几何形状。
现在，您的程序应该使用“多态性”来绘制几何形状。也就是说，
你需要用基类指针调用任何几何形状对象的“draw()”函数
或者基类引用。
3.5。你的项目的一般要求
您可以确定上述未提及的任何细节，只要这些细节是
对这个实验室来说是合理的。
*/

int main()
{
	controller.open();
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
					LJRectangle rectangle;
					rectangle.draw();
					break;
				}
				else if (b == '2')//圆形
				{
					Circle circle;
					circle.draw();
					break;
				}
				else if (b == '3')//三角形
				{
					Triangle triangle;
					triangle.draw();
					break;
				}
				else if (b == '4')//线
				{
					Line line;
					line.draw();
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
		}
		else if (a == '0')//退出
			break;
		else
		{
			controller.clearMenu();
			controller.errorMenu();
		}
	}
	controller.close();
	return 0;
}