#pragma once
#include "User.h"
#include  <Windows.h>
#include <fstream>
#include <conio.h>

class Maze
{
private:
	static const int UP = 72;
	static const int DOWN = 80;
	static const int LEFT = 75;
	static const int RIGHT = 77;
	int row;
	int col;
	int **maze;
	int x;
	int y;
	int checkfloor;
public:
	Maze();
	~Maze();
	void makeMaze(const int& floor);
	void show();
	void moveCursor();
	void setCursorView(bool visible);
	void gotoxy(int x, int y);
	bool checkWall();
	bool checkWin();
	bool checkDevil();
	void erase();
	void showhospital();
	void setMaze(int x, int y);
};