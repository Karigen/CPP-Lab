#pragma once

class Controller
{
private:
	unsigned int height;
	unsigned int width;
public:
	Controller() = delete;
	Controller(const unsigned int height, const unsigned int width);
	void open()const;
	void clearMenu()const;
	void clearBoard()const;
	char mainMenu()const;
	char drawingMenu()const;
	void readMenu()const;
	void saveMenu()const;
	void errorMenu()const;
	char detailMenu()const;
	void close()const;
	~Controller() = default;

	unsigned int getHeight()const;
	void setHeight(const unsigned int height);
	unsigned int getWidth()const;
	void setWidth(const unsigned int width);
};