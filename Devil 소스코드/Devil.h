#pragma once
#include "User.h"
#include "Maze.h"
#include "Tetrix.h"
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <vector>
class Devil
{
private:
	int count;
	vector<User> user;
	Maze **maze;
	Tetrix tetrix;
	ofstream outFile;
	bool gn=true;
public:
	Devil();
	~Devil();
	void bgm1start();
	void bgm2start();
	void bgmpause();
	int gotoxy(int x, int y);
	void cursor(int n);
	void play();
	void viewRank();
	void init();
	void showStory(int story);
	bool devil(int game, int floor);
	void showghost(bool a);

	void ending();
};

