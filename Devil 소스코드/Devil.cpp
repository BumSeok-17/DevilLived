#include "Devil.h"
#pragma comment(lib, "winmm.lib")
#include "Mmsystem.h"
#include "Digitalv.h"
MCI_OPEN_PARMS m_mciOpenParms;
MCI_PLAY_PARMS m_mciPlayParms;
DWORD m_dwDeviceID;
MCI_OPEN_PARMS mciOpen;
MCI_PLAY_PARMS mciPlay;
#include <atlstr.h> 
#define print( str ) printf( "%s\n", str )
int dwID;

Devil::Devil()
	:count(0), user(NULL), maze(NULL)
{
	maze = new Maze*[3];
	for (int i = 0; i < 3; i++) {
		maze[i] = new Maze();
		maze[i]->makeMaze(i + 1);
	}
	outFile.open("user.txt", ios::app);

}



Devil::~Devil()
{
	for (int i = 0; i < 3; i++)
		delete maze[i];
	delete[] maze;

}
void Devil::bgm1start() {
	mciOpen.lpstrElementName = "HORROR Background Music.mp3"; // 파일 경로 입력
	mciOpen.lpstrDeviceType = "mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
		(DWORD)(LPVOID)&m_mciPlayParms);
}

void Devil::bgm2start() {
	mciOpen.lpstrElementName = "mazebgm.mp3"; // 파일 경로 입력
	mciOpen.lpstrDeviceType = "mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
		(DWORD)(LPVOID)&m_mciPlayParms);
}

void Devil::bgmpause() {
	 mciSendCommandW(dwID, MCI_PAUSE, MCI_NOTIFY,
	(DWORD)(LPVOID)&m_mciPlayParms); 
}

int Devil::gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void Devil::cursor(int n)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}




