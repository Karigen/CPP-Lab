#include<graphics.h>
#include"Controller.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Triangle.h"
#include"Line.h"

Controller controller{ 1200,700 };

/*
3.1.��������
����һ������ļ�����״�ࡣ�����������Ϊ������ĸ��๤��
�������弸����״��(�������࣬�硰��ɫ��)����һ�����������
����draw()������������С���draw()���������ڻ�����ļ�����״
��ͼ�δ����С�
ע�� : ������Ҫ��geometry��Ĺ��������ƶ���
���ࡣ���磬������ı߽���ɫ��
3.2���޸����е���
1)�ع�ʵ��1�еļ�����״�࣬ʹ��̳�����
�����ࡣ
2)��ÿ���������һ�����ƹ��캯��������������
3)Ϊÿ�������һ����̬��Ա�������Լ�����Ӧ�Ĵ�����
Ϊ�����������������һ����̬getter������
4)��ÿ�����ж�����������������ʾ���л�Ķ���
3.3�����������ٶ���
�κμ�����״���еġ�color����Ա����ʹ�á�new���������ʹ���
�á�ɾ�������������١�������״�ε�������Ա������
ʹ��new / delete���� / ���٣��������Ϊ�������ڱ��Զ�����Ķ�ջ���� / ������
ע�⣬��һ��������״�����еġ�color����Ա������ / ����ʱ
"new/delete"����Ӧ���ڼ��εĸ��ƹ��캯�� / ���������н���"��㸴��"
��״�ࡣ
�κμ�����״����Ӧ���á��½����������á�ɾ�������١�
3.4�����Ƽ���ͼ��
��ʵ��1�У����ĳ��򽫻���û��������״���ݣ�Ȼ�������Щ����
ͼ�δ����еļ�����״��
���ڣ����ĳ���Ӧ��ʹ�á���̬�ԡ������Ƽ�����״��Ҳ����˵��
����Ҫ�û���ָ������κμ�����״����ġ�draw()������
���߻������á�
3.5�������Ŀ��һ��Ҫ��
������ȷ������δ�ἰ���κ�ϸ�ڣ�ֻҪ��Щϸ����
�����ʵ������˵�Ǻ���ġ�
*/

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
					rectangle.draw();
					break;
				}
				else if (b == '2')//Բ��
				{
					Circle circle;
					circle.draw();
					break;
				}
				else if (b == '3')//������
				{
					Triangle triangle;
					triangle.draw();
					break;
				}
				else if (b == '4')//��
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