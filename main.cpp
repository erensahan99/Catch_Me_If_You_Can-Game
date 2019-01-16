
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

HANDLE renk = GetStdHandle(STD_OUTPUT_HANDLE);
COORD destCoord;

void hide_cursor();
void cursor_move(int x, int y);
void button();
int Start();
void draw_hud();

bool walls = true;

class Player {
public:
	Player();
	int Coord_X, Coord_Y, color;
	int temp_X, temp_Y;
	int state_X, state_Y;

	void draw();
	void move();

}p1, p2;
Player::Player() {
	walls = false;
	state_X = 0;
	state_Y = 0;
	p1.color = 164;
	p2.color = 64;

	p1.Coord_X = 17;
	p1.Coord_Y = 12;
	p1.temp_X = p1.Coord_X;
	p1.temp_Y = p1.Coord_Y;

	p2.Coord_X = 84;
	p2.Coord_Y = 12;
	p2.temp_X = p2.Coord_X;
	p2.temp_Y = p2.Coord_Y;
}
void Player::draw() {
	SetConsoleTextAttribute(renk, 0);
	cursor_move(temp_X, temp_Y);
	cout << "    ";
	cursor_move(temp_X, temp_Y + 1);
	cout << "    ";
	SetConsoleTextAttribute(renk, color);
	cursor_move(Coord_X, Coord_Y);
	cout << "    ";
	cursor_move(Coord_X, Coord_Y + 1);
	cout << "    ";
}
void Player::move() {
	if (state_X == 1 && state_Y == -1) {  //Sað Yukarý
		temp_X = Coord_X;
		temp_Y = Coord_Y;
		Coord_X++;
		Coord_Y++;
		Sleep(30);
	}
	if (state_X == 1 && state_Y == 0) {  //Sað
		temp_X = Coord_X;
		temp_Y = Coord_Y;
		Coord_X++;
		Sleep(10);
	}
	if (state_X == 0 && state_Y == -1) {  //Yukarý
		temp_X = Coord_X;
		temp_Y = Coord_Y;
		Coord_Y++;
		Sleep(30);
	}
	if (state_X == -1 && state_Y == 0) {  //Sol
		temp_X = Coord_X;
		temp_Y = Coord_Y;
		Coord_X--;
		Sleep(10);
	}
	if (state_X == -1 && state_Y == 1) {  //Sol Aþaðý
		temp_X = Coord_X;
		temp_Y = Coord_Y;
		Coord_X--;
		Coord_Y--;
		Sleep(30);
	}
	if (state_X == 0 && state_Y == 1) {  //Aþaðý
		temp_X = Coord_X;
		temp_Y = Coord_Y;
		Coord_Y--;
		Sleep(30);
	}
	if (state_X == 1 && state_Y == 1) {  //Sað Aþaðý
		temp_X = Coord_X;
		temp_Y = Coord_Y;
		Coord_X++;
		Coord_Y--;
		Sleep(30);
	}
	if (state_X == -1 && state_Y == -1) {  //Sol Yukarý
		temp_X = Coord_X;
		temp_Y = Coord_Y;
		Coord_X--;
		Coord_Y++;
		Sleep(30);
	}

	if (walls)
	{
		if (Coord_X > 96) {
			Coord_X = 0;
		}
		if (Coord_X < 0) {
			Coord_X = 96;
		}
		if (Coord_Y > 33) {
			Coord_Y = 0;
		}
		if (Coord_Y < 0) {
			Coord_Y = 33;
		}
	}
	else
	{
		if (Coord_X > 95) {
			Coord_X = 95;
		}
		if (Coord_X < 1) {
			Coord_X = 1;
		}
		if (Coord_Y > 32) {
			Coord_Y = 32;
		}
		if (Coord_Y < 1) {
			Coord_Y = 1;
		}
	}
	state_X = 0;
	state_Y = 0;
}

