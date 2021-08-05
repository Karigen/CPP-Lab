#include<graphics.h>
#include"Controller.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"Line.h"

Controller controller{ 1200,700 };

int main()
{
	controller.open();
	for (char a; is_run;)//��ͼѭ��
	{
		controller.clearMenu();
		controller.mainMenu();
		a = getch();
		if (a == '1')//��
		{
			for (char b; is_run; delay_fps(60))
			{
				controller.clearMenu();
				controller.drawingMenu();
				b = getch();
				if (b == '1')//����
				{
					LJRectangle rectangle;
					rectangle.getColors().setColor();
					rectangle.draw();
					rectangle.getColors().setFillColor();
					rectangle.getColors().fill();
					break;
				}
				else if (b == '2')//Բ��
				{
					Circle circle;
					circle.getColors().setColor();
					circle.draw();
					circle.getColors().setFillColor();
					circle.getColors().fill();
					break;
				}
				else if (b == '3')//������
				{
					Triangle triangle;
					triangle.getColors().setColor();
					triangle.draw();
					triangle.getColors().setFillColor();
					triangle.getColors().fill();
					break;
				}
				else if (b == '4')//��
				{
					Line line;
					line.getColors().setColor();
					line.draw();
				}
				else
				{
					controller.clearMenu();
					controller.errorMenu();
				}
			}
		}
		else if (a == '2')//����
		{
			controller.clearBoard();
		}
		else if (a == '0')//�˳�
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