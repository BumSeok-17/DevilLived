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
	mciOpen.lpstrElementName = "HORROR Background Music.mp3"; // ���� ��� �Է�
	mciOpen.lpstrDeviceType = "mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
		(DWORD)(LPVOID)&m_mciPlayParms);
}

void Devil::bgm2start() {
	mciOpen.lpstrElementName = "mazebgm.mp3"; // ���� ��� �Է�
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
		cout << "(  __  �� (  ____ ��|��      /|��__   __/( ��           ( ��      ��__   __/|��      /|(  _____��(  __  �� " << endl;
		cout << "| (  �� ) | (    ��/| )     ( |    ) (   |  (           |  (          ) (   | )     ( || (    ��/| (  ��  )" << endl;
		cout << "| |   ) | | (__     | |     | |    | |   |  |           |  |          | |   | |     | || (__     | |    ) |" << endl;
		cout << "| |   | | |  __)    ( (     ) )    | |   |  |           |  |          | |   ( (     ) )|  __)    | |    | |" << endl;
		cout << "| |   ) | | (        �� ��_/ /     | |   |  |           |  |          | |    �� ��_/ / | (       | |    ) |" << endl;
		cout << "| (__/  ) | (____/��   ��   /   ___) (___|  (____/�� _  |  (____/��___) (___   ��   /  | (____/��| (___/  )" << endl;
		cout << "(______/  (_______ /     ��/   ��_______/(_________/( ) (_______/��________/     ��/   (________/(_______/ " << endl;
		cout << "                                                    |/                                                    " << endl;
		while(true)
		{
			int a = 0;
			srand((unsigned int)time(NULL));
			a = rand() % 15 + 1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
			gotoxy(0, 10);
			cout << "                                                   ,-." << endl;
			cout << "                              ___,---.__          /'| ��          __,---,___" << endl;
			cout << "                           ,-'   ����   `-.____,-'  |  `-.____,-'    //    `-." << endl;
			cout << "                         ,'        |           ~'`     /`~           |        `." << endl;
			cout << "                        /      ___//              `. ,'          ,  , `___      ` " << endl;
			cout << "                       |    ,-'   `-.__   _         |        ,    __,-'   `-.    |" << endl;
			cout << "                       |   /          /`_  `   .    |    ,      _/`          `   |" << endl;
			cout << "                       |  |           ��``-.___��   |   / ___,-'/ /           |  /" << endl;
			cout << "                       �� ��           | `._   ���� |  //'   _,' |           /  /" << endl;
			cout << "                         `-.`         /'  _ `---'' , . ``---' _  ��         /,-'" << endl;
			cout << "                            ``       /     ��   ,='/ ��`=.    /    ��       ''" << endl;
			cout << "                                    |__   /|`_,--.,-.--,--._/|`   __|" << endl;
			cout << "                                    /  `./  ```` |  |  | /,//' `,'  �� " << endl;
			cout << "                                   /   /     ||--+--|--+-/-|     `   | " << endl;
			cout << "                                  |   |     /'`_`_` | /_/_/``    |   |" << endl;
			cout << "                                   �� ��__, `_     `~'     _/ ._/   /" << endl;
			cout << "                                     '-._,-'  `-._______,-'  `-._,-''" << endl;



			cursor(0);
			cout << endl;
			cout << "                                        <<press any key to start>>" << endl;
			Sleep(1000);

			if (_kbhit())
				break;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\Door_Counterweight.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		system("cls");
		_getch();
int menu = 0;
while (true)
{
	gotoxy(40, 13);
	cout << "������������������������������";
	gotoxy(40, 14);
	cout << "��      [1] ���ӽ���        ��";
	gotoxy(40, 15);
	cout << "��      [2] ��    ŷ        ��";
	gotoxy(40, 16);
	cout << "��      [3] �� �� ��        ��";
	gotoxy(40, 17);
	cout << "������������������������������";
	int menu = _getch() - '0';
	sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
	switch (menu) {
	case 1:
		init();
		showStory(0); //���ѷα� ���
		if (devil(1, 1))//ù��° �ͽ� ����
			if (devil(2, 2))//�ι�° �ͽ�, ����° �ͽ� ����
				if (devil(4, 3)) {//�׹�° �ͽ�, �ټ���° �ͽ� ����
					showStory(6);//���ʷα� ���
					user.back().setStage(5); //������ ���������� ���� �� ���� ���� ����
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
		cout << "2�� �ڿ� ����˴ϴ�..";
		Sleep(2000);
		return;
	default:
		system("cls");
		cout << "�ٽ� �Է��ϼ���" << endl;
	}
}
}
void Devil::init() {
	string nickname;
	int character;
	system("cls");
	gotoxy(40, 14);
	cout << "������������������������������";
	gotoxy(40, 15);
	cout << "������� �̸���? :          ��";
	gotoxy(40, 16);
	cout << "������������������������������";
	gotoxy(59, 15);
	cin >> nickname;
	sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
	system("cls");
	gotoxy(40, 11);
	cout << "������������������������������";
	gotoxy(40, 12);
	cout << "��      [1] �� �� ��        ��";
	gotoxy(40, 13);
	cout << "��      [2] �� �� ��        ��";
	gotoxy(40, 14);
	cout << "��      [3] �� �� ��        ��";
	gotoxy(40, 15);
	cout << "��      [4] �� �� ��        ��";
	gotoxy(40, 16);
	cout << "������������������������������";
	gotoxy(40, 17);
	cout << " ĳ���� ���� : ";
	
	cin >> character;
	sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
	switch (character) {
	case 1:
		sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		system("cls");
		cout << "		       ," << endl;
		cout << "            ,:' `..;" << endl;
		cout << "            `. ,;;'%" << endl;
		cout << "            +;;'%%%%%" << endl;
		cout << "             /- %,)%%" << endl;
		cout << "             `  �� %%" << endl;
		cout << "              =  )/ ��" << endl;
		cout << "              `-'/ / ��" << endl;
		cout << "                /��/.-��" << endl;
		cout << "               |  (    |" << endl;
		cout << "               |  |   ||" << endl;
		cout << "               |  |   ||" << endl;
		cout << "           _.-----'   ||" << endl;
		cout << "          /��________,'|" << endl;
		cout << "         (((/  |       |" << endl;
		cout << "         //    |       |" << endl;
		cout << "        //     |��     |" << endl;
		cout << "       //      | ��    |" << endl;
		cout << "      //       |  ��   |" << endl;
		cout << "     //        |   ��  |" << endl;
		cout << "    //         |    �� |" << endl;
		cout << "   //          |    |��|" << endl;
		cout << "  //           |    |��|" << endl;
		cout << " //            ��   ��" << endl;
		cout << "c'             |��   ��" << endl;
		cout << "               | ��   ��" << endl;
		cout << "               |  ��   ��" << endl;
		cout << "               |.' ��   ��" << endl;
		cout << "              _��    ��.-'��" << endl;
		cout << "             (___.-(__.'��/" << endl;

	gotoxy(50, 13);
	cout << "������������������������������";
	gotoxy(50, 14);
	cout << "��   [ĳ���͸�] �� �� ��    ��";
	gotoxy(50, 15);
	cout << "��[����]�����δ� ����ô�ϳ�,��";
	gotoxy(50, 16);
	cout << "�� �˰��� ���� ���� ���̴٦�";
	gotoxy(50, 17);
	cout << "������������������������������";
	gotoxy(50, 18);
	cout << " press any key to continue...";
	if (_getch()) {
		
		system("cls");
	}
		break;
	case 2:
		system("cls");
		sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		cout << "      ////^����" << endl;
		cout << "      | ^   ^ |" << endl;
		cout << "     @ (o) (o) @" << endl;
		cout << "      |   <   |" << endl;
		cout << "      |  ___  |" << endl;
		cout << "       ��____/" << endl;
		cout << "     ____|  |___" << endl;
		cout << "    /    ��_/   ��" << endl;
	    cout << "   /              ��" << endl;
		cout << "  /��/|        |�� /��" << endl;
		cout << " / /  |        |  �� ��" << endl;
		cout << "( <   |        |   >  )" << endl;
		cout << "����  |        |  /  /" << endl;
		cout << "  ����|________| /  /" << endl;
		cout << "    ��|<I_D_I__|/  /" << endl;
		cout << "      |/ I ��  / /" << endl;
		cout << "      | /  I  ��|" << endl;
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
		cout << "������������������������������";
		gotoxy(50, 14);
		cout << "��   [ĳ���͸�] �� �� ��    ��";
		gotoxy(50, 15);
		cout << "��   [����] �������̳�,     ��";
		gotoxy(50, 16);
		cout << "��   ���� ����ġ�� ����.    ��";
		gotoxy(50, 17);
		cout << "������������������������������";
		gotoxy(50, 18);
		cout << " press any key to continue...";
		if (_getch()) {
		
			system("cls");
		}
		break;
	case 3:
		system("cls");
		sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		cout << "              ., _" << endl;
		cout << "             /    `" << endl;
		cout << "            ((|)))))" << endl;
		cout << "            ((/ a a" << endl;
		cout << "            )))   >)" << endl;
		cout << "           ((((._e((" << endl;
		cout << "          ,--/ (-." << endl;
		cout << "         /��<��/>/|" << endl;
		cout << "        / /)  Lo )|" << endl;
		cout << "       / / )    / |" << endl;
		cout << "      |   /    ( /" << endl;
		cout << "      |  /     ;/" << endl;
		cout << "      ||(      |" << endl;
		cout << "     / )|/|    | " << endl;
		cout << "    |/'/��_____��" << endl;
		cout << "          ��   | ��" << endl;
		cout << "           ��  |�� ��" << endl;
		cout << "            |  | )  )" << endl;
		cout << "            )  )/  /" << endl;
		cout << "           /  /   /" << endl;
		cout << "          /   |  /" << endl;
		cout << "         /    | /" << endl;
		cout << "        /     ||" << endl;
		cout << "       /      ||" << endl;
		cout << "        '-,_  |_��" << endl;
		cout << "          ( ''''-`' " << endl;
		cout << "           ��(��_��" << endl;

		gotoxy(50, 13);
		cout << "������������������������������";
		gotoxy(50, 14);
		cout << "��   [ĳ���͸�] �� �� ��    ��";
		gotoxy(50, 15);
		cout << "�� [����] �ҽ��� �� ������, ��";
		gotoxy(50, 16);
		cout << "�� �� �������ٵ� �б��ģ�� ��";
		gotoxy(50, 17);
		cout << "������������������������������";
		gotoxy(50, 18);
		cout << " press any key to continue...";
		if (_getch()) {
			
			system("cls");
		}
		break;
	case 4:
		system("cls");
		sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\�¿�1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		cout << "           ____  " << endl;
		cout << "         /((   ))" << endl;
		cout << "        ( )6  6( )" << endl;
		cout << "        (_)  l (_)" << endl;
		cout << "          ( <> )" << endl;
		cout << "      _____)  (_____" << endl;
		cout << "     (  ��      /   )" << endl;
		cout << "     )  ,�� |  /  ` (" << endl;
		cout << "    / /(    Y     )����" << endl;
		cout << "   / /   `     ,'   | )" << endl;
		cout << "   ����   )===(    / /" << endl;
		cout << "    ���� ,     `  / /" << endl;
		cout << "     '��/       ��//'" << endl;
		cout << "     '|��`     '|��`" << endl;
		cout << "        ��      /" << endl;
		cout << "         ��    /" << endl;
		cout << "          )    (" << endl;
		cout << "         /     ��" << endl;
		cout << "        /       �� " << endl;
		cout << "       /         ��" << endl;
		cout << "      /           �� " << endl;
		cout << "     /             ��" << endl;
		cout << "    /               ��" << endl;
		cout << "    `-....,      ,..-'" << endl;
		cout << "           `-..-'" << endl;
		
		gotoxy(50, 13);
		cout << "������������������������������";
		gotoxy(50, 14);
		cout << "��   [ĳ���͸�] �� �� ��    ��";
		gotoxy(50, 15);
		cout << "��   [����] ��Ⱑ ���޶�,  ��";
		gotoxy(50, 16);
		cout << "��  �ͽ������� �޾Ƴ����Ѵ� ��";
		gotoxy(50, 17);
		cout << "������������������������������";
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
	ifstream inputFile("User.txt"); //User.txt�� �ִ� ������ �ҷ�����
	while (true) {
		if (inputFile.eof())
			break;
		getline(inputFile, line);
		name.push_back(line.substr(0, line.find(' ')));//��ĭ�� �������� �պκ��� name ���Ϳ� �ֱ�
		stage.push_back(line.substr(line.rfind(' ') + 1, line.size() - name.at(name.size() - 1).size()));//��ĭ�� �������� �޺κ��� stage ���Ϳ� �ֱ�
	}

	for (int i = 0; i < stage.size(); i++) { //���� �������� Ŭ������ ������� ����
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
	cout << "<********** ��ŷ **********>" << endl;
	gotoxy(42, 5);
	cout << "   �г���        ��������" << endl;
	for (int i = 0; i < name.size(); i++) {
		gotoxy(45, 7+i);
		cout << name.at(i);
		gotoxy(60, 7 + i);
		cout << stage.at(i);
		cout << endl;
		temp = i;
	}
	gotoxy(45, 10 + temp);
	cout << "�ڷΰ���..(Enter)";
	_getch();
}
void Devil::showStory(int story) {
	if (story == 0) //���ѷα� ���
	{
		gotoxy(32, 12);
		cout << "��������������������������������������������";
		gotoxy(32, 13);
		cout << "������ �󺴵��� ������ ȣ������� ���Դ٦�";
		gotoxy(32, 14);
		cout << "�������� ȣ����̿���.                    ��";
		gotoxy(32, 15);
		cout << "������ Ž���� �غ��� �;���  ���̴�.      ��";
		gotoxy(32, 16);
		cout << "��������������������������������������������";
		gotoxy(32, 17);
		cout << " press any key to continue..." << endl;
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(31, 12);
		cout << "����������������������������������������������";
		gotoxy(31, 13);
		cout << "����ġ�� ���� ������ Ž���� �̷��� �ƴϿ��� ��";
		gotoxy(31, 14); 
		cout << "������ �̻��ϴ�.                          ��";
		gotoxy(31, 15); 
		cout << "������ �̻��� �͵��� ���� ���ĿԴ�.       ��";
		gotoxy(31, 16);
		cout << "����������������������������������������������";
		gotoxy(31, 17);
		cout << " press any key to continue..." << endl;
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(15, 12);
		cout << "��������������������������������������������������������������������������������";
		gotoxy(15, 13);
		cout << "���󺴵��� �ִ� �� ���� ��ȣ��ͽŵ� �׸��� �ǻ�ͽŵ��� ���� ���� ���� ����";
		gotoxy(15, 14);
		cout << "�������� ������ Ż�ⱸ�� �������� ���� ���� ���θ��Ҵ�.                       ��";
		gotoxy(15, 15);
		cout << "���̰��� ������ 6��°, �ΰ��� �ƹ��� ���� �ķ����� ��ƿ�� �ִ� ����           ��";
		gotoxy(15, 16);
		cout << "���� �Ϸ� ���Ҵ�.                                                             ��";
		gotoxy(15, 17);
		cout << "��������������������������������������������������������������������������������";
		gotoxy(15, 18);
		cout << " press any key to continue..." << endl;
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(30, 12);
		cout << "����������������������������������������������������";
		gotoxy(30, 13);
		cout << "�������� Ż���ؾ߸� �Ѵ�, ���� ��� ���ؼ�.       ��";
		gotoxy(30, 14);
		cout << "�������� Ż�ⱸ�� �������� ��Ե� ���߸��Ѵ١�����";
		gotoxy(30, 15);
		cout << "���߰����� ����.                                  ��";
		gotoxy(30, 16);
		cout << "����������������������������������������������������";
		gotoxy(30, 17);
		cout << " press any key to ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "[ESCAPE]";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}

	}
	else if (story == 1)
	{
		gotoxy(30, 11);
		cout << "#ȯ��, �� ù���� ��� : �θ�";
		gotoxy(30, 12);
		cout << "����������������������������������������������������";
		gotoxy(30, 13);
		cout << "���� : ����..����... ���� ��ǳ���� �ȵſ�... ?    ��";
		gotoxy(30, 14);
		cout << "������ : ���� ���� �ʶ� ����� �ð��� �����!?    ��";
		gotoxy(30, 15);
		cout << "���� : �׷���...�ٸ� ģ������....                 ��";
		gotoxy(30, 16);
		cout << "������ : ���� ���� �ʸ� �� ���Ҿ....           ��";
		gotoxy(30, 17);
		cout << "����������������������������������������������������";
		gotoxy(30, 18);
		cout << " '���� �����..? �ϴ� �����ϰ� �������߰ھ�..'";
		gotoxy(30, 24);
		cout << "����������������������������������������������������";
		gotoxy(30, 25);
		cout << "��   [���] �� 20 % ���ƿԽ��ϴ�...���(ENTER)    ��";
		gotoxy(30, 26);
		cout << "����������������������������������������������������";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		Sleep(5000);
	}
	else if (story == 2)
	{
		gotoxy(30, 11);
		cout << "#ȯ��, �� �ι��� ��� : ģ��";
		gotoxy(30, 12);
		cout << "��������������������������������������������������������";
		gotoxy(30, 13);
		cout << "���� : ��ü ������ ���̷��°ǵ�...                    ��";
		gotoxy(30, 14);
		cout << "��ģ���� : �׵��� ���� ģ���� ������� �� �����ض�";
		gotoxy(30, 15);
		cout << "���� : �� ���� �� �����...                           ��";
		gotoxy(30, 16);
		cout << "��ģ���� : �θ� ���� ���� �����Ϸ��� �� ���� ������   ��";
		gotoxy(30, 17);
		cout << "��������������������������������������������������������";
		gotoxy(30, 18);
		cout << " '���� ����� ����� ���� �� ������...�ϴ� �� ������'";
		gotoxy(30, 24);
		cout << "����������������������������������������������������";
		gotoxy(30, 25);
		cout << "��   [���] �� 40 % ���ƿԽ��ϴ�...���(ENTER)    ��";
		gotoxy(30, 26);
		cout << "����������������������������������������������������";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 3)
	{
		gotoxy(15, 11);
		cout << "#ȯ��, �� ������ ��� : �б�";
		gotoxy(15, 12);
		cout << "��������������������������������������������������������������������������������";
		gotoxy(15, 13);
		cout << "���� : ������...�θ��̴ٰ��ϼż���..                                          ��";
		gotoxy(15, 14);
		cout << "�������� :(�λ��� ��Ǫ����) �Դ� ? �� ���� �ֵ���̿��� ���� ����?            ��";
		gotoxy(15, 15);
		cout << "���� : �װ�...ģ������ �ڲ� ����....                                          ��";
		gotoxy(15, 16);
		cout << "�������� : ģ���� ſ���� ���� �װ� �� �ൿ���� �ǵ��ƺ���,                    ��";
		gotoxy(15, 17);
		cout << "��         �ٸ� ģ���� ���δ� �װ� ��������� ?                               ��";
		gotoxy(15, 18);
		cout << "��         �׷��� �ʰ��� �� ������ ģ������ ���ڱ� ���� �����ڴ�? �༮ ��.. ��";
		gotoxy(15, 19);
		cout << "��������������������������������������������������������������������������������";
		gotoxy(15, 20);
		cout << " '���� �б��� �ٳ��� ���� ����� ���� �Ͼ�� �� ������...�� ������...'";
		gotoxy(30, 24);
		cout << "����������������������������������������������������";
		gotoxy(30, 25);
		cout << "��   [���] �� 60 % ���ƿԽ��ϴ�...���(ENTER)    ��";
		gotoxy(30, 26);
		cout << "����������������������������������������������������";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 4)
	{
		gotoxy(15, 11);
		cout << "#ȯ��, �� �׹��� ��� : ȸ��";
		gotoxy(15, 12);
		cout << "��������������������������������������������������������������������������������";
		gotoxy(15, 13);
		cout << "���� : ����� �Ʊ� �����Ͻ� ���� �����Դϴ�...                                ��";
		gotoxy(15, 14);
		cout << "������� : ��Ų���� ������ ������ ������? �峭�ϳ� �ڳ�?                      ��";
		gotoxy(15, 15); 
		cout << "���� : ������ ���� ����Բ��� ���ñ���..                                      ��";
		gotoxy(15, 16);
		cout << "������� : ����..�ϳ��� �˰� ���� �𸣴±�, �� ȸ�簡 �׷��� �����Ѱ�?        ��";
		gotoxy(15, 17);
		cout << "��        ��ü �� �� �ƴ°� ����? �̷� �ΰ��� ��� ���� ���Դ��� ��..���� ��";
		gotoxy(15, 18);
		cout << "��������������������������������������������������������������������������������";
		gotoxy(15, 19);
		cout << " '���..? �ǰ� �ֱٿ� ���� ȸ�翡�� ���������ݾ� �̰� ���ڱ� ��...?'";
		gotoxy(30, 24);
		cout << "����������������������������������������������������";
		gotoxy(30, 25);
		cout << "��   [���] �� 80 % ���ƿԽ��ϴ�...���(ENTER)    ��";
		gotoxy(30, 26);
		cout << "����������������������������������������������������";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 5)
	{
		gotoxy(15, 11);
		cout << "#ȯ��, �� �ټ����� ��� : ���";
		gotoxy(15, 12);
		cout << "����������������������������������������������������������������������������������";
		gotoxy(15, 13);
		cout << "���� : ������ ���� ��ٷ���!! ���� �� �ʾ��� �̾���, ���� ��ٷȾ�??            ��";
		gotoxy(15, 14);
		cout << "������ : ....����..���ݾ�..                                                     ��";
		gotoxy(15, 15);
		cout << "���� : ���ڱ� ������� ���� ���̾� ?? ���� �߱��Ѵٸ�, ���� ������� ���ݾ�~    ��";
		gotoxy(15, 16);
		cout << "������ : ������ ���� �� �� �־ �Ծ�                                          ��";
		gotoxy(15, 17);
		cout << "���� : ��? ��...���� �׷�? ���غ�                                               ��";
		gotoxy(15, 18);			
		cout << "������ : ���� ������ �� ���ھ�. �Ź� �� �ൿ�� ������ ���� ���� �� �� �η���    ��";
		gotoxy(15, 19);
		cout << "��       �ʶ� ������ �ູ�Ѱ� �ƴ϶�, �ǰ� ������ �� ����..�׸�����..�� ����..  ��";
		gotoxy(15, 20);
		cout << "����������������������������������������������������������������������������������";
		gotoxy(15, 21);
		cout << " '������...?�̰� ������ �� ����ݾ�....��ü �� �̷� ������ �������°ųİ�!!!'";
		gotoxy(30, 24);
		cout << "����������������������������������������������������";
		gotoxy(30, 25);
		cout << "��   [���] �� 100 % ���ƿԽ��ϴ�...���(ENTER)   ��";
		gotoxy(30, 26);
		cout << "����������������������������������������������������";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 6) //���ʷα� ���
	{
		if (user.back().getCharacter() == 1)
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		else if (user.back().getCharacter() == 2)
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		else if (user.back().getCharacter() == 3)
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		else if (user.back().getCharacter() == 4)
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\�¿�4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		gotoxy(15, 13);
		cout << "����������������������������������������������������������������������������";
		gotoxy(15, 14);
		cout << "��  �� Ż���ߴ�.���������� �̰����κ���.� �پ���� ���� �����߰ڴ�.  ��";
		gotoxy(15, 15);
		cout << "��  4���̴ϱ� ũ�� ��ġ�� �ʰ���, , , !                                   ��";
		gotoxy(15, 16);
		cout << "����������������������������������������������������������������������������";
		gotoxy(90, 29);
		cout << "...���(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		bgmpause();
		sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\glass.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		system("color 44");
		Sleep(4000);
		system("color 07");
		bgm2start();

		gotoxy(28, 13);
		cout << "����������������������������������������������������������";
		gotoxy(28, 14);
		cout << "��    ���ϴ�..�� ��� ������ �ǵ��� ���� �� �;���.   ��";
		gotoxy(28, 15);
		cout << "��                                                      ��";
		gotoxy(28, 16);
		cout << "��     �׷��� ���� ���� �̻��� �ǹ��� �����.         ��";
		gotoxy(28, 17);
		cout << "����������������������������������������������������������";
		gotoxy(90, 29);
		cout << "...���(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}

		gotoxy(15, 11);
		cout << "��������������������������������������������������������������������������������������";
		gotoxy(15, 12);
		cout << "��    �� �� ���� �󺴵��� ���°��� �� �̰��� ������ ���ԵȰ���..?                 ��";
		gotoxy(15, 13);
		cout << "��    �� �и� ȣ����̿���.ȣ��ɿ� Ž���� �Ϸ��ߴµ��� ?                           ��";
		gotoxy(15, 14);
		cout << "��    �׷����� �� �Ӹ��� �ٸ� ����� ����Ѵ�.                                      ��";
		gotoxy(15, 15);
		cout << "��    ������ ���� ������ �̰����� ����Դ�.                                         ��";
		gotoxy(15, 16);
		cout << "��    ��¼�� ȣ����� �湮�� �ƴ϶� �������� �Կ��̾������� �𸥴ٴ� ������ �����. ��";
		gotoxy(15, 17);
		cout << "��    �� �𸣰ڴ�.�� ������ ����غ���.Ȥ�� �ٸ� ����� �� ���� �����ϱ�.           ��";
		gotoxy(15, 18);
		cout << "��������������������������������������������������������������������������������������";
		gotoxy(90, 29);
		cout << "...���(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(15, 11);
		cout << "��������������������������������������������������������������������������������������";
		gotoxy(15, 12);
		cout << "�� �׷��� ���� ��������� �θ�Բ� �̿��� �޾Ҵ� �ڽ��� �ƴ� ����ó�� �ٷ�����...   ��";
		gotoxy(15, 13);
		cout << "�� �б������� ģ������ ��Ÿ�� �յ� �׸��� �ܿ� ������ �� ���ٱ⸸ �ٶ󺸸� ��ƿ�   ��";
		gotoxy(15, 14);
		cout << "�� ���� �� ���忡�� ���� �������� ����� ����..���� �׷��� ���İ��� �ڶ���.   ��";
		gotoxy(15, 15);
		cout << "�� ���� �ᱹ ������� �ξҴ�. ���� ���� ��Ȱ�� �Ұ��������� ���� ���� ���İ���.     ��";
		gotoxy(15, 16);
		cout << "�� �ֺ�����鿡�Ե� ���ظ� �ֱ� �����߰� �ֺ�������� �ϳ��Ѿ� ���� ��������.       ��";
		gotoxy(15, 17);
		cout << "�� �̴�δ� �ȵȴ� ���� ��ȸ���� �ݸ��Ǿ���Ѵٰ� �Ǵ��ߴ�.                         ��";
		gotoxy(15, 18);
		cout << "�� ������ �˾ƺô� ���ź��� ��ȣ�� ��ȭ�� �ɾ��١���.��������....                   ��";
		gotoxy(15, 19);
		cout << "��������������������������������������������������������������������������������������";
		gotoxy(90, 29);
		cout << "...���(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		system("color 17");
		bgmpause();
		bgm1start();
		gotoxy(15, 11);
		cout << "��������������������������������������������������������������������������������������";
		gotoxy(15, 12);
		cout << "�� ȯ�� �� ���� Ż�ⱸ��� �Ͼ��� ���� �ᱹ ���� �������� ���Ƴִ� ���̾���.        ��";
		gotoxy(15, 13);
		cout << "�� �ƴ� ��¼�� ������ �����Է� �������� ��v��κ��� ������ Ż�ⱸ �������� �𸥴�. ��";
		gotoxy(15, 14);
		cout << "�� ������ �װ��� �ܼ��� '����' ��ü�� �ƴϴ�. ���� �Ͽ��ߴ� ���Ÿ� �ǵ��ƺ���,      ��";
		gotoxy(15, 15);
		cout << "�� ������ ������ ������ ��Ե� ���� �ƴұ�.                                         ��";
		gotoxy(15, 16);
		cout << "�� ��ӱ⸸ �ߴ� �� �, ��ħ�� ���ٱ� ���� ���� ���� ����̴�.                  ��";
		gotoxy(15, 17);
		cout << "��                                                                                  ��";
		gotoxy(15, 18);
		cout << "�� ���� ���� ����� ��������...���� ���ϴ�...                                       ��";
		gotoxy(15, 19);
		cout << "��������������������������������������������������������������������������������������";
		gotoxy(90, 29);
		cout << "...���(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
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
		cout << "             $$$ , ,  ������������������������������ " << endl;
		gotoxy(45, 4);
		cout << "            $$C    >  �� ��ȣ��(�ͽ�) : ȯ�ں�... ��" << endl;
		gotoxy(45, 5);
		cout << "           $$$;  _<   ������������������������������" << endl;
		gotoxy(45, 6);
		cout << "       _______/ /_    " << endl;
		gotoxy(45, 7);
		cout << "      |  |__`��~/o�� _,]-]___]----->" << endl;
		gotoxy(45, 8);
		cout << "      | / ��(  )  )��-//  " << endl;
		gotoxy(45, 9);
		cout << "     _( �� )    / �� '|  " << endl;
		gotoxy(45, 10);
		cout << "      //| /   ,/   ��/    " << endl;
		gotoxy(45, 11);
		cout << "        '/   o ��        " << endl;
		gotoxy(45, 12);
		cout << "        /     o ��         " << endl;
		gotoxy(45, 13);
		cout << "       /______/����         " << endl;
		gotoxy(45, 14);
		cout << "       ��  ||   /" << endl;
		gotoxy(45, 15);
		cout << "        �� ||  /" << endl;
		gotoxy(45, 16);
		cout << "         ��|| /" << endl;
		gotoxy(45, 17);
		cout << "         / )( ��" << endl;
		gotoxy(45, 18);
		cout << "         |/  '|" << endl;
		gotoxy(45, 19);
		cout << "         :]  [:" << endl;
		gotoxy(45, 20);
		cout << "         o|  |o" << endl;
		gotoxy(45, 21);
		cout << "        /o|  |o��" << endl;
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
		cout << "    ����  []       |||||||||||||||||||" << endl;
		gotoxy(45, 4);
		cout << "     ��___/        |                 |    " << endl;
		gotoxy(45, 5);
		cout << "     |_____|      _|__ __       __ __|_" << endl;
		gotoxy(45, 6);
		cout << "     |     |     ( |  (_o)-/~'-(o_)  | )" << endl;
		gotoxy(45, 7);
		cout << "     |     |      (|      (   )      |) " << endl;
		gotoxy(45, 8);
		cout << "     |     |       |                 |   " << endl;
		gotoxy(45, 9);
		cout << "     |     |_______|    /      ��    |_________ " << endl;
		gotoxy(45, 10);
		cout << "     |     |        ��    _____     /          ��" << endl;
		gotoxy(45, 11);
		cout << "     |     |         ��  (_____)   /            �� " << endl;
		gotoxy(45, 12);
		cout << "     |     |          ��__________/              |" << endl;
		gotoxy(45, 13);
		cout << "     |     |    |      |||||||||||               |" << endl;
		gotoxy(45, 14);
		cout << "     |     /   /        |||||||||       |        |" << endl;
		gotoxy(45, 15);
		cout << "     |        /          |||||||        |        |" << endl;
		gotoxy(45, 16);
		cout << "     |       /              {o          |        |" << endl;
		gotoxy(45, 17);
		cout << "     ��_____/               {o          |        |" << endl;
		gotoxy(45, 18);
		cout << " ������������������������������������������������������" << endl;
		gotoxy(45, 19);
		cout << " �����Ű� �ǻ�(�ͽ�) : ȭ,,ȯ..�ں�, �����̸� �ȵſ�.��" << endl;
		gotoxy(45, 20);
		cout << " ������������������������������������������������������" << endl;
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
		if (maze[floor - 1]->checkDevil()) { //�ͽ��� �������� �Ǵ�
			system("cls");
			if (user.back().getCharacter() == 1)
				sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 2)
				sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 3)
				sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 4)
				sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\�¿�3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			showghost(gn);
			if (!tetrix.start(game - 1)) { //��Ʈ���� ����, Ŭ�����ϸ� true�� ��ȯ
				user.back().setStage(game-1);
				outFile << user.at(user.size() - 1).getInfo() << endl; //������� �г��Ӱ� Ŭ������ �������� ����
				
				return false;
			}
			system("cls");
			showStory(game); 
			system("cls");
			maze[floor - 1]->show();//��Ʈ������ Ŭ�����ϰ� �̷�(�󺴵�) �����
			if (game == 2||game==4) //2��, 3������ �ͽ��� �� �� �����Ƿ�, �� ���� ������ä, ���� ���������� +1 ����
				game++;
			
			continue;
		}
		if (maze[floor - 1]->checkWin()) //Ż�ⱸ�� �����ߴ��� �Ǵ� true: ���޾��� false: ������
		{
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\Door_Shack", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			return true;
		}
		int a = 0;
		srand((unsigned int)time(NULL));
		a = rand() % 8 + 1;
		switch (a) {
		case 1:
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\squeaky.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			break;
		case 2:
			if (user.back().getCharacter() == 1)
				sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 2)
				sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 3)
				sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\����2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 4)
				sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\�¿�2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
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
		cout << "                              ___,---.__          /'| ��          __,---,___" << endl;
		cout << "                           ,-'   ����   `-.____,-'  |  `-.____,-'    //    `-." << endl;
		cout << "                         ,'        |           ~'`     /`~           |        `." << endl;
		cout << "                        /      ___//              `. ,'          ,  , `___      ` " << endl;
		cout << "                       |    ,-'   `-.__   _         |        ,    __,-'   `-.    |" << endl;
		cout << "                       |   /          /`_  `   .    |    ,      _/`          `   |" << endl;
		cout << "                       |  |           ��``-.___��   |   / ___,-'/ /           |  /" << endl;
		cout << "                       �� ��           | `._   ���� |  //'   _,' |           /  /" << endl;
		cout << "                         `-.`         /'  _ `---'' , . ``---' _  ��         /,-'" << endl;
		cout << "                            ``       /     ��   ,='/ ��`=.    /    ��       ''" << endl;
		cout << "                                    |__   /|`_,--.,-.--,--._/|`   __|" << endl;
		cout << "                                    /  `./  ```` |  |  | /,//' `,'  �� " << endl;
		cout << "                                   /   /     ||--+--|--+-/-|     `   | " << endl;
		cout << "                                  |   |     /'`_`_` | /_/_/``    |   |" << endl;
		cout << "                                   �� ��__, `_     `~'     _/ ._/   /" << endl;
		cout << "                                     '-._,-'  `-._______,-'  `-._,-''" << endl;



		cursor(0);
		cout << endl;
		cout << "                                          DO NOT DIE, SURVIVE" << endl;
		if (_getch()) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			sndPlaySoundA("C:\\Users\\�ֽ¿�\\Desktop\\Project6\\Project6\\Project6\\Door_Counterweight.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
}
