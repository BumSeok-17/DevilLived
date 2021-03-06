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
	mciOpen.lpstrElementName = "HORROR Background Music.mp3"; // だ橾 唳煎 殮溘
	mciOpen.lpstrDeviceType = "mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE,
		(DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
		(DWORD)(LPVOID)&m_mciPlayParms);
}

void Devil::bgm2start() {
	mciOpen.lpstrElementName = "mazebgm.mp3"; // だ橾 唳煎 殮溘
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
		cout << "(  __  ′ (  ____ ′|′      /|′__   __/( ′           ( ′      ′__   __/|′      /|(  _____′(  __  ′ " << endl;
		cout << "| (  ′ ) | (    ′/| )     ( |    ) (   |  (           |  (          ) (   | )     ( || (    ′/| (  ′  )" << endl;
		cout << "| |   ) | | (__     | |     | |    | |   |  |           |  |          | |   | |     | || (__     | |    ) |" << endl;
		cout << "| |   | | |  __)    ( (     ) )    | |   |  |           |  |          | |   ( (     ) )|  __)    | |    | |" << endl;
		cout << "| |   ) | | (        ′ ′_/ /     | |   |  |           |  |          | |    ′ ′_/ / | (       | |    ) |" << endl;
		cout << "| (__/  ) | (____/′   ′   /   ___) (___|  (____/′ _  |  (____/′___) (___   ′   /  | (____/′| (___/  )" << endl;
		cout << "(______/  (_______ /     ′/   ′_______/(_________/( ) (_______/′________/     ′/   (________/(_______/ " << endl;
		cout << "                                                    |/                                                    " << endl;
		while(true)
		{
			int a = 0;
			srand((unsigned int)time(NULL));
			a = rand() % 15 + 1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
			gotoxy(0, 10);
			cout << "                                                   ,-." << endl;
			cout << "                              ___,---.__          /'| ′          __,---,___" << endl;
			cout << "                           ,-'   ′′   `-.____,-'  |  `-.____,-'    //    `-." << endl;
			cout << "                         ,'        |           ~'`     /`~           |        `." << endl;
			cout << "                        /      ___//              `. ,'          ,  , `___      ` " << endl;
			cout << "                       |    ,-'   `-.__   _         |        ,    __,-'   `-.    |" << endl;
			cout << "                       |   /          /`_  `   .    |    ,      _/`          `   |" << endl;
			cout << "                       |  |           ′``-.___′   |   / ___,-'/ /           |  /" << endl;
			cout << "                       ′ ′           | `._   ′′ |  //'   _,' |           /  /" << endl;
			cout << "                         `-.`         /'  _ `---'' , . ``---' _  ′         /,-'" << endl;
			cout << "                            ``       /     ′   ,='/ ′`=.    /    ′       ''" << endl;
			cout << "                                    |__   /|`_,--.,-.--,--._/|`   __|" << endl;
			cout << "                                    /  `./  ```` |  |  | /,//' `,'  ′ " << endl;
			cout << "                                   /   /     ||--+--|--+-/-|     `   | " << endl;
			cout << "                                  |   |     /'`_`_` | /_/_/``    |   |" << endl;
			cout << "                                   ′ ′__, `_     `~'     _/ ._/   /" << endl;
			cout << "                                     '-._,-'  `-._______,-'  `-._,-''" << endl;



			cursor(0);
			cout << endl;
			cout << "                                        <<press any key to start>>" << endl;
			Sleep(1000);

			if (_kbhit())
				break;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\Door_Counterweight.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		system("cls");
		_getch();
int menu = 0;
while (true)
{
	gotoxy(40, 13);
	cout << "旨收收收收收收收收收收收收收旬";
	gotoxy(40, 14);
	cout << "早      [1] 啪歜衛濛        早";
	gotoxy(40, 15);
	cout << "早      [2] 楨    韁        早";
	gotoxy(40, 16);
	cout << "早      [3] 釭 陛 晦        早";
	gotoxy(40, 17);
	cout << "曲收收收收收收收收收收收收收旭";
	int menu = _getch() - '0';
	sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
	switch (menu) {
	case 1:
		init();
		showStory(0); //Щ煤煎斜 轎溘
		if (devil(1, 1))//羅廓簞 敝褐 虜陴
			if (devil(2, 2))//舒廓簞 敝褐, 撮廓簞 敝褐 虜陴
				if (devil(4, 3)) {//啻廓簞 敝褐, 棻撓廓簞 敝褐 虜陴
					showStory(6);//縑в煎斜 轎溘
					user.back().setStage(5); //葆雖虞 蝶纔檜雖蒂 產擊 陽 嶸盪 薑爾 熱薑
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
		cout << "2蟾 菴縑 謙猿腌棲棻..";
		Sleep(2000);
		return;
	default:
		system("cls");
		cout << "棻衛 殮溘ж撮蹂" << endl;
	}
}
}
void Devil::init() {
	string nickname;
	int character;
	system("cls");
	gotoxy(40, 14);
	cout << "旨收收收收收收收收收收收收收旬";
	gotoxy(40, 15);
	cout << "早渡褐曖 檜葷擎? :          早";
	gotoxy(40, 16);
	cout << "曲收收收收收收收收收收收收收旭";
	gotoxy(59, 15);
	cin >> nickname;
	sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
	system("cls");
	gotoxy(40, 11);
	cout << "旨收收收收收收收收收收收收收旬";
	gotoxy(40, 12);
	cout << "早      [1] 鬼 彰 戮        早";
	gotoxy(40, 13);
	cout << "早      [2] 夢 彰 熱        早";
	gotoxy(40, 14);
	cout << "早      [3] 撩 晦 擎        早";
	gotoxy(40, 15);
	cout << "早      [4] 譆 蝓 翱        早";
	gotoxy(40, 16);
	cout << "曲收收收收收收收收收收收收收旭";
	gotoxy(40, 17);
	cout << " 議葛攪 摹鷗 : ";
	
	cin >> character;
	sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
	switch (character) {
	case 1:
		sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\彰戮1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		system("cls");
		cout << "		       ," << endl;
		cout << "            ,:' `..;" << endl;
		cout << "            `. ,;;'%" << endl;
		cout << "            +;;'%%%%%" << endl;
		cout << "             /- %,)%%" << endl;
		cout << "             `  ′ %%" << endl;
		cout << "              =  )/ ′" << endl;
		cout << "              `-'/ / ′" << endl;
		cout << "                /′/.-′" << endl;
		cout << "               |  (    |" << endl;
		cout << "               |  |   ||" << endl;
		cout << "               |  |   ||" << endl;
		cout << "           _.-----'   ||" << endl;
		cout << "          /′________,'|" << endl;
		cout << "         (((/  |       |" << endl;
		cout << "         //    |       |" << endl;
		cout << "        //     |′     |" << endl;
		cout << "       //      | ′    |" << endl;
		cout << "      //       |  ′   |" << endl;
		cout << "     //        |   ′  |" << endl;
		cout << "    //         |    ′ |" << endl;
		cout << "   //          |    |′|" << endl;
		cout << "  //           |    |′|" << endl;
		cout << " //            ′   ′" << endl;
		cout << "c'             |′   ′" << endl;
		cout << "               | ′   ′" << endl;
		cout << "               |  ′   ′" << endl;
		cout << "               |.' ′   ′" << endl;
		cout << "              _′    ′.-'′" << endl;
		cout << "             (___.-(__.'′/" << endl;

	gotoxy(50, 13);
	cout << "旨收收收收收收收收收收收收收旬";
	gotoxy(50, 14);
	cout << "早   [議葛攪貲] 鬼 彰 戮    早";
	gotoxy(50, 15);
	cout << "早[撩問]參戲煎朝 鬼и繫ж釭,早";
	gotoxy(50, 16);
	cout << "早 憲堅爾賊 匏檜 號擎 ら檜棻早";
	gotoxy(50, 17);
	cout << "曲收收收收收收收收收收收收收旭";
	gotoxy(50, 18);
	cout << " press any key to continue...";
	if (_getch()) {
		
		system("cls");
	}
		break;
	case 2:
		system("cls");
		sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\彰熱1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		cout << "      ////^′′" << endl;
		cout << "      | ^   ^ |" << endl;
		cout << "     @ (o) (o) @" << endl;
		cout << "      |   <   |" << endl;
		cout << "      |  ___  |" << endl;
		cout << "       ′____/" << endl;
		cout << "     ____|  |___" << endl;
		cout << "    /    ′_/   ′" << endl;
	    cout << "   /              ′" << endl;
		cout << "  /′/|        |′ /′" << endl;
		cout << " / /  |        |  ′ ′" << endl;
		cout << "( <   |        |   >  )" << endl;
		cout << "′′  |        |  /  /" << endl;
		cout << "  ′′|________| /  /" << endl;
		cout << "    ′|<I_D_I__|/  /" << endl;
		cout << "      |/ I ′  / /" << endl;
		cout << "      | /  I  ′|" << endl;
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
		cout << "旨收收收收收收收收收收收收收旬";
		gotoxy(50, 14);
		cout << "早   [議葛攪貲] 夢 彰 熱    早";
		gotoxy(50, 15);
		cout << "早   [撩問] 瞳斛瞳檜釭,     早";
		gotoxy(50, 16);
		cout << "早   匏檜 雖釭纂啪 號棻.    早";
		gotoxy(50, 17);
		cout << "曲收收收收收收收收收收收收收旭";
		gotoxy(50, 18);
		cout << " press any key to continue...";
		if (_getch()) {
		
			system("cls");
		}
		break;
	case 3:
		system("cls");
		sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\晦擎1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		cout << "              ., _" << endl;
		cout << "             /    `" << endl;
		cout << "            ((|)))))" << endl;
		cout << "            ((/ a a" << endl;
		cout << "            )))   >)" << endl;
		cout << "           ((((._e((" << endl;
		cout << "          ,--/ (-." << endl;
		cout << "         /′<′/>/|" << endl;
		cout << "        / /)  Lo )|" << endl;
		cout << "       / / )    / |" << endl;
		cout << "      |   /    ( /" << endl;
		cout << "      |  /     ;/" << endl;
		cout << "      ||(      |" << endl;
		cout << "     / )|/|    | " << endl;
		cout << "    |/'/′_____′" << endl;
		cout << "          ′   | ′" << endl;
		cout << "           ′  |′ ′" << endl;
		cout << "            |  | )  )" << endl;
		cout << "            )  )/  /" << endl;
		cout << "           /  /   /" << endl;
		cout << "          /   |  /" << endl;
		cout << "         /    | /" << endl;
		cout << "        /     ||" << endl;
		cout << "       /      ||" << endl;
		cout << "        '-,_  |_′" << endl;
		cout << "          ( ''''-`' " << endl;
		cout << "           ′(′_′" << endl;

		gotoxy(50, 13);
		cout << "旨收收收收收收收收收收收收收旬";
		gotoxy(50, 14);
		cout << "早   [議葛攪貲] 撩 晦 擎    早";
		gotoxy(50, 15);
		cout << "早 [撩問] 模褕й 匙 偽雖虜, 早";
		gotoxy(50, 16);
		cout << "早 斜 援掘爾棻紫 ぬ晦剩耀棻 早";
		gotoxy(50, 17);
		cout << "曲收收收收收收收收收收收收收旭";
		gotoxy(50, 18);
		cout << " press any key to continue...";
		if (_getch()) {
			
			system("cls");
		}
		break;
	case 4:
		system("cls");
		sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\蝓翱1.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		cout << "           ____  " << endl;
		cout << "         /((   ))" << endl;
		cout << "        ( )6  6( )" << endl;
		cout << "        (_)  l (_)" << endl;
		cout << "          ( <> )" << endl;
		cout << "      _____)  (_____" << endl;
		cout << "     (  ′      /   )" << endl;
		cout << "     )  ,′ |  /  ` (" << endl;
		cout << "    / /(    Y     )′′" << endl;
		cout << "   / /   `     ,'   | )" << endl;
		cout << "   ′′   )===(    / /" << endl;
		cout << "    ′′ ,     `  / /" << endl;
		cout << "     '′/       ′//'" << endl;
		cout << "     '|′`     '|′`" << endl;
		cout << "        ′      /" << endl;
		cout << "         ′    /" << endl;
		cout << "          )    (" << endl;
		cout << "         /     ′" << endl;
		cout << "        /       ′ " << endl;
		cout << "       /         ′" << endl;
		cout << "      /           ′ " << endl;
		cout << "     /             ′" << endl;
		cout << "    /               ′" << endl;
		cout << "    `-....,      ,..-'" << endl;
		cout << "           `-..-'" << endl;
		
		gotoxy(50, 13);
		cout << "旨收收收收收收收收收收收收收旬";
		gotoxy(50, 14);
		cout << "早   [議葛攪貲] 譆 蝓 翱    早";
		gotoxy(50, 15);
		cout << "早   [撩問] 辨晦陛 陴殖塭,  早";
		gotoxy(50, 16);
		cout << "早  敝褐褻離紫 殖嬴釭啪и棻 早";
		gotoxy(50, 17);
		cout << "曲收收收收收收收收收收收收收旭";
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
	ifstream inputFile("User.txt"); //User.txt縑 氈朝 等檜攪 碳楝螃晦
	while (true) {
		if (inputFile.eof())
			break;
		getline(inputFile, line);
		name.push_back(line.substr(0, line.find(' ')));//綴蘊擊 晦遽戲煎 擅睡碟擊 name 漱攪縑 厥晦
		stage.push_back(line.substr(line.rfind(' ') + 1, line.size() - name.at(name.size() - 1).size()));//綴蘊擊 晦遽戲煎 萌睡碟擊 stage 漱攪縑 厥晦
	}

	for (int i = 0; i < stage.size(); i++) { //堪擎 蝶纔檜雖 贗葬橫и 牖憮渠煎 薑溺
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
	cout << "<********** 楨韁 **********>" << endl;
	gotoxy(42, 5);
	cout << "   棣啻歜        蝶纔檜雖" << endl;
	for (int i = 0; i < name.size(); i++) {
		gotoxy(45, 7+i);
		cout << name.at(i);
		gotoxy(60, 7 + i);
		cout << stage.at(i);
		cout << endl;
		temp = i;
	}
	gotoxy(45, 10 + temp);
	cout << "菴煎陛晦..(Enter)";
	_getch();
}
void Devil::showStory(int story) {
	if (story == 0) //Щ煤煎斜 轎溘
	{
		gotoxy(32, 12);
		cout << "旨收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(32, 13);
		cout << "早釭朝 わ煽翕縑 橾謙曖 �ㄠ熀劦虞� 菟橫諮棻早";
		gotoxy(32, 14);
		cout << "早橾謙曖 �ㄠ熀劦抰斐�.                    早";
		gotoxy(32, 15);
		cout << "早斜盪 鬚я檜 п爾堅 談歷擊  閨檜棻.      早";
		gotoxy(32, 16);
		cout << "曲收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(32, 17);
		cout << " press any key to continue..." << endl;
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(31, 12);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(31, 13);
		cout << "早斜纂虜 頂陛 儅陝и 鬚я擎 檜楛啪 嬴棲艘棻 早";
		gotoxy(31, 14); 
		cout << "早鼠樹陛 檜鼻ж棻.                          早";
		gotoxy(31, 15); 
		cout << "早鼠樹陛 檜鼻и 匙菟檜 釭蒂 竣藥諮棻.       早";
		gotoxy(31, 16);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(31, 17);
		cout << " press any key to continue..." << endl;
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(15, 12);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(15, 13);
		cout << "早わ煽翕縑 氈朝 и 裕�� 除�˙蝐芺霾� 斜葬堅 曖餌敝褐菟檜 頂陛 菟橫螞 僥擊 虞堅早";
		gotoxy(15, 14);
		cout << "早煽錳曖 嶸橾и 驍轎掘檣 螟鼻戲煎 陛朝 望擊 陛煎虞懊棻.                       早";
		gotoxy(15, 15);
		cout << "早檜夠縑 陘�钁� 6橾簞, 檣除檜 嬴鼠楛 僭婁 衝榆橈檜 幗せ熱 氈朝 陳擎           早";
		gotoxy(15, 16);
		cout << "早欽 ж瑞 陴懊棻.                                                             早";
		gotoxy(15, 17);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(15, 18);
		cout << " press any key to continue..." << endl;
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(30, 12);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(30, 13);
		cout << "早檜薯朝 驍轎п撿虜 и棻, 頂陛 髦晦 嬪п摹.       早";
		gotoxy(30, 14);
		cout << "早嶸橾и 驍轎掘檣 螟鼻戲煎 橫飩啪萇 陛撿虜и棻’’早";
		gotoxy(30, 15);
		cout << "早嫦勘擠擊 馮棻.                                  早";
		gotoxy(30, 16);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(30, 17);
		cout << " press any key to ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "[ESCAPE]";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}

	}
	else if (story == 1)
	{
		gotoxy(30, 11);
		cout << "#�秣�, 斜 羅廓�� 晦橘 : 睡賅";
		gotoxy(30, 12);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(30, 13);
		cout << "早釭 : 樵葆..盪晦... 螃棺 模Ё陛賊 寰腋蹂... ?    早";
		gotoxy(30, 14);
		cout << "早樵葆 : 頂陛 雖旎 傘嫌 啾嬴還 衛除檜 橫視棲!?    早";
		gotoxy(30, 15);
		cout << "早釭 : 斜楚紫...棻艇 耀掘菟擎....                 早";
		gotoxy(30, 16);
		cout << "早樵葆 : 嬴�� 頂陛 傘虜 寰 竟懊橫紫....           早";
		gotoxy(30, 17);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(30, 18);
		cout << " '援掘 樽晦雖..? 橾欽 鼠衛ж堅 雖釭陛撿啊橫..'";
		gotoxy(30, 24);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(30, 25);
		cout << "早   [晦橘] 檜 20 % 給嬴諮蝗棲棻...啗樓(ENTER)    早";
		gotoxy(30, 26);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收旭";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		Sleep(5000);
	}
	else if (story == 2)
	{
		gotoxy(30, 11);
		cout << "#�秣�, 斜 舒廓�� 晦橘 : 耀掘";
		gotoxy(30, 12);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(30, 13);
		cout << "早釭 : 渠羹 釭и纔 謁檜楝朝勒等...                    早";
		gotoxy(30, 14);
		cout << "早耀掘菟 : 斜翕寰 釭塭紫 耀掘煎 陴懊鍍湍 勘 堅葆錶п塭早";
		gotoxy(30, 15);
		cout << "早釭 : 頂 蜓紫 覬 菟橫醜...                           早";
		gotoxy(30, 16);
		cout << "早耀掘菟 : 睡賅 橈朝 喫擊 檜пж溥堅 и 頂陛 嘐蟻雖   早";
		gotoxy(30, 17);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(30, 18);
		cout << " '劃陛 綠蝌и 晦橘檜 釭朝 匙 偽擎等...橾欽 渦 陛爾濠'";
		gotoxy(30, 24);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(30, 25);
		cout << "早   [晦橘] 檜 40 % 給嬴諮蝗棲棻...啗樓(ENTER)    早";
		gotoxy(30, 26);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收旭";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 3)
	{
		gotoxy(15, 11);
		cout << "#�秣�, 斜 撮廓�� 晦橘 : з掖";
		gotoxy(15, 12);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(15, 13);
		cout << "早釭 : 摹儅椒...睡腦樟棻堅ж敷憮蹂..                                          早";
		gotoxy(15, 14);
		cout << "早摹儅椒 :(檣鼻擊 鎬ヰ葬貊) 諮棲 ? 傘 蹂闈 擁菟餌檜縑憮 蜓檜 號棻?            早";
		gotoxy(15, 15);
		cout << "早釭 : 斜啪...耀掘菟檜 濠紱 盪蒂....                                          早";
		gotoxy(15, 16);
		cout << "早摹儅椒 : 耀掘菟 鰱ж雖 蜓堅 啻陛 и ч翕菟擊 腎給嬴爾溫,                    早";
		gotoxy(15, 17);
		cout << "早         棻艇 耀掘菟 蜓煎朝 啻陛 僥薯塭湍等 ?                               早";
		gotoxy(15, 18);
		cout << "早         斜溢雖 彊堅憮撿 澀 雖頂湍 耀掘菟檜 骨濠晦 蛔擊 給萵啊棲? 喪戮 霤.. 早";
		gotoxy(15, 19);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(15, 20);
		cout << " '頂陛 з掖縑 棻單擊 ��紫 綠蝌и 橾檜 橾橫陬湍 匙 偽擎等...渦 陛獐梱...'";
		gotoxy(30, 24);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(30, 25);
		cout << "早   [晦橘] 檜 60 % 給嬴諮蝗棲棻...啗樓(ENTER)    早";
		gotoxy(30, 26);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收旭";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 4)
	{
		gotoxy(15, 11);
		cout << "#�秣�, 斜 啻廓�� 晦橘 : �蜓�";
		gotoxy(15, 12);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(15, 13);
		cout << "早釭 : 睡濰椒 嬴梱 蜓噪ж褐 唸營 憮盟殮棲棻...                                早";
		gotoxy(15, 14);
		cout << "早睡濰椒 : 衛鑑雖陛 樹薇等 檜薯撿 陛螳諦? 濰陪ж釭 濠啻?                      早";
		gotoxy(15, 15); 
		cout << "早釭 : ж雖虜 橫薯 睡濰椒眷憮 螃棺梱雖..                                      早";
		gotoxy(15, 16);
		cout << "早睡濰椒 : 剪霤..ж釭朝 憲堅 萃擎 賅腦朝捱, 檜 �蜓蝪� 斜溢啪 虜虜и陛?        早";
		gotoxy(15, 17);
		cout << "早        渠羹 й 還 嬴朝啪 劃陛? 檜楛 檣除檜 橫飩啪 罹望 菟橫諮朝雖 霤..橫�� 早";
		gotoxy(15, 18);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(15, 19);
		cout << " '橫塭..? 腎啪 譆斬縑 頂陛 �蜓蝧□� 啕擎橾檜濫嬴 檜啪 骨濠晦 謁...?'";
		gotoxy(30, 24);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(30, 25);
		cout << "早   [晦橘] 檜 80 % 給嬴諮蝗棲棻...啗樓(ENTER)    早";
		gotoxy(30, 26);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收旭";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 5)
	{
		gotoxy(15, 11);
		cout << "#�秣�, 斜 棻撓廓�� 晦橘 : 餌嫌";
		gotoxy(15, 12);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(15, 13);
		cout << "早釭 : 雖熱撿 號檜 晦棻溜雖!! 頂陛 覬 棵歷棻 嘐寰п, 號檜 晦棻溜橫??            早";
		gotoxy(15, 14);
		cout << "早擁檣 : ....盪晦..氈濫嬴..                                                     早";
		gotoxy(15, 15);
		cout << "早釭 : 骨濠晦 罹晦梱雖 鼠蝦 橾檜撿 ?? 螃棺 撿斬и棻貊, 頂橾 虜釭晦煎 ц濫嬴~    早";
		gotoxy(15, 16);
		cout << "早擁檣 : 傘и纔 螃棺 й 蜓 氈橫憮 諮橫                                          早";
		gotoxy(15, 17);
		cout << "早釭 : 擬? 謁...劃等 斜楚? 蜓п瑭                                               早";
		gotoxy(15, 18);			
		cout << "早擁檣 : 檜薇 紫盪�� 跤 霤啊橫. 衙廓 啻 ч翕檜 鼠撥堅 鼠蝦 騁擊 й 雖 舒溥錶    早";
		gotoxy(15, 19);
		cout << "早       傘嫌 氈戲賊 ч犒и啪 嬴棲塭, Я陛 葆腦朝 匙 偽嬴..斜虜ж濠..釭 陞啪..  早";
		gotoxy(15, 20);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(15, 21);
		cout << " '雖錳檜...?檜勒 諫瞪�� 頂 樽晦濫嬴....渠羹 謁 檜楛 晦橘菟檜 集螃腦朝剪傍堅!!!'";
		gotoxy(30, 24);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(30, 25);
		cout << "早   [晦橘] 檜 100 % 給嬴諮蝗棲棻...啗樓(ENTER)   早";
		gotoxy(30, 26);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收旭";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
	}
	else if (story == 6) //縑в煎斜 轎溘
	{
		if (user.back().getCharacter() == 1)
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\彰戮4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		else if (user.back().getCharacter() == 2)
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\彰熱4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		else if (user.back().getCharacter() == 3)
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\晦擎4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		else if (user.back().getCharacter() == 4)
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\蝓翱4.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		gotoxy(15, 13);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(15, 14);
		cout << "早  陪 驍轎ц棻.雖晚雖晚и 檜夠戲煎睡攪.橫憮 嗨橫頂溥憮 罹望 釭陛撿啊棻.  早";
		gotoxy(15, 15);
		cout << "早  4類檜棲梱 觼啪 棻纂雖 彊啊雖, , , !                                   早";
		gotoxy(15, 16);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收六收收收收收收收收收收收收旭";
		gotoxy(90, 29);
		cout << "...啗樓(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		bgmpause();
		sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\glass.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
		system("color 44");
		Sleep(4000);
		system("color 07");
		bgm2start();

		gotoxy(28, 13);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(28, 14);
		cout << "早    らж棻..頂 賅萇 晦橘菟檜 腎給嬴 螃朝 蛭 談歷棻.   早";
		gotoxy(28, 15);
		cout << "早                                                      早";
		gotoxy(28, 16);
		cout << "早     斜楛等 僥菜 鼠樹陛 檜鼻и 曖僥檜 菟歷棻.         早";
		gotoxy(28, 17);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(90, 29);
		cout << "...啗樓(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}

		gotoxy(15, 11);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(15, 12);
		cout << "早    陪 謁 掩檜 わ煽翕縑 菟橫螞勒雖 謁 檜夠縑 莊葬蛭 螃啪脹剪雖..?                 早";
		gotoxy(15, 13);
		cout << "早    陪 碟貲 �ㄠ熀劦抰斐�.�ㄠ熀刐� 鬚я擊 ж溥ц朝等’ ?                           早";
		gotoxy(15, 14);
		cout << "早    斜溢雖虜 頂 該葬朝 棻艇 濰賊擊 晦橘и棻.                                      早";
		gotoxy(15, 15);
		cout << "早    援捱陛 釭蒂 鬼薯煎 檜夠戲煎 莊堅諮棻.                                         早";
		gotoxy(15, 16);
		cout << "早    橫翹賊 �ㄠ熀劦� 寞僥檜 嬴棲塭 鬼薯瞳檣 殮錳檜歷擊雖紫 賅艇棻朝 儅陝檜 菟歷棻. 早";
		gotoxy(15, 17);
		cout << "早    澀 賅腦啊棻.渦 蕨瞪擊 晦橘п爾濠.�公� 棻艇 晦橘檜 陳 熱紫 氈戲棲械.           早";
		gotoxy(15, 18);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(90, 29);
		cout << "...啗樓(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		gotoxy(15, 11);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(15, 12);
		cout << "早 斜溢棻 釭朝 橫溥憮睡攪 睡賅椒眷 嘐遺擊 嫡懊棻 濠衝檜 嬴棋 颶蝓籀歲 棻瘀螺棻...   早";
		gotoxy(15, 13);
		cout << "早 з掖縑憮朝 耀掘菟曖 掘顫諦 諾評 斜葬堅 啖辦 絮董曖 維 и還晦虜 夥塭爾貊 髦嬴螞   早";
		gotoxy(15, 14);
		cout << "早 頂陛 菟橫除 霜濰縑憮 渡и 霜濰鼻餌曖 ァч婁 ァ樹..釭朝 斜溢啪 嘐藥陛貊 濠嫉棻.   早";
		gotoxy(15, 15);
		cout << "早 釭朝 唸措 辦選隸擊 憊懊棻. 擒檜 橈檣 儅�偯� 碳陛棟п螺堅 釭朝 薄薄 嘐藥鬲棻.     早";
		gotoxy(15, 16);
		cout << "早 輿滲餌塋菟縑啪紫 Яп蒂 輿晦 衛濛ц堅 輿滲餌塋菟擎 ж釭萃噶 釭蒂 集釭鬲棻.       早";
		gotoxy(15, 17);
		cout << "早 檜渠煎朝 寰脹棻 釭朝 餌�蛾□� 問葬腎橫撿и棻堅 っ欽ц棻.                         早";
		gotoxy(15, 18);
		cout << "早 檜瞪縑 憲嬴疑湍 薑褐煽錳 廓�ㄦ� 瞪�飛� 勘歷棻’’.罹爾撮蹂....                   早";
		gotoxy(15, 19);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(90, 29);
		cout << "...啗樓(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
		system("color 17");
		bgmpause();
		bgm1start();
		gotoxy(15, 11);
		cout << "旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬";
		gotoxy(15, 12);
		cout << "早 �秣� 樓 頂陛 驍轎掘塭堅 圖歷湍 匙擎 唸措 釭蒂 避擠戲煎 路嬴厥朝 夠檜歷棻.        早";
		gotoxy(15, 13);
		cout << "早 嬴棲 橫翹賊 避擠檜 釭縑啪煎 褻罹螃朝 堅漓菟煎睡攪 嶸橾и 驍轎掘 艘擊雖紫 賅艇棻. 早";
		gotoxy(15, 14);
		cout << "早 ж雖虜 斜匙擎 欽牖и '避擠' 濠羹陛 嬴棲棻. 釭曖 懍選ц湍 婁剪蒂 腎給嬴爾堅,      早";
		gotoxy(15, 15);
		cout << "早 檜薯朝 霞薑и 濠嶸蒂 橢啪脹 匙檜 嬴棍梱.                                         早";
		gotoxy(15, 16);
		cout << "早 橫萍晦虜 ц湍 頂 魂縑, 葆藹頂 и還晦 維檜 菟橫螞 蛭и 晦碟檜棻.                  早";
		gotoxy(15, 17);
		cout << "早                                                                                  早";
		gotoxy(15, 18);
		cout << "早 薄薄 跺縑 晦遴檜 緒螳除棻...檜薇 らж棻...                                       早";
		gotoxy(15, 19);
		cout << "曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭";
		gotoxy(90, 29);
		cout << "...啗樓(ENTER)";
		if (_getch()) {
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\gun.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
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
		cout << "             $$$ , ,  旨收收收收收收收收收收收收收旬 " << endl;
		gotoxy(45, 4);
		cout << "            $$C    >  早 除�˙�(敝褐) : �素睆�... 早" << endl;
		gotoxy(45, 5);
		cout << "           $$$;  _<   曲收收收收收收收收收收收收收旭" << endl;
		gotoxy(45, 6);
		cout << "       _______/ /_    " << endl;
		gotoxy(45, 7);
		cout << "      |  |__`′~/o′ _,]-]___]----->" << endl;
		gotoxy(45, 8);
		cout << "      | / ′(  )  )′-//  " << endl;
		gotoxy(45, 9);
		cout << "     _( ′ )    / ′ '|  " << endl;
		gotoxy(45, 10);
		cout << "      //| /   ,/   ′/    " << endl;
		gotoxy(45, 11);
		cout << "        '/   o ′        " << endl;
		gotoxy(45, 12);
		cout << "        /     o ′         " << endl;
		gotoxy(45, 13);
		cout << "       /______/′′         " << endl;
		gotoxy(45, 14);
		cout << "       ′  ||   /" << endl;
		gotoxy(45, 15);
		cout << "        ′ ||  /" << endl;
		gotoxy(45, 16);
		cout << "         ′|| /" << endl;
		gotoxy(45, 17);
		cout << "         / )( ′" << endl;
		gotoxy(45, 18);
		cout << "         |/  '|" << endl;
		gotoxy(45, 19);
		cout << "         :]  [:" << endl;
		gotoxy(45, 20);
		cout << "         o|  |o" << endl;
		gotoxy(45, 21);
		cout << "        /o|  |o′" << endl;
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
		cout << "    ′′  []       |||||||||||||||||||" << endl;
		gotoxy(45, 4);
		cout << "     ′___/        |                 |    " << endl;
		gotoxy(45, 5);
		cout << "     |_____|      _|__ __       __ __|_" << endl;
		gotoxy(45, 6);
		cout << "     |     |     ( |  (_o)-/~'-(o_)  | )" << endl;
		gotoxy(45, 7);
		cout << "     |     |      (|      (   )      |) " << endl;
		gotoxy(45, 8);
		cout << "     |     |       |                 |   " << endl;
		gotoxy(45, 9);
		cout << "     |     |_______|    /      ′    |_________ " << endl;
		gotoxy(45, 10);
		cout << "     |     |        ′    _____     /          ′" << endl;
		gotoxy(45, 11);
		cout << "     |     |         ′  (_____)   /            ′ " << endl;
		gotoxy(45, 12);
		cout << "     |     |          ′__________/              |" << endl;
		gotoxy(45, 13);
		cout << "     |     |    |      |||||||||||               |" << endl;
		gotoxy(45, 14);
		cout << "     |     /   /        |||||||||       |        |" << endl;
		gotoxy(45, 15);
		cout << "     |        /          |||||||        |        |" << endl;
		gotoxy(45, 16);
		cout << "     |       /              {o          |        |" << endl;
		gotoxy(45, 17);
		cout << "     ′_____/               {o          |        |" << endl;
		gotoxy(45, 18);
		cout << " 旨收收收收收收收收收收收收收收收收收收收收收收收收收旬" << endl;
		gotoxy(45, 19);
		cout << " 早薑褐婁 曖餌(敝褐) : ��,,��..濠碟, 遺霜檜賊 寰腋蹂.早" << endl;
		gotoxy(45, 20);
		cout << " 曲收收收收收收收收收收收收收收收收收收收收收收收收收旭" << endl;
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
		if (maze[floor - 1]->checkDevil()) { //敝褐擊 虜陬朝雖 っ欽
			system("cls");
			if (user.back().getCharacter() == 1)
				sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\彰戮3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 2)
				sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\彰熱3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 3)
				sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\晦擎3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 4)
				sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\蝓翱3.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			showghost(gn);
			if (!tetrix.start(game - 1)) { //纔お葬蝶 褒ч, 贗葬橫ж賊 true蒂 奩��
				user.back().setStage(game-1);
				outFile << user.at(user.size() - 1).getInfo() << endl; //餌辨濠曖 棣啻歜婁 贗葬橫и 蝶纔檜雖 盪濰
				
				return false;
			}
			system("cls");
			showStory(game); 
			system("cls");
			maze[floor - 1]->show();//纔お葬蝶蒂 贗葬橫ж堅 嘐煎(わ煽翕) 營轎溘
			if (game == 2||game==4) //2類, 3類縑摹 敝褐擊 舒 廓 虜釭嘎煎, 類 熱朝 嶸雖и瓣, 啪歜 蝶纔檜雖虜 +1 п邀
				game++;
			
			continue;
		}
		if (maze[floor - 1]->checkWin()) //驍轎掘縑 紫殖ц朝雖 っ欽 true: 紫殖寰л false: 紫殖л
		{
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\Door_Shack", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			return true;
		}
		int a = 0;
		srand((unsigned int)time(NULL));
		a = rand() % 8 + 1;
		switch (a) {
		case 1:
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\squeaky.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			break;
		case 2:
			if (user.back().getCharacter() == 1)
				sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\彰戮2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 2)
				sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\彰熱2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 3)
				sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\晦擎2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			else if (user.back().getCharacter() == 4)
				sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\蝓翱2.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
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
		cout << "                              ___,---.__          /'| ′          __,---,___" << endl;
		cout << "                           ,-'   ′′   `-.____,-'  |  `-.____,-'    //    `-." << endl;
		cout << "                         ,'        |           ~'`     /`~           |        `." << endl;
		cout << "                        /      ___//              `. ,'          ,  , `___      ` " << endl;
		cout << "                       |    ,-'   `-.__   _         |        ,    __,-'   `-.    |" << endl;
		cout << "                       |   /          /`_  `   .    |    ,      _/`          `   |" << endl;
		cout << "                       |  |           ′``-.___′   |   / ___,-'/ /           |  /" << endl;
		cout << "                       ′ ′           | `._   ′′ |  //'   _,' |           /  /" << endl;
		cout << "                         `-.`         /'  _ `---'' , . ``---' _  ′         /,-'" << endl;
		cout << "                            ``       /     ′   ,='/ ′`=.    /    ′       ''" << endl;
		cout << "                                    |__   /|`_,--.,-.--,--._/|`   __|" << endl;
		cout << "                                    /  `./  ```` |  |  | /,//' `,'  ′ " << endl;
		cout << "                                   /   /     ||--+--|--+-/-|     `   | " << endl;
		cout << "                                  |   |     /'`_`_` | /_/_/``    |   |" << endl;
		cout << "                                   ′ ′__, `_     `~'     _/ ._/   /" << endl;
		cout << "                                     '-._,-'  `-._______,-'  `-._,-''" << endl;



		cursor(0);
		cout << endl;
		cout << "                                          DO NOT DIE, SURVIVE" << endl;
		if (_getch()) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			sndPlaySoundA("C:\\Users\\譆蝓翱\\Desktop\\Project6\\Project6\\Project6\\Door_Counterweight.wav", SND_ASYNC | SND_NODEFAULT | SND_SYNC);
			system("cls");
		}
}
