#pragma once

class Controller
{
private:
	unsigned int height;
	unsigned int width;
public:
	Controller() = delete;
	Controller(unsigned int height, unsigned int width);
	void open();
	void clearMenu();
	void mainMenu();
	void drawingMenu();
	void errorMenu();
	void clearBoard();
	void close();

	unsigned int getHeight();
	void setHeight(unsigned int height);
	unsigned int getWidth();
	void setWidth(unsigned int width);
};