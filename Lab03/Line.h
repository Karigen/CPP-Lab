#pragma once

#include<string>
#include"Shape.h"
#include"Point.h"

class Line :public Shape
{
private:
	Point p1;
	Point p2;
	static int numberOfLine;
public:
	Line();
	void draw()override;
	void reDraw()override;
	std::string toString()override;
	Line(unsigned int p1x, unsigned int p1y, unsigned int p2x, unsigned int p2y, color_t color, bool isFilled, color_t fillColor);
	static Line* read(std::ifstream& input);
	static void findError(std::ifstream& input);

	Line(Color colors, Point p1, Point p2);
	Line(Line& line);
	Point& getP1();
	void setP1(Point p1);
	Point& getP2();
	void setP2(Point p2);
	static int getNumberOfLine();
	~Line()override;
};