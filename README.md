# -
实验-俄罗斯方块
#include <iostream>
#include<windows.h> 
#include<process.h> 
#include<ctime>
#include<cstdlib>
#include <conio.h> 
using namespace std;
int gotoxy(int x, int y)
{
	COORD c;
	c.X = 2 * x; c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}
int sharp[19][8] = { { 0, 0, 0, 1, 0, 2, 0, 3 }, { 0, 0, 1, 0, 2, 0, 3, 0 },										//圆柱 
{ 0, 0, 0, 1, 1, 0, 1, 1 },															//正方形 
{ 0, 0, 0, 1, 0, 2, 1, 2 }, { 0, 1, 1, 1, 2, 1, 2, 0 }, { 0, 0, 1, 0, 1, 1, 1, 2 }, { 0, 0, 1, 0, 2, 0, 0, 1 },		//L形 
{ 0, 2, 1, 0, 1, 1, 1, 2 }, { 0, 0, 0, 1, 1, 1, 2, 1 }, { 0, 0, 0, 1, 0, 2, 1, 0 }, { 0, 0, 1, 0, 2, 0, 2, 1 },		//反L形	
{ 0, 0, 1, 0, 1, 1, 2, 1 }, { 1, 0, 1, 1, 0, 1, 0, 2 },											//z形 
{ 0, 1, 1, 1, 1, 0, 2, 0 }, { 0, 0, 0, 1, 1, 1, 1, 2 },											//反z形 
{ 0, 1, 1, 1, 2, 1, 1, 0 }, { 1, 2, 1, 1, 1, 0, 0, 1 }, { 1, 0, 2, 0, 1, 1, 0, 0 }, { 0, 2, 0, 1, 0, 0, 1, 1 }		//T形 
};
int v = 300;
class Terix{
private:
	int map[12][20];
	int right, down;
	int _right, _down;
	int id, next;
	int score;
public:
	Terix();
	void create();					//创造新的方块 
	void initial();					//绘画界面 
	void display();					//画下一个方块的界面
	void _display(); 					//消除下一方块的界面 
	void move();						//键盘响应 
	int _turnshape(int);				//检测是否可以变形 
	void turnshape(int); 				//更改形状 
	void _draw();				   		//删除原来图像 
	void draw();						//画新的图像 
	int _check(int, char);				//检查左右下方是否可以移动 
	void check();						//检查每行是否满格 
	void clear(int);					//清除满格的行 
	int  end();						//判断是否结束 
};
int Terix::end(){
	if (map[4][1] == 1 || map[5][1] == 1)return 1;
	else return 0;
}
void Terix::clear(int j){
	for (int i = 1; i <= 10; i++){
		gotoxy(i, j); std::cout << "  ";
		map[i][j] = 0;
	}
	for (; j>0; j--){
		for (int i = 1; i <= 10; i++){
			if (map[i][j] == 1){
				gotoxy(i, j); cout << "  ";
				map[i][j] = 0;
				gotoxy(i, j + 1); std::cout << "▉";
				map[i][j + 1] = 1;
			}
		}
	}
	score += 10;
	for (int i = 0; i<4; i++){
		gotoxy(_right - 1, 10 + _down);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		std::cout << "score:" << score;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	}
}
void Terix::display(){
	for (int i = 0; i<4; i++){
		gotoxy(sharp[next][2 * i] + _right, sharp[next][2 * i + 1] + _down);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
		std::cout << "▉";
	}
	for (int i = 0; i<4; i++){
		gotoxy(_right - 1, 10 + _down);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		std::cout << "score:" << score;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	}
}
void Terix::_display(){
	for (int i = 0; i<4; i++){
		gotoxy(sharp[next][2 * i] + _right, sharp[next][2 * i + 1] + _down);
		std::cout << "  ";
	}

}
void Terix::check(){
	for (int j = 1; j<19; j++){
		if (map[1][j] == 1 && map[2][j] == 1 && map[3][j] == 1 && map[4][j] == 1 &&
			map[5][j] == 1 && map[6][j] == 1 && map[7][j] == 1 && map[8][j] == 1 &&
			map[9][j] == 1 && map[10][j] == 1)
			clear(j);
	}
}
void Terix::create(){
	_display();
	right = 5; down = 1;
	id = next;
	next = rand() % 7;
	switch (next){
	case 0:next = 0; break;
	case 1:next = 2; break;
	case 2:next = 3; break;
	case 3:next = 7; break;
	case 4:next = 11; break;
	case 5:next = 13; break;
	case 6:next = 15; break;
	}
	display();
}
Terix::Terix(){
	srand(time(NULL));
	right = 5; down = 1;
	_right = 17; _down = 4;
	id = 15; next = 2;
	score = 0;
	for (int i = 0; i<12; i++){
		for (int j = 0; j<20; j++){
			if (i == 0 || i == 11 || j == 0 || j == 19)map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	for (int i = 13; i<23; i++){
		for (int j = 0; j<10; j++){
			if (i == 13 || i == 22 || j == 0 || j == 9){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				gotoxy(i, j); std::cout << "▉";
			}
		}
	}
	for (int i = 13; i<23; i++){
		for (int j = 11; j<20; j++){
			if (i == 13 || i == 22 || j == 11 || j == 19){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				gotoxy(i, j); std::cout << "▉";
			}
		}
	}
}
void Terix::initial(){
	for (int i = 0; i<12; i++){
		for (int j = 0; j<20; j++){
			if (map[i][j] == 1){
				gotoxy(i, j); std::cout << "▉";
			}
		}
	}

}
void Terix::draw(){
	for (int i = 0; i<4; i++){
		gotoxy(sharp[id][2 * i] + right, sharp[id][2 * i + 1] + down);
		std::cout << "▉";
	}
}
void Terix::_draw(){
	for (int i = 0; i<4; i++){
		gotoxy(sharp[id][2 * i] + right, sharp[id][2 * i + 1] + down);
		std::cout << "  ";
	}
}
void Terix::turnshape(int _shape){

	switch (_shape){
	case 0:_shape = 1; break;
	case 1:_shape = 0; break;

	case 2:_shape = 2; break;

	case 3:_shape = 4; break;
	case 4:_shape = 5; break;
	case 5:_shape = 6; break;
	case 6:_shape = 3; break;

	case 7:_shape = 8; break;
	case 8:_shape = 9; break;
	case 9:_shape = 10; break;
	case 10:_shape = 7; break;

	case 11:_shape = 12; break;
	case 12:_shape = 11; break;

	case 13:_shape = 14; break;
	case 14:_shape = 13; break;

	case 15:_shape = 16; break;
	case 16:_shape = 17; break;
	case 17:_shape = 18; break;
	case 18:_shape = 15; break;
	}
	if (_turnshape(_shape) == 0)
		id = _shape;
}
int Terix::_turnshape(int id){
	int error = 0;
	for (int i = 0; i<4; i++){
		if (map[sharp[id][2 * i] + right][sharp[id][2 * i + 1] + down] == 1)return 1;
	}
	return error;
}
int Terix::_check(int id, char u){
	int error = 0;
	switch (u){
	case 'a':		for (int i = 0; i<4; i++){
						if (map[sharp[id][2 * i] + right - 1][sharp[id][2 * i + 1] + down] == 1)return 1;
	}break;

	case 's':		for (int i = 0; i<4; i++){
						if (map[sharp[id][2 * i] + right][sharp[id][2 * i + 1] + down + 1] == 1){
							return 1;
						}
	}break;

	case 'd':		for (int i = 0; i<4; i++){
						if (map[sharp[id][2 * i] + 1 + right][sharp[id][2 * i + 1] + down] == 1)return 1;
	}break;
	}
	return error;
}
void Terix::move(){
	char u = 's';
	if (_kbhit() == 0){
		v = 300;
		if (_check(id, u) == 0){
			_draw();
			down++;
			draw();
		}
		if (_check(id, u) != 0){
			for (int i = 0; i<4; i++){
				map[sharp[id][2 * i] + right][sharp[id][2 * i + 1] + down] = 1;
			}
			create();
		}
	}
	if (_kbhit() != 0){
		u = getch();
		if (u == 's')v = 100;
		if (u != 's')v = 300;
		switch (u){
		case 'a':		if (_check(id, u) == 0){
							_draw();
							right--;
							draw();
		}
						else u = 's';
						break;

		case 's':		if (_check(id, u) == 0){
							_draw();
							down++;
							draw();
							Sleep(1);
		}
						if (_check(id, u) != 0){
							for (int i = 0; i<4; i++){
								map[sharp[id][2 * i] + right][sharp[id][2 * i + 1] + down] = 1;
							}
							create();
						}
						break;

		case 'd':		if (_check(id, u) == 0){
							_draw();
							right++;
							draw();
		}
						else u = 's';
						break;

		case 'w':		_draw();
			turnshape(id);
			draw();
			break;
		}
	}
};
int main(){
	Terix c;
	int d = 0;
	c.initial();
	c.display();
	while (d == 0){
		c.draw();
		c.move();
		c.check();
		Sleep(v);
		d = c.end();
	}
	gotoxy(20, 20); cout << endl;


	return 0;
}

