#include"Shape.h"
#include<conio.h>

Shape::Shape() :ptrOfColors(new Color())
{
	numberOfShape++;
}

Shape::Shape(const bool isFilled) : ptrOfColors(new Color(isFilled))
{
	numberOfShape++;
}

Shape::Shape(const color_t color, const bool isFilled) : ptrOfColors(new Color(color, isFilled))
{
	numberOfShape++;
}

int Shape::getNumberOfShape()
{
	return numberOfShape;
}

bool Shape::operator<(const Shape* shapePtr)const
{
	if (this->getArea() < shapePtr->getArea())
		return true;
	else
		return false;
}

bool Shape::operator>(const Shape* shapePtr)const
{
	if (this->getArea() > shapePtr->getArea())
		return true;
	else
		return false;
}

bool Shape::operator<=(const Shape* shapePtr)const
{
	if (this->getArea() <= shapePtr->getArea())
		return true;
	else
		return false;
}

bool Shape::operator>=(const Shape* shapePtr)const
{
	if (this->getArea() >= shapePtr->getArea())
		return true;
	else
		return false;
}

bool Shape::operator==(const Shape* shapePtr)const
{
	if (this->getArea() == shapePtr->getArea())
		return true;
	else
		return false;
}

bool Shape::operator!=(const Shape* shapePtr)const
{
	if (this->getArea() != shapePtr->getArea())
		return true;
	else
		return false;
}

Shape::~Shape()
{
	delete ptrOfColors;
	numberOfShape--;
}

void Shape::colorDetail()
{
	for (char indexChoice; is_run; delay_fps(60))
	{
		setcolor(BLACK);
		line(1, 1, 1198, 1);
		line(1198, 1, 1198, 75);
		line(1198, 75, 1, 75);
		line(1, 75, 1, 1);
		setfontbkcolor(WHITE);
		bool isClear = true;
		outtextxy(3, 3, "颜色对应RGB值:");
		try
		{
			xyprintf(3, 21, "对应值为：%d,%d,%d", (*(this->ptrOfColors))['0'], (*(this->ptrOfColors))['1'], (*(this->ptrOfColors))['2']);
		}
		catch (const std::exception&)
		{
			setfillcolor(WHITE);
			bar(0, 0, 1200, 76);
			setcolor(BLACK);
			line(1, 1, 1198, 1);
			line(1198, 1, 1198, 75);
			line(1198, 75, 1, 75);
			line(1, 75, 1, 1);
			setfontbkcolor(WHITE);
			outtextxy(3, 3, "输入错误");
			outtextxy(3, 21, "按任意键继续");
			getch();
			setfillcolor(WHITE);
			bar(0, 0, 1200, 76);
		}
		xyprintf(3, 39, "操作前：（%d,%d,%d)", (*(this->ptrOfColors))['0'], (*(this->ptrOfColors))['1'], (*(this->ptrOfColors))['2']);
		outtextxy(3, 57, "操作后：");
		outtextxy(540, 3, "前置++");
		outtextxy(540, 21, "后置++");
		outtextxy(540, 39, "前置--");
		outtextxy(540, 57, "后置--");
		outtextxy(720, 3, "退出");
		
		int x = 0, y = 0;
		mouse_msg msg = { 0 };
		while (mousemsg())
		{
			msg = getmouse();
		}
		mousepos(&x, &y);

		if (x <= 612 && x >= 540 && y <= 18 && y >= 3)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(540, 3, "前置++");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				setfillcolor(WHITE);
				bar(3, 39, 183, 75);
				setfontbkcolor(WHITE);
				setcolor(BLACK);
				Color temp = ++(*(this->ptrOfColors));
				xyprintf(3, 39, "操作前：（%d,%d,%d)", (*(this->ptrOfColors))['0'], (*(this->ptrOfColors))['1'], (*(this->ptrOfColors))['2']);
				xyprintf(3, 57, "操作后：（%d,%d,%d)", temp['0'], temp['1'], temp['2']);
			}
		}
		else if (x <= 612 && x >= 540 && y <= 36 && y >= 24)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(540, 21, "后置++");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				setfillcolor(WHITE);
				bar(3, 39, 183, 75);
				setfontbkcolor(WHITE);
				setcolor(BLACK);
				Color temp = (*(this->ptrOfColors))++;
				xyprintf(3, 39, "操作前：（%d,%d,%d)", (*(this->ptrOfColors))['0'], (*(this->ptrOfColors))['1'], (*(this->ptrOfColors))['2']);
				xyprintf(3, 57, "操作后：（%d,%d,%d)", temp['0'], temp['1'], temp['2']);
			}
		}
		else if (x <= 612 && x >= 540 && y <= 54 && y >= 42)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(540, 39, "前置--");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				setfillcolor(WHITE);
				bar(3, 39, 183, 75);
				setfontbkcolor(WHITE);
				setcolor(BLACK);
				Color temp = --(*(this->ptrOfColors));
				xyprintf(3, 39, "操作前：（%d,%d,%d)", (*(this->ptrOfColors))['0'], (*(this->ptrOfColors))['1'], (*(this->ptrOfColors))['2']);
				xyprintf(3, 57, "操作后：（%d,%d,%d)", temp['0'], temp['1'], temp['2']);
			}
		}
		else if (x <= 612 && x >= 540 && y <= 75 && y >= 60)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(540, 57, "后置--");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				setfillcolor(WHITE);
				bar(3, 39, 183, 75);
				setfontbkcolor(WHITE);
				setcolor(BLACK);
				Color temp = (*(this->ptrOfColors))--;
				xyprintf(3, 39, "操作前：（%d,%d,%d)", (*(this->ptrOfColors))['0'], (*(this->ptrOfColors))['1'], (*(this->ptrOfColors))['2']);
				xyprintf(3, 57, "操作后：（%d,%d,%d)", temp['0'], temp['1'], temp['2']);
			}
		}
		else if (x <= 756 && x >= 720 && y <= 21 && y >= 3)
		{
			setfontbkcolor(BLACK);
			setcolor(WHITE);
			outtextxy(720, 3, "退出");
			isClear = false;
			if (msg.is_left() && msg.is_down())
			{
				break;
			}
		}
		else if (isClear == false)
		{
			setfontbkcolor(WHITE);
			setcolor(BLACK);
			outtextxy(540, 3, "前置++");
			outtextxy(540, 21, "后置++");
			outtextxy(540, 39, "前置--");
			outtextxy(540, 57, "后置--");
			outtextxy(720, 3, "退出");
			isClear = true;
		}
		this->draw();
	}
}



Shape::Shape(const Shape& shape)
{
	this->ptrOfColors = new Color(*(shape.ptrOfColors));
	this->shapeID = shape.shapeID;
	numberOfShape++;
}

Color* Shape::getPtrOfColors()const
{
	return ptrOfColors;
}

void Shape::setPtrOfColors(Color* ptrOfColors)
{
	this->ptrOfColors = ptrOfColors;
}

char Shape::getShapeID()const
{
	return shapeID;
}

void Shape::setShapeID(const char shapeID)
{
	this->shapeID = shapeID;
}