#include"Line.h"

void Line::draw()
{
	for (int count = 1; is_run; delay_fps(60))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
		{
			msg = getmouse();
		}
		if (msg.is_left() && msg.is_down() && count == 1)
		{
			p1.setPointX(msg.x);
			p1.setPointY(msg.y);
			count++;
		}
		else if (msg.is_left() && msg.is_down() && count == 2)
		{
			p2.setPointX(msg.x);
			p2.setPointY(msg.y);
			count++;
		}
		else if (count == 3)
		{
			line(p1.getPointX(), p1.getPointY(), p2.getPointX(), p2.getPointY());
			break;
		}
	}
}

Color Line::getColors()
{
	return colors;
}