////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Turkish");
	SetConsoleTitle(TEXT("Catch Me If You Can!"));
	system("MODE CON: COLS=100 LINES=35");
	hide_cursor();
	int winner = 0;
	while (true)
	{
		system("cls");
		system("color 07");
		Player p1, p2;
		draw_hud();
		winner = Start();
		Sleep(1000);
		if (winner == 0) {
			system("color 10");
			SetConsoleTextAttribute(renk, 64);
			cursor_move(15, 11);
			cout << "//////////////////////////////////////////////////////////////////";
			cursor_move(15, 12);
			cout << "/                                                                /";
			cursor_move(15, 13);
			cout << "/                                                                /";
			cursor_move(15, 14);
			cout << "/                                                                /";
			cursor_move(15, 15);
			cout << "/                          Oyun Bitti                            /";
			cursor_move(15, 16);
			cout << "/                                                                /";
			cursor_move(15, 17);
			cout << "/                        Polis Kazandý.                          /";
			cursor_move(15, 18);
			cout << "/                                                                /";
			cursor_move(15, 19);
			cout << "/                                                                /";
			cursor_move(15, 20);
			cout << "/                                                                /";
			cursor_move(15, 21);
			cout << "//////////////////////////////////////////////////////////////////";
			system("pause>null");
			system("color 07");
			system("cls");
			Sleep(500);
		}
		else if (winner == 1) {
			system("color 10");
			SetConsoleTextAttribute(renk, 64);
			cursor_move(15, 11);
			cout << "//////////////////////////////////////////////////////////////////";
			cursor_move(15, 12);
			cout << "/                                                                /";
			cursor_move(15, 13);
			cout << "/                                                                /";
			cursor_move(15, 14);
			cout << "/                                                                /";
			cursor_move(15, 15);
			cout << "/                          Oyun Bitti                            /";
			cursor_move(15, 16);
			cout << "/                                                                /";
			cursor_move(15, 17);
			cout << "/                     Oyunu Hýrsýz Kazandý.                      /";
			cursor_move(15, 18);
			cout << "/                                                                /";
			cursor_move(15, 19);
			cout << "/                                                                /";
			cursor_move(15, 20);
			cout << "/                                                                /";
			cursor_move(15, 21);
			cout << "//////////////////////////////////////////////////////////////////";
			system("pause>null");
			system("color 07");
			system("cls");
			Sleep(500);
		}
	}
	system("pause>null");
	return 0;
}
////////////////////////////////////////////////////

