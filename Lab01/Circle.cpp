#include<math.h>
#include<graphics.h>
#include"Point.h"
#include"Circle.h"

void Circle::draw()
{
	for (unsigned int x2 = 0, y2 = 0, count = 1; is_run; delay_fps(60))
	{
		mouse_msg msg = { 0 };
		while (mousemsg())
		{
			msg = getmouse();
		}
		if (msg.is_left() && msg.is_down() && count == 1)
		{
			centerOfCircle.setPointX(msg.x);
			centerOfCircle.setPointY(msg.y);
			count++;
		}
		else if (msg.is_left() && msg.is_down() && count == 2)
		{
			x2 = msg.x;
			y2 = msg.y;
			radius = sqrt((x2 - centerOfCircle.getPointX()) * (x2 - centerOfCircle.getPointX()) + (y2 - centerOfCircle.getPointY()) * (y2 - centerOfCircle.getPointY()));
			count++;
		}
		if (count == 3)
		{
			circle(centerOfCircle.getPointX(), centerOfCircle.getPointY(), radius);
			break;
		}
	}
}

Color Circle::getColors()
{
	return colors;
}