void Devil::play()
{
	//bgm
	
	bgm1start();
	


	system("mode con:cols=107 lines=30");
	system("title Devil,Lived");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << " ______    _______             __________ _              _        __________            _______   ______  " << endl;
		cout << "(  __  ＼ (  ____ ＼|＼      /|＼__   __/( ＼           ( ＼      ＼__   __/|＼      /|(  _____＼(  __  ＼ " << endl;
		cout << "| (  ＼ ) | (    ＼/| )     ( |    ) (   |  (           |  (          ) (   | )     ( || (    ＼/| (  ＼  )" << endl;
		cout << "| |   ) | | (__     | |     | |    | |   |  |           |  |          | |   | |     | || (__     | |    ) |" << endl;
		cout << "| |   | | |  __)    ( (     ) )    | |   |  |           |  |          | |   ( (     ) )|  __)    | |    | |" << endl;
		cout << "| |   ) | | (        ＼ ＼_/ /     | |   |  |           |  |          | |    ＼ ＼_/ / | (       | |    ) |" << endl;
		cout << "| (__/  ) | (____/＼   ＼   /   ___) (___|  (____/＼ _  |  (____/＼___) (___   ＼   /  | (____/＼| (___/  )" << endl;
		cout << "(______/  (_______ /     ＼/   ＼_______/(_________/( ) (_______/＼________/     ＼/   (________/(_______/ " << endl;
		cout << "                                                    |/                                                    " << endl;
		while(true)
		{
			int a = 0;
			srand((unsigned int)time(NULL));
			a = rand() % 15 + 1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
			gotoxy(0, 10);
			cout << "                                                   ,-." << endl;
			cout << "                              ___,---.__          /'| ＼          __,---,___" << endl;
			cout << "                           ,-'   ＼＼   `-.____,-'  |  `-.____,-'    //    `-." << endl;
			cout << "                         ,'        |           ~'`     /`~           |        `." << endl;
			cout << "                        /      ___//              `. ,'          ,  , `___      ` " << endl;
			cout << "                       |    ,-'   `-.__   _         |        ,    __,-'   `-.    |" << endl;
			cout << "                       |   /          /`_  `   .    |    ,      _/`          `   |" << endl;
			cout << "                       |  |           ＼``-.___＼   |   / ___,-'/ /           |  /" << endl;
			cout << "                       ＼ ＼           | `._   ＼＼ |  //'   _,' |           /  /" << endl;
			cout << "                         `-.`         /'  _ `---'' , . ``---' _  ＼         /,-'" << endl;
			cout << "                            ``       /     ＼   ,='/ ＼`=.    /    ＼       ''" << endl;
			cout << "                                    |__   /|`_,--.,-.--,--._/|`   __|" << endl;
			cout << "                                    /  `./  ```` |  |  | /,//' `,'  ＼ " << endl;
			cout << "                                   /   /     ||--+--|--+-/-|     `   | " << endl;
			cout << "                                  |   |     /'`_`_` | /_/_/``    |   |" << endl;
			cout << "                                   ＼ ＼__, `_     `~'     _/ ._/   /" << endl;
			cout << "                                     '-._,-'  `-._______,-'  `-._,-''" << endl;



			cursor(0);
			cout << endl;
			cout << "                                        <<press any key to start>>" << endl;
			Sleep(1000);

			if (_kbhit())
				break;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\Door_Counterweight.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		system("cls");
		_getch();
int menu = 0;
while (true)
{
	gotoxy(40, 13);
	cout << "┏━━━━━━━━━━━━━┓";
	gotoxy(40, 14);
	cout << "┃      [1] 게임시작        ┃";
	gotoxy(40, 15);
	cout << "┃      [2] 랭    킹        ┃";
	gotoxy(40, 16);
	cout << "┃      [3] 나 가 기        ┃";
	gotoxy(40, 17);
	cout << "┗━━━━━━━━━━━━━┛";
	int menu = _getch() - '0';
	sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
	switch (menu) {
	case 1:
		init();
		showStory(0); //프롤로그 출력
		if (devil(1, 1))//첫번째 귀신 만남
			if (devil(2, 2))//두번째 귀신, 세번째 귀신 만남
				if (devil(4, 3)) {//네번째 귀신, 다섯번째 귀신 만남
					showStory(6);//에필로그 출력
					user.back().setStage(5); //마지막 스테이지를 깼을 때 유저 정보 수정
					outFile << user.back().getInfo() << endl;
				}
		for (int i = 0; i < 3; i++)
			maze[i]->setMaze(0, 0);
		break;
	case 2:
		viewRank();

		system("cls");
		break;
	case 3:
		system("cls");
		cout << "2초 뒤에 종료됩니다..";
		Sleep(2000);
		return;
	default:
		system("cls");
		cout << "다시 입력하세요" << endl;
	}
}
}
void Devil::init() {
	string nickname;
	int character;
	system("cls");
	gotoxy(40, 14);
	cout << "┏━━━━━━━━━━━━━┓";
	gotoxy(40, 15);
	cout << "┃당신의 이름은? :          ┃";
	gotoxy(40, 16);
	cout << "┗━━━━━━━━━━━━━┛";
	gotoxy(59, 15);
	cin >> nickname;
	sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
	system("cls");
	gotoxy(40, 11);
	cout << "┏━━━━━━━━━━━━━┓";
	gotoxy(40, 12);
	cout << "┃      [1] 강 범 석        ┃";
	gotoxy(40, 13);
	cout << "┃      [2] 박 범 수        ┃";
	gotoxy(40, 14);
	cout << "┃      [3] 성 기 은        ┃";
	gotoxy(40, 15);
	cout << "┃      [4] 최 승 연        ┃";
	gotoxy(40, 16);
	cout << "┗━━━━━━━━━━━━━┛";
	gotoxy(40, 17);
	cout << " 캐릭터 선택 : ";
	
	cin >> character;
	sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
	switch (character) {
	case 1:
		sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\범석1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		system("cls");
		cout << "		       ," << endl;
		cout << "            ,:' `..;" << endl;
		cout << "            `. ,;;'%" << endl;
		cout << "            +;;'%%%%%" << endl;
		cout << "             /- %,)%%" << endl;
		cout << "             `  ＼ %%" << endl;
		cout << "              =  )/ ＼" << endl;
		cout << "              `-'/ / ＼" << endl;
		cout << "                /＼/.-＼" << endl;
		cout << "               |  (    |" << endl;
		cout << "               |  |   ||" << endl;
		cout << "               |  |   ||" << endl;
		cout << "           _.-----'   ||" << endl;
		cout << "          /＼________,'|" << endl;
		cout << "         (((/  |       |" << endl;
		cout << "         //    |       |" << endl;
		cout << "        //     |＼     |" << endl;
		cout << "       //      | ＼    |" << endl;
		cout << "      //       |  ＼   |" << endl;
		cout << "     //        |   ＼  |" << endl;
		cout << "    //         |    ＼ |" << endl;
		cout << "   //          |    |＼|" << endl;
		cout << "  //           |    |＼|" << endl;
		cout << " //            ＼   ＼" << endl;
		cout << "c'             |＼   ＼" << endl;
		cout << "               | ＼   ＼" << endl;
		cout << "               |  ＼   ＼" << endl;
		cout << "               |.' ＼   ＼" << endl;
		cout << "              _＼    ＼.-'＼" << endl;
		cout << "             (___.-(__.'＼/" << endl;

	gotoxy(50, 13);
	cout << "┏━━━━━━━━━━━━━┓";
	gotoxy(50, 14);
	cout << "┃   [캐릭터명] 강 범 석    ┃";
	gotoxy(50, 15);
	cout << "┃[성격]겉으로는 강한척하나,┃";
	gotoxy(50, 16);
	cout << "┃ 알고보면 겁이 많은 편이다┃";
	gotoxy(50, 17);
	cout << "┗━━━━━━━━━━━━━┛";
	gotoxy(50, 18);
	cout << " press any key to continue...";
	if (_getch()) {
		
		system("cls");
	}
		break;
	case 2:
		system("cls");
		sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\범수1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		cout << "      ////^＼＼" << endl;
		cout << "      | ^   ^ |" << endl;
		cout << "     @ (o) (o) @" << endl;
		cout << "      |   <   |" << endl;
		cout << "      |  ___  |" << endl;
		cout << "       ＼____/" << endl;
		cout << "     ____|  |___" << endl;
		cout << "    /    ＼_/   ＼" << endl;
	    cout << "   /              ＼" << endl;
		cout << "  /＼/|        |＼ /＼" << endl;
		cout << " / /  |        |  ＼ ＼" << endl;
		cout << "( <   |        |   >  )" << endl;
		cout << "＼＼  |        |  /  /" << endl;
		cout << "  ＼＼|________| /  /" << endl;
		cout << "    ＼|<I_D_I__|/  /" << endl;
		cout << "      |/ I ＼  / /" << endl;
		cout << "      | /  I  ＼|" << endl;
		cout << "      |         |" << endl;
		cout << "      |    |    |" << endl;
		cout << "      |    |    |" << endl;
		cout << "      |    |    |" << endl;
		cout << "      |    |    |" << endl;
		cout << "      | ## | ## |" << endl;
		cout << "      |    |    |" << endl;
		cout << "      |    |    |" << endl;
		cout << "      |____|____|" << endl;
		cout << "      (____(____)" << endl;
		cout << "       _| | _| |" << endl;
		cout << "   cccC__Cccc___)" << endl;
		
		gotoxy(50, 13);
		cout << "┏━━━━━━━━━━━━━┓";
		gotoxy(50, 14);
		cout << "┃   [캐릭터명] 박 범 수    ┃";
		gotoxy(50, 15);
		cout << "┃   [성격] 적극적이나,     ┃";
		gotoxy(50, 16);
		cout << "┃   겁이 지나치게 많다.    ┃";
		gotoxy(50, 17);
		cout << "┗━━━━━━━━━━━━━┛";
		gotoxy(50, 18);
		cout << " press any key to continue...";
		if (_getch()) {
		
			system("cls");
		}
		break;
	case 3:
		system("cls");
		sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\기은1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		cout << "              ., _" << endl;
		cout << "             /    `" << endl;
		cout << "            ((|)))))" << endl;
		cout << "            ((/ a a" << endl;
		cout << "            )))   >)" << endl;
		cout << "           ((((._e((" << endl;
		cout << "          ,--/ (-." << endl;
		cout << "         /＼<＼/>/|" << endl;
		cout << "        / /)  Lo )|" << endl;
		cout << "       / / )    / |" << endl;
		cout << "      |   /    ( /" << endl;
		cout << "      |  /     ;/" << endl;
		cout << "      ||(      |" << endl;
		cout << "     / )|/|    | " << endl;
		cout << "    |/'/＼_____＼" << endl;
		cout << "          ＼   | ＼" << endl;
		cout << "           ＼  |＼ ＼" << endl;
		cout << "            |  | )  )" << endl;
		cout << "            )  )/  /" << endl;
		cout << "           /  /   /" << endl;
		cout << "          /   |  /" << endl;
		cout << "         /    | /" << endl;
		cout << "        /     ||" << endl;
		cout << "       /      ||" << endl;
		cout << "        '-,_  |_＼" << endl;
		cout << "          ( ''''-`' " << endl;
		cout << "           ＼(＼_＼" << endl;

		gotoxy(50, 13);
		cout << "┏━━━━━━━━━━━━━┓";
		gotoxy(50, 14);
		cout << "┃   [캐릭터명] 성 기 은    ┃";
		gotoxy(50, 15);
		cout << "┃ [성격] 소심할 것 같지만, ┃";
		gotoxy(50, 16);
		cout << "┃ 그 누구보다도 패기넘친다 ┃";
		gotoxy(50, 17);
		cout << "┗━━━━━━━━━━━━━┛";
		gotoxy(50, 18);
		cout << " press any key to continue...";
		if (_getch()) {
			
			system("cls");
		}
		break;
	case 4:
		system("cls");
		sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\승연1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		cout << "           ____  " << endl;
		cout << "         /((   ))" << endl;
		cout << "        ( )6  6( )" << endl;
		cout << "        (_)  l (_)" << endl;
		cout << "          ( <> )" << endl;
		cout << "      _____)  (_____" << endl;
		cout << "     (  ＼      /   )" << endl;
		cout << "     )  ,＼ |  /  ` (" << endl;
		cout << "    / /(    Y     )＼＼" << endl;
		cout << "   / /   `     ,'   | )" << endl;
		cout << "   ＼＼   )===(    / /" << endl;
		cout << "    ＼＼ ,     `  / /" << endl;
		cout << "     '＼/       ＼//'" << endl;
		cout << "     '|＼`     '|＼`" << endl;
		cout << "        ＼      /" << endl;
		cout << "         ＼    /" << endl;
		cout << "          )    (" << endl;
		cout << "         /     ＼" << endl;
		cout << "        /       ＼ " << endl;
		cout << "       /         ＼" << endl;
		cout << "      /           ＼ " << endl;
		cout << "     /             ＼" << endl;
		cout << "    /               ＼" << endl;
		cout << "    `-....,      ,..-'" << endl;
		cout << "           `-..-'" << endl;
		
		gotoxy(50, 13);
		cout << "┏━━━━━━━━━━━━━┓";
		gotoxy(50, 14);
		cout << "┃   [캐릭터명] 최 승 연    ┃";
		gotoxy(50, 15);
		cout << "┃   [성격] 용기가 남달라,  ┃";
		gotoxy(50, 16);
		cout << "┃  귀신조차도 달아나게한다 ┃";
		gotoxy(50, 17);
		cout << "┗━━━━━━━━━━━━━┛";
		gotoxy(50, 18);
		cout << " press any key to continue...";
		if (_getch()) {
			
			system("cls");
		}
		break;
	default:
		break;
	}
	user.push_back(User(nickname,character));
	system("cls");
}

void Devil::viewRank() {
	system("cls");
	vector<string> name;
	vector<string> stage;
	string line;
	int temp = 0;
	ifstream inputFile("User.txt"); //User.txt에 있는 데이터 불러오기
	while (true) {
		if (inputFile.eof())
			break;
		getline(inputFile, line);
		name.push_back(line.substr(0, line.find(' ')));//빈칸을 기준으로 앞부분을 name 벡터에 넣기
		stage.push_back(line.substr(line.rfind(' ') + 1, line.size() - name.at(name.size() - 1).size()));//빈칸을 기준으로 뒷부분을 stage 벡터에 넣기
	}

	for (int i = 0; i < stage.size(); i++) { //높은 스테이지 클리어한 순서대로 정렬
		for (int j = 0; j < stage.size() - 1; j++) {
			if (stage.at(j) < stage.at(j + 1)) {
				string tS = stage.at(j);
				stage.at(j) = stage.at(j + 1);
				stage.at(j + 1) = tS;
				string tN = name.at(j);
				name.at(j) = name.at(j + 1);
				name.at(j + 1) = tN;

			}
		}

	}
	gotoxy(42, 3);
	cout << "<********** 랭킹 **********>" << endl;
	gotoxy(42, 5);
	cout << "   닉네임        스테이지" << endl;
	for (int i = 0; i < name.size(); i++) {
		gotoxy(45, 7+i);
		cout << name.at(i);
		gotoxy(60, 7 + i);
		cout << stage.at(i);
		cout << endl;
		temp = i;
	}
	gotoxy(45, 10 + temp);
	cout << "뒤로가기..(Enter)";
	_getch();
}
void Devil::showStory(int story) {
	if (story == 0) //프롤로그 출력
	{
		gotoxy(32, 12);
		cout << "┏━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(32, 13);
		cout << "┃나는 폐병동에 일종의 호기심으로 들어왔다┃";
		gotoxy(32, 14);
		cout << "┃일종의 호기심이였다.                    ┃";
		gotoxy(32, 15);
		cout << "┃그저 탐험이 해보고 싶었을  뿐이다.      ┃";
		gotoxy(32, 16);
		cout << "┗━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(32, 17);
		cout << " press any key to continue..." << endl;
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(31, 12);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(31, 13);
		cout << "┃그치만 내가 생각한 탐험은 이런게 아니였다 ┃";
		gotoxy(31, 14); 
		cout << "┃무언가 이상하다.                          ┃";
		gotoxy(31, 15); 
		cout << "┃무언가 이상한 것들이 나를 덮쳐왔다.       ┃";
		gotoxy(31, 16);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(31, 17);
		cout << " press any key to continue..." << endl;
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(15, 12);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(15, 13);
		cout << "┃폐병동에 있는 한 맺힌 간호사귀신들 그리고 의사귀신들이 내가 들어온 문을 막고┃";
		gotoxy(15, 14);
		cout << "┃병원의 유일한 탈출구인 옥상으로 가는 길을 가로막았다.                       ┃";
		gotoxy(15, 15);
		cout << "┃이곳에 갇힌지 6일째, 인간이 아무런 물과 식량없이 버틸수 있는 날은           ┃";
		gotoxy(15, 16);
		cout << "┃단 하루 남았다.                                                             ┃";
		gotoxy(15, 17);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(15, 18);
		cout << " press any key to continue..." << endl;
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(30, 12);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(30, 13);
		cout << "┃이제는 탈출해야만 한다, 내가 살기 위해선.       ┃";
		gotoxy(30, 14);
		cout << "┃유일한 탈출구인 옥상으로 어떻게든 가야만한다……┃";
		gotoxy(30, 15);
		cout << "┃발걸음을 뗀다.                                  ┃";
		gotoxy(30, 16);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(30, 17);
		cout << " press any key to ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "[ESCAPE]";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}

	}
	else if (story == 1)
	{
		gotoxy(30, 11);
		cout << "#환각, 그 첫번쨰 기억 : 부모";
		gotoxy(30, 12);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(30, 13);
		cout << "┃나 : 엄마..저기... 오늘 소풍가면 안돼요... ?    ┃";
		gotoxy(30, 14);
		cout << "┃엄마 : 내가 지금 너랑 놀아줄 시간이 어딨니!?    ┃";
		gotoxy(30, 15);
		cout << "┃나 : 그래도...다른 친구들은....                 ┃";
		gotoxy(30, 16);
		cout << "┃엄마 : 아휴 내가 너만 안 낳았어도....           ┃";
		gotoxy(30, 17);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(30, 18);
		cout << " '누구 얘기지..? 일단 무시하고 지나가야겠어..'";
		gotoxy(30, 24);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(30, 25);
		cout << "┃   [기억] 이 20 % 돌아왔습니다...계속(ENTER)    ┃";
		gotoxy(30, 26);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━┛";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		Sleep(5000);
	}
	else if (story == 2)
	{
		gotoxy(30, 11);
		cout << "#환각, 그 두번쨰 기억 : 친구";
		gotoxy(30, 12);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(30, 13);
		cout << "┃나 : 대체 나한테 왜이러는건데...                    ┃";
		gotoxy(30, 14);
		cout << "┃친구들 : 그동안 나라도 친구로 남았줬던 걸 고마워해라┃";
		gotoxy(30, 15);
		cout << "┃나 : 내 말도 좀 들어줘...                           ┃";
		gotoxy(30, 16);
		cout << "┃친구들 : 부모 없는 놈을 이해하려고 한 내가 미쳤지   ┃";
		gotoxy(30, 17);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(30, 18);
		cout << " '뭔가 비슷한 기억이 나는 것 같은데...일단 더 가보자'";
		gotoxy(30, 24);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(30, 25);
		cout << "┃   [기억] 이 40 % 돌아왔습니다...계속(ENTER)    ┃";
		gotoxy(30, 26);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━┛";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 3)
	{
		gotoxy(15, 11);
		cout << "#환각, 그 세번쨰 기억 : 학교";
		gotoxy(15, 12);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(15, 13);
		cout << "┃나 : 선생님...부르셨다고하셔서요..                                          ┃";
		gotoxy(15, 14);
		cout << "┃선생님 :(인상을 찌푸리며) 왔니 ? 너 요즘 애들사이에서 말이 많다?            ┃";
		gotoxy(15, 15);
		cout << "┃나 : 그게...친구들이 자꾸 저를....                                          ┃";
		gotoxy(15, 16);
		cout << "┃선생님 : 친구들 탓하지 말고 네가 한 행동들을 되돌아보렴,                    ┃";
		gotoxy(15, 17);
		cout << "┃         다른 친구들 말로는 네가 문제라던데 ?                               ┃";
		gotoxy(15, 18);
		cout << "┃         그렇지 않고서야 잘 지내던 친구들이 갑자기 등을 돌릴겠니? 녀석 참.. ┃";
		gotoxy(15, 19);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(15, 20);
		cout << " '내가 학교에 다녔을 떄도 비슷한 일이 일어났던 것 같은데...더 가볼까...'";
		gotoxy(30, 24);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(30, 25);
		cout << "┃   [기억] 이 60 % 돌아왔습니다...계속(ENTER)    ┃";
		gotoxy(30, 26);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━┛";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 4)
	{
		gotoxy(15, 11);
		cout << "#환각, 그 네번쨰 기억 : 회사";
		gotoxy(15, 12);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(15, 13);
		cout << "┃나 : 부장님 아까 말씀하신 결재 서류입니다...                                ┃";
		gotoxy(15, 14);
		cout << "┃부장님 : 시킨지가 언젠데 이제야 가져와? 장난하나 자네?                      ┃";
		gotoxy(15, 15); 
		cout << "┃나 : 하지만 어제 부장님께서 오늘까지..                                      ┃";
		gotoxy(15, 16);
		cout << "┃부장님 : 거참..하나는 알고 둘은 모르는군, 이 회사가 그렇게 만만한가?        ┃";
		gotoxy(15, 17);
		cout << "┃        대체 할 줄 아는게 뭔가? 이런 인간이 어떻게 여길 들어왔는지 참..어휴 ┃";
		gotoxy(15, 18);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(15, 19);
		cout << " '어라..? 되게 최근에 내가 회사에서 겪은일이잖아 이게 갑자기 왜...?'";
		gotoxy(30, 24);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(30, 25);
		cout << "┃   [기억] 이 80 % 돌아왔습니다...계속(ENTER)    ┃";
		gotoxy(30, 26);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━┛";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 5)
	{
		gotoxy(15, 11);
		cout << "#환각, 그 다섯번쨰 기억 : 사랑";
		gotoxy(15, 12);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(15, 13);
		cout << "┃나 : 지수야 많이 기다렸지!! 내가 좀 늦었다 미안해, 많이 기다렸어??            ┃";
		gotoxy(15, 14);
		cout << "┃애인 : ....저기..있잖아..                                                     ┃";
		gotoxy(15, 15);
		cout << "┃나 : 갑자기 여기까지 무슨 일이야 ?? 오늘 야근한다며, 내일 만나기로 했잖아~    ┃";
		gotoxy(15, 16);
		cout << "┃애인 : 너한테 오늘 할 말 있어서 왔어                                          ┃";
		gotoxy(15, 17);
		cout << "┃나 : 응? 왜...뭔데 그래? 말해봐                                               ┃";
		gotoxy(15, 18);			
		cout << "┃애인 : 이젠 도저히 못 참겠어. 매번 네 행동이 무섭고 무슨 짓을 할 지 두려워    ┃";
		gotoxy(15, 19);
		cout << "┃       너랑 있으면 행복한게 아니라, 피가 마르는 것 같아..그만하자..나 갈게..  ┃";
		gotoxy(15, 20);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(15, 21);
		cout << " '지원이...?이건 완전히 내 얘기잖아....대체 왜 이런 기억들이 떠오르는거냐고!!!'";
		gotoxy(30, 24);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(30, 25);
		cout << "┃   [기억] 이 100 % 돌아왔습니다...계속(ENTER)   ┃";
		gotoxy(30, 26);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━┛";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 6) //에필로그 출력
	{
		if (user.back().getCharacter() == 1)
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\범석4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		else if (user.back().getCharacter() == 2)
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\범수4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		else if (user.back().getCharacter() == 3)
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\기은4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		else if (user.back().getCharacter() == 4)
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\승연4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		gotoxy(15, 13);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(15, 14);
		cout << "┃  난 탈출했다.지긋지긋한 이곳으로부터.어서 뛰어내려서 여길 나가야겠다.  ┃";
		gotoxy(15, 15);
		cout << "┃  4층이니까 크게 다치지 않겠지, , , !                                   ┃";
		gotoxy(15, 16);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━ㅋ━━━━━━━━━━━━┛";
		gotoxy(90, 29);
		cout << "...계속(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		bgmpause();
		sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\glass.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		system("color 44");
		Sleep(4000);
		system("color 07");
		bgm2start();

		gotoxy(28, 13);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(28, 14);
		cout << "┃    편하다..내 모든 기억들이 되돌아 오는 듯 싶었다.   ┃";
		gotoxy(28, 15);
		cout << "┃                                                      ┃";
		gotoxy(28, 16);
		cout << "┃     그런데 문득 무언가 이상한 의문이 들었다.         ┃";
		gotoxy(28, 17);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(90, 29);
		cout << "...계속(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}

		gotoxy(15, 11);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(15, 12);
		cout << "┃    난 왜 굳이 폐병동에 들어온건지 왜 이곳에 끌리듯 오게된거지..?                 ┃";
		gotoxy(15, 13);
		cout << "┃    난 분명 호기심이였다.호기심에 탐험을 하려했는데… ?                           ┃";
		gotoxy(15, 14);
		cout << "┃    그렇지만 내 머리는 다른 장면을 기억한다.                                      ┃";
		gotoxy(15, 15);
		cout << "┃    누군가 나를 강제로 이곳으로 끌고왔다.                                         ┃";
		gotoxy(15, 16);
		cout << "┃    어쩌면 호기심의 방문이 아니라 강제적인 입원이었을지도 모른다는 생각이 들었다. ┃";
		gotoxy(15, 17);
		cout << "┃    잘 모르겠다.더 예전을 기억해보자.혹시 다른 기억이 날 수도 있으니깐.           ┃";
		gotoxy(15, 18);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(90, 29);
		cout << "...계속(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(15, 11);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(15, 12);
		cout << "┃ 그렇다 나는 어려서부터 부모님께 미움을 받았다 자식이 아닌 짐승처럼 다뤄졌다...   ┃";
		gotoxy(15, 13);
		cout << "┃ 학교에서는 친구들의 구타와 왕따 그리고 겨우 독립의 빛 한줄기만 바라보며 살아온   ┃";
		gotoxy(15, 14);
		cout << "┃ 내가 들어간 직장에서 당한 직장상사의 폭행과 폭언..나는 그렇게 미쳐가며 자랐다.   ┃";
		gotoxy(15, 15);
		cout << "┃ 나는 결국 우울증을 앓았다. 약이 없인 생활이 불가능해졌고 나는 점점 미쳐갔다.     ┃";
		gotoxy(15, 16);
		cout << "┃ 주변사람들에게도 피해를 주기 시작했고 주변사람들은 하나둘씩 나를 떠나갔다.       ┃";
		gotoxy(15, 17);
		cout << "┃ 이대로는 안된다 나는 사회에서 격리되어야한다고 판단했다.                         ┃";
		gotoxy(15, 18);
		cout << "┃ 이전에 알아봤던 정신병원 번호로 전화를 걸었다…….여보세요....                   ┃";
		gotoxy(15, 19);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(90, 29);
		cout << "...계속(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		system("color 17");
		bgmpause();
		bgm1start();
		gotoxy(15, 11);
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
		gotoxy(15, 12);
		cout << "┃ 환각 속 내가 탈출구라고 믿었던 것은 결국 나를 죽음으로 몰아넣는 곳이었다.        ┃";
		gotoxy(15, 13);
		cout << "┃ 아니 어쩌면 죽음이 나에게로 조여오는 고틍들로부터 유일한 탈출구 였을지도 모른다. ┃";
		gotoxy(15, 14);
		cout << "┃ 하지만 그것은 단순한 '죽음' 자체가 아니다. 나의 암울했던 과거를 되돌아보고,      ┃";
		gotoxy(15, 15);
		cout << "┃ 이제는 진정한 자유를 얻게된 것이 아닐까.                                         ┃";
		gotoxy(15, 16);
		cout << "┃ 어둡기만 했던 내 삶에, 마침내 한줄기 빛이 들어온 듯한 기분이다.                  ┃";
		gotoxy(15, 17);
		cout << "┃                                                                                  ┃";
		gotoxy(15, 18);
		cout << "┃ 점점 몸에 기운이 빠져간다...이젠 편하다...                                       ┃";
		gotoxy(15, 19);
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
		gotoxy(90, 29);
		cout << "...계속(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("color07");
			system("cls");
			ending();
		}
		
	}
	
	system("cls");
}
void Devil::showghost(bool a) {
	if (a == true) {
		gotoxy(45, 0);
		cout << "                 __" << endl;
		gotoxy(45, 1);
		cout << "                | +| " << endl;
		gotoxy(45, 2);
		cout << "             ,,,|__| " << endl;
		gotoxy(45, 3);
		cout << "             $$$ , ,  ┏━━━━━━━━━━━━━┓ " << endl;
		gotoxy(45, 4);
		cout << "            $$C    >  ┃ 간호사(귀신) : 환자분... ┃" << endl;
		gotoxy(45, 5);
		cout << "           $$$;  _<   ┗━━━━━━━━━━━━━┛" << endl;
		gotoxy(45, 6);
		cout << "       _______/ /_    " << endl;
		gotoxy(45, 7);
		cout << "      |  |__`＼~/o＼ _,]-]___]----->" << endl;
		gotoxy(45, 8);
		cout << "      | / ＼(  )  )＼-//  " << endl;
		gotoxy(45, 9);
		cout << "     _( ＼ )    / ＼ '|  " << endl;
		gotoxy(45, 10);
		cout << "      //| /   ,/   ＼/    " << endl;
		gotoxy(45, 11);
		cout << "        '/   o ＼        " << endl;
		gotoxy(45, 12);
		cout << "        /     o ＼         " << endl;
		gotoxy(45, 13);
		cout << "       /______/＼＼         " << endl;
		gotoxy(45, 14);
		cout << "       ＼  ||   /" << endl;
		gotoxy(45, 15);
		cout << "        ＼ ||  /" << endl;
		gotoxy(45, 16);
		cout << "         ＼|| /" << endl;
		gotoxy(45, 17);
		cout << "         / )( ＼" << endl;
		gotoxy(45, 18);
		cout << "         |/  '|" << endl;
		gotoxy(45, 19);
		cout << "         :]  [:" << endl;
		gotoxy(45, 20);
		cout << "         o|  |o" << endl;
		gotoxy(45, 21);
		cout << "        /o|  |o＼" << endl;
		gotoxy(45, 22);
		cout << "        `-'  `-'" << endl;
		gotoxy(5, 24);
		cout << "                                                                                                           ";
	}
	else {
		gotoxy(45, 5);
		gotoxy(45, 0);
		cout << "                                                    " << endl;
		gotoxy(45, 1);
		cout << "        ||         |||||||||||||||||||   " << endl;
		gotoxy(45, 2);
		cout << "    ____||         |------( + )------| " << endl;
		gotoxy(45, 3);
		cout << "    ＼＼  []       |||||||||||||||||||" << endl;
		gotoxy(45, 4);
		cout << "     ＼___/        |                 |    " << endl;
		gotoxy(45, 5);
		cout << "     |_____|      _|__ __       __ __|_" << endl;
		gotoxy(45, 6);
		cout << "     |     |     ( |  (_o)-/~'-(o_)  | )" << endl;
		gotoxy(45, 7);
		cout << "     |     |      (|      (   )      |) " << endl;
		gotoxy(45, 8);
		cout << "     |     |       |                 |   " << endl;
		gotoxy(45, 9);
		cout << "     |     |_______|    /      ＼    |_________ " << endl;
		gotoxy(45, 10);
		cout << "     |     |        ＼    _____     /          ＼" << endl;
		gotoxy(45, 11);
		cout << "     |     |         ＼  (_____)   /            ＼ " << endl;
		gotoxy(45, 12);
		cout << "     |     |          ＼__________/              |" << endl;
		gotoxy(45, 13);
		cout << "     |     |    |      |||||||||||               |" << endl;
		gotoxy(45, 14);
		cout << "     |     /   /        |||||||||       |        |" << endl;
		gotoxy(45, 15);
		cout << "     |        /          |||||||        |        |" << endl;
		gotoxy(45, 16);
		cout << "     |       /              {o          |        |" << endl;
		gotoxy(45, 17);
		cout << "     ＼_____/               {o          |        |" << endl;
		gotoxy(45, 18);
		cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
		gotoxy(45, 19);
		cout << " ┃정신과 의사(귀신) : 화,,환..자분, 움직이면 안돼요.┃" << endl;
		gotoxy(45, 20);
		cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
		gotoxy(5, 24);
		cout << "                                                                                                           ";
	}
gn = !a;
}

bool Devil::devil(int game, int floor) {
	bgmpause();
	bgm2start();
	maze[floor - 1]->show();
	
	while (true) {
		maze[floor - 1]->moveCursor();
		if (maze[floor - 1]->checkDevil()) { //귀신을 만났는지 판단
			system("cls");
			if (user.back().getCharacter() == 1)
				sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\범석3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 2)
				sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\범수3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 3)
				sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\기은3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 4)
				sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\승연3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			showghost(gn);
			if (!tetrix.start(game - 1)) { //테트리스 실행, 클리어하면 true를 반환
				user.back().setStage(game-1);
				outFile << user.at(user.size() - 1).getInfo() << endl; //사용자의 닉네임과 클리어한 스테이지 저장
				
				return false;
			}
			system("cls");
			showStory(game); 
			system("cls");
			maze[floor - 1]->show();//테트리스를 클리어하고 미로(폐병동) 재출력
			if (game == 2||game==4) //2층, 3층에선 귀신을 두 번 만나므로, 층 수는 유지한채, 게임 스테이지만 +1 해줌
				game++;
			
			continue;
		}
		if (maze[floor - 1]->checkWin()) //탈출구에 도달했는지 판단 true: 도달안함 false: 도달함
		{
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\Door_Shack", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			return true;
		}
		int a = 0;
		srand((unsigned int)time(NULL));
		a = rand() % 8 + 1;
		switch (a) {
		case 1:
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\squeaky.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			break;
		case 2:
			if (user.back().getCharacter() == 1)
				sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\범석2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 2)
				sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\범수2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 3)
				sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\기은2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 4)
				sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\승연2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			break;
		default:
			break;
		}

	}
}