void hide_cursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void cursor_move(int x, int y)
{
	destCoord.X = x;
	destCoord.Y = y;
	SetConsoleCursorPosition(renk, destCoord);
}
void button() {
	if ((GetAsyncKeyState(0x45) & 0x0001) || (GetAsyncKeyState(0x60) & 0x0001)) {  // E TUÞU YADA SAÐ CONTROL
		walls = !walls;
		draw_hud();
	}
	if (GetAsyncKeyState(VK_LEFT)) {  // SOL OK
		p1.state_X = -1;
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {  // SAÐ OK
		p1.state_X = 1;
	}
	if (GetAsyncKeyState(0x41)) {  // SOL OK
		p2.state_X = -1;
	}
	else if (GetAsyncKeyState(0x44)) {  // SAÐ OK
		p2.state_X = 1;
	}
	if ((GetAsyncKeyState(0x45) & 0x0001) || (GetAsyncKeyState(0x60) & 0x0001)) {  // E TUÞU YADA SAÐ CONTROL
		walls = !walls;
		draw_hud();
	}
	if (GetAsyncKeyState(VK_UP)) {  // YUKARI OK
		p1.state_Y = 1;
	}
	else if (GetAsyncKeyState(VK_DOWN)) {  // AÞAÐI OK
		p1.state_Y = -1;
	}
	if (GetAsyncKeyState(0x57)) {  // YUKARI OK
		p2.state_Y = 1;
	}
	else if (GetAsyncKeyState(0x53)) {  // AÞAÐI OK
		p2.state_Y = -1;
	}
	if ((GetAsyncKeyState(0x45) & 0x0001) || (GetAsyncKeyState(0x60) & 0x0001)) {  // E TUÞU YADA SAÐ CONTROL
		walls = !walls;
		draw_hud();
	}

}
bool Is_Catched(bool catched = false) {
	if (p1.Coord_X == p2.Coord_X && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X == p2.Coord_X + 1 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X == p2.Coord_X + 2 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X == p2.Coord_X + 3 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;

	if (p1.Coord_X + 1 == p2.Coord_X && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 1 == p2.Coord_X + 1 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 1 == p2.Coord_X + 2 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 1 == p2.Coord_X + 3 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;

	if (p1.Coord_X + 2 == p2.Coord_X && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 2 == p2.Coord_X + 1 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 2 == p2.Coord_X + 2 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 2 == p2.Coord_X + 3 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;

	if (p1.Coord_X + 3 == p2.Coord_X && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 3 == p2.Coord_X + 1 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 3 == p2.Coord_X + 2 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 3 == p2.Coord_X + 3 && p1.Coord_Y == p2.Coord_Y + 1) catched = true;


	if (p1.Coord_X == p2.Coord_X && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X == p2.Coord_X + 1 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X == p2.Coord_X + 2 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X == p2.Coord_X + 3 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;

	if (p1.Coord_X + 1 == p2.Coord_X && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 1 == p2.Coord_X + 1 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 1 == p2.Coord_X + 2 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 1 == p2.Coord_X + 3 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;

	if (p1.Coord_X + 2 == p2.Coord_X && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 2 == p2.Coord_X + 1 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 2 == p2.Coord_X + 2 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 2 == p2.Coord_X + 3 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;

	if (p1.Coord_X + 3 == p2.Coord_X && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 3 == p2.Coord_X + 1 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 3 == p2.Coord_X + 2 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 3 == p2.Coord_X + 3 && p2.Coord_Y == p1.Coord_Y + 1) catched = true;


	if (p1.Coord_X == p2.Coord_X && p1.Coord_Y == p2.Coord_Y) catched = true;
	else if (p1.Coord_X == p2.Coord_X + 1 && p1.Coord_Y == p2.Coord_Y) catched = true;
	else if (p1.Coord_X == p2.Coord_X + 2 && p1.Coord_Y == p2.Coord_Y) catched = true;
	else if (p1.Coord_X == p2.Coord_X + 3 && p1.Coord_Y == p2.Coord_Y) catched = true;

	if (p1.Coord_X + 1 == p2.Coord_X && p1.Coord_Y == p2.Coord_Y) catched = true;
	else if (p1.Coord_X + 1 == p2.Coord_X + 1 && p1.Coord_Y == p2.Coord_Y) catched = true;
	else if (p1.Coord_X + 1 == p2.Coord_X + 2 && p1.Coord_Y == p2.Coord_Y) catched = true;
	else if (p1.Coord_X + 1 == p2.Coord_X + 3 && p1.Coord_Y == p2.Coord_Y) catched = true;

	if (p1.Coord_X + 2 == p2.Coord_X && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 2 == p2.Coord_X + 1 && p1.Coord_Y == p2.Coord_Y) catched = true;
	else if (p1.Coord_X + 2 == p2.Coord_X + 2 && p1.Coord_Y == p2.Coord_Y) catched = true;
	else if (p1.Coord_X + 2 == p2.Coord_X + 3 && p1.Coord_Y == p2.Coord_Y) catched = true;

	if (p1.Coord_X + 3 == p2.Coord_X && p1.Coord_Y == p2.Coord_Y + 1) catched = true;
	else if (p1.Coord_X + 3 == p2.Coord_X + 1 && p1.Coord_Y == p2.Coord_Y) catched = true;
	else if (p1.Coord_X + 3 == p2.Coord_X + 2 && p1.Coord_Y == p2.Coord_Y) catched = true;
	else if (p1.Coord_X + 3 == p2.Coord_X + 3 && p1.Coord_Y == p2.Coord_Y) catched = true;
	return !catched;
}

void draw_hud()
{
	if (!walls) {
		SetConsoleTextAttribute(renk, 48);
		cursor_move(0, 0);
		for (int i = 0; i < 100; i++)
		{
			cout << " ";
		}
		for (int i = 0; i < 34; i++)
		{
			cursor_move(0, i);
			cout << " ";
			cursor_move(99, i);
			cout << " ";
		}
		cursor_move(0, 35);
		for (int i = 0; i < 100; i++)
		{
			cout << " ";
		}
	}
	else {
		SetConsoleTextAttribute(renk, 0);
		cursor_move(0, 0);
		for (int i = 0; i < 100; i++)
		{
			cout << " ";
		}
		for (int i = 0; i < 34; i++)
		{
			cursor_move(0, i);
			cout << " ";
			cursor_move(99, i);
			cout << " ";
		}
		cursor_move(0, 35);
		for (int i = 0; i < 100; i++)
		{
			cout << " ";
		}
	}
}

int Start() {

	clock_t time;
	bool isPlay = true;

	p1.draw();
	p2.draw();

	time = clock();
	while (isPlay) {
		SetConsoleTextAttribute(renk, 11);
		cursor_move(97, 1);
		cout << (clock() - time) / 1000;
		while ((GetKeyState(VK_NUMLOCK) & 0x0001) == 0)
		{
			Sleep(100);
		}
		button();
		p1.move();
		p2.move();
		p1.draw();
		p2.draw();
		isPlay = Is_Catched();
		if (((clock() - time) / 1000) + 1 == 90) return 1;
		Sleep(20);
	}
	return 0;
}