#include "Maze.h"



Maze::Maze()
	:row(30), col(30), x(0), y(0)
{
	maze = new int*[row];
	for (int i = 0; i < row; i++)
		maze[i] = new int[col];
}

Maze::~Maze()
{
	for (int i = 0; i < row; i++)
		delete maze[i];
	delete[] maze;
}
void Maze::makeMaze(const int& floor)
{
	checkfloor = floor;
	ifstream inputFile;
	switch (floor) {
	case 1:
		inputFile.open("1fMaze.txt");
		if (inputFile.is_open()) {
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					inputFile >> maze[i][j];
		}
		break;
	case 2:
		inputFile.open("2fMaze.txt");
		if (inputFile.is_open()) {
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					inputFile >> maze[i][j];
		}
		break;
	case 3:
		inputFile.open("3fMaze.txt");
		if (inputFile.is_open()) {
			for (int i = 0; i < row; i++)
				for (int j = 0; j < col; j++)
					inputFile >> maze[i][j];

		}
		break;

	}
}
void Maze::show() { //미로(폐병동) 출력
	setCursorView(false);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (maze[i][j] == 1)
				cout << "■";
			else
				cout << "  ";
		}
		if (i == row - 1)
			break;
		cout << endl;
	}
	showhospital();

}
void Maze::moveCursor() {
	gotoxy(x, y);
	cout << "▣";
	int ch = _getch();
	if (ch == 224) {
		ch = _getch();
		switch (ch) {
		case UP:
			erase();
			y--;
			if (!checkWall()) //장애물인지, 좌표가 배열의 크기를 벗어나는지 판단 길이면 true
				y++;
			break;
		case DOWN:
			erase();
			y++;
			if (!checkWall())
				y--;
			break;
		case LEFT:
			erase();
			x -= 2;
			if (!checkWall())
				x += 2;
			break;
		case RIGHT:
			erase();
			x += 2;
			if (!checkWall())
				x -= 2;
			break;

		}
	}

}
bool Maze::checkWall() { //벽인지 판단
	if (maze[y][x / 2] == 1) 
		return false;
	else
		return true;
} 
void Maze::erase() { //움직이면 그 전 위치 지우기
	gotoxy(x, y);
	cout << "  ";

}
bool Maze::checkWin() { //탈출구에 도달했는지 판단
	gotoxy(0, 13);
	if (maze[y][x / 2] == 2) {
		system("cls");
		x = 0, y = 0;
		return true;
	}
	return false;
}
bool Maze::checkDevil() { 
	if (maze[y][x / 2] == 3) {
		maze[y][x / 2] = 0; //귀신을 만나서 테트리스를 하고 미로로 돌아왔을 때, 다시 테트리스를 안하도록 0으로 바꾸기
		return true;
	}
	return false;
}
void Maze::setMaze(int x,int y) {
	this->x = x;
	this->y = y;
}
void Maze::setCursorView(bool visible) {
	CONSOLE_CURSOR_INFO cursor = { 1, visible };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void Maze::gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void Maze::showhospital()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(62, 5);
	cout << "┏━━━━━━━━━━━━┓" << endl;
	gotoxy(62, 6);
	cout << "┃         "<<checkfloor<<"f floor       ┃ " << endl;
	gotoxy(62, 7);
	cout << "┗━━━━━━━━━━━━┛" << endl;


	gotoxy(62, 10);
	cout << "┏━━━━━━━━━━━━┓/＼     /＼" << endl;
	gotoxy(62, 11);
	cout << "┃ Konkuk mental Hospital ┃||______|┃ " << endl;
	gotoxy(62, 12);
	cout << "┃     closed at 2003     ┃|| ^  ^ |┃" << endl;
	gotoxy(62, 13);
	cout << "┗━━━━━━━━━━━━┛'| |  | |/" << endl;
	gotoxy(62, 14);
	cout << "                             |______|" << endl;
	gotoxy(62, 15);
	cout << "                             |  __  |" << endl;
	gotoxy(62, 16);
	cout << "     ________________________|_/  ＼|___" << endl;
	gotoxy(62, 17);
	cout << "    /=====□■□==============/ ^^ ＼===|" << endl;
	gotoxy(62, 18);
	cout << "   /======■■■=============/  []  ＼==|" << endl;
	gotoxy(62, 19);
	cout << "  /=======□■□============/________＼=|" << endl;
	gotoxy(62, 20);
	cout << " /==========================|         |=|" << endl;
	gotoxy(62, 21);
	cout << "|---------------------------| ^^  ^^  |--" << endl;
	gotoxy(62, 22);
	cout << "|           _____           | []  []  | |" << endl;
	gotoxy(62, 23);
	cout << "|          /_____＼         |      *  | |" << endl;
	gotoxy(62, 24);
	cout << "|  ^^  ^^  |  |  |  ^^  ^^  |     *** | |" << endl;
	gotoxy(62, 25);
	cout << "|  []  []  |  |  |  []  []  | ===*****  |" << endl;
	gotoxy(62, 26);
	cout << "|         @|__|__|@         |/ |******* |" << endl;
	gotoxy(62, 27);
	cout << "**********--=====--**********| ********* " << endl;
	gotoxy(62, 28);
	cout << "********** |=====| **********|*********** ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