void Devil::ending()
{
	
		gotoxy(0, 5);
		cout << "                                                   ,-." << endl;
		cout << "                              ___,---.__          /'| ＼          __,---,___" << endl;
		cout << "                           ,-'   ＼＼   `-.____,-'  |  `-.____,-'    //    `-." << endl;
		cout << "                         ,'        |           ~'`     /`~           |        `." << endl;
		cout << "                        /      ___//              `. ,'          ,  , `___      ` " << endl;
		cout << "                       |    ,-'   `-.__   _         |        ,    __,-'   `-.    |" << endl;
		cout << "                       |   /          /`_  `   .    |    ,      _/`          `   |" << endl;
		cout << "                       |  |           ＼``-.___＼   |   / ___,-'/ /           |  /" << endl;
		cout << "                       ＼ ＼           | `._   ＼＼ |  //'   _,' |           /  /" << endl;
		cout << "                         `-.`         /'  _ `---'' , . ``---' _  ＼         /,-'" << endl;
		cout << "                            ``       /     ＼   ,='/ ＼`=.    /    ＼       ''" << endl;
		cout << "                                    |__   /|`_,--.,-.--,--._/|`   __|" << endl;
		cout << "                                    /  `./  ```` |  |  | /,//' `,'  ＼ " << endl;
		cout << "                                   /   /     ||--+--|--+-/-|     `   | " << endl;
		cout << "                                  |   |     /'`_`_` | /_/_/``    |   |" << endl;
		cout << "                                   ＼ ＼__, `_     `~'     _/ ._/   /" << endl;
		cout << "                                     '-._,-'  `-._______,-'  `-._,-''" << endl;



		cursor(0);
		cout << endl;
		cout << "                                          DO NOT DIE, SURVIVE" << endl;
		if (_getch()) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			sndPlaySoundA("C:\\Users\\최승연\\Desktop\\Project6\\Project6\\Project6\\Door_Counterweight.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
}
