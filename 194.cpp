#include <iostream>
#include<windows.h> 
#include<process.h> 
#include<ctime>
#include<cstdlib>
#include <conio.h> 
using namespace std;
int gotoxy(int x,int y)
{
COORD c;
c.X=4*y;c.Y=x;
SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE),c);
return 0;
}
struct map{
	int num;
	
};
int count=0;
class _2048{
	private:
		map w1[4][4],w2[4][4];
	 public:
	 	_2048();
	 	int move();
	 	void create();
	 	void display();
	 	int end(int);
};

_2048::_2048(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
  		w1[i][j].num=0;
	}
}
	srand(time(NULL));
	int x,y;
	
	
		x=0;
		y=0;
		
		w1[x][y].num=2;
	
		x=1;
		y=1;
		
		w1[x][y].num=2;
	
		x=0;
		y=2;
		
		w1[x][y].num=4;
		
		x=0;
		y=3;
		
		w1[x][y].num=4;
		

}
void _2048::create(){
	int a,b;
	srand(time(NULL));
	while(1){
		a=rand()%4;
		b=rand()%4;
	if(w1[a][b].num==0)break;
	}
		
	int v=rand()%2;	
	if(v==1)w1[a][b].num=2;
	if(v==0)w1[a][b].num=4;
	
	gotoxy(10,10);cout<<a<<"  "<<b;
	
}
int _2048::move(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){	
  			w2[i][j].num=w1[i][j].num;
		}
	}
if(_kbhit()==0){
	return 2;		
	}
char w='z';
	if(_kbhit()!=0){
	w=getch();		
	}

if(w=='d'){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(w1[i][j].num!=0){	
				for(int h=j+1;h<4;h++){
					if(w1[i][h].num!=0&&w1[i][h].num==w1[i][j].num){
					
						w1[i][j].num=0;
						w1[i][h].num=2*(w1[i][h].num);
						j=h;
						break;
					}
					if(w1[i][h].num!=0&&w1[i][h].num!=w1[i][j].num){
						
						int x;
						x=w1[i][j].num;
						w1[i][j].num=0;
						j=h-1;
						w1[i][j].num=x;
						
						break;
					}
					
				}
			}
		}
	}


	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(w1[i][j].num==0){
				for(int h=j-1;h>=0;h--){
					if(w1[i][h].num!=0){
						w1[i][j].num=w1[i][h].num;
						w1[i][h].num=0;
						break;
					}
				}
			}
		}
	}

}
if(w=='a'){
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(w1[i][j].num!=0){	
				for(int h=j-1;h>=0;h--){
					if(w1[i][h].num!=0&&w1[i][h].num==w1[i][j].num){
						
						w1[i][j].num=0;
						w1[i][h].num=2*(w1[i][h].num);
						j=h;
						break;
					}
					if(w1[i][h].num!=0&&w1[i][h].num!=w1[i][j].num){
						
						
						int x;
						x=w1[i][j].num;
						w1[i][j].num=0;
						j=h+1;
						w1[i][j].num=x;
						
						
						break;
					}
					
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(w1[i][j].num==0){
				for(int h=j+1;h<4;h++){
					if(w1[i][h].num!=0){
						
						w1[i][j].num=w1[i][h].num;
						w1[i][h].num=0;
						break;
						
					}
				}
			}
		}
	}

	
	
	
	
	
	
}
if(w=='s'){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(w1[j][i].num!=0){	
				for(int h=j+1;h<4;h++){
					if(w1[h][i].num!=0&&w1[h][i].num==w1[j][i].num){
						
						w1[j][i].num=0;
						w1[h][i].num=2*(w1[h][i].num);
						j=h;
						break;
					}
					if(w1[h][i].num!=0&&w1[h][i].num!=w1[j][i].num){
						
						
						int x;
						x=w1[j][i].num;
						w1[j][i].num=0;
						j=h-1;
						w1[j][i].num=x;
						
						
						break;
					}
					
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(w1[j][i].num==0){
				for(int h=j-1;h>=0;h--){
					if(w1[h][i].num!=0){
						
						w1[j][i].num=w1[h][i].num;
						w1[h][i].num=0;
						break;
					}
				}
			}
		}
	}
}
if(w=='w'){
	for(int i=0;i<4;i++){
		for(int j=3;j>=0;j--){
			if(w1[j][i].num!=0){	
				for(int h=j-1;h>=0;h--){
					if(w1[h][i].num!=0&&w1[h][i].num==w1[j][i].num){
						
						w1[j][i].num=0;
						w1[h][i].num=2*(w1[h][i].num);
						j=h;
						break;
					}
					if(w1[h][i].num!=0&&w1[h][i].num!=w1[j][i].num){
						
						int x;
						x=w1[j][i].num;
						w1[j][i].num=0;
						j=h+1;
						w1[j][i].num=x;
					
					
						break;
					}
					
				}
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(w1[j][i].num==0){
				for(int h=j+1;h<4;h++){
					if(w1[h][i].num!=0){
						
						w1[j][i].num=w1[h][i].num;
						w1[h][i].num=0;
						break;
					}
				}
			}
		}
	}
}

for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
		if(w1[i][j].num!=w2[i][j].num){
			return 0;
		}
	}
}
	return 1;
}

int _2048::end(int a){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(w1[i][j].num==2048){
				gotoxy(5,6);cout<<"游戏成功";return 1;	
			}
		}
	}
	if(a==1){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(w1[i][j].num==0){
					return 0;
				}
			
			}
		}
	}
	if(a==2)return 0;
	if(a==0)return 0;
	gotoxy(5,6);cout<<"游戏失败";return 1;	
}
void _2048::display(){
	gotoxy(0,0);
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			switch(w1[i][j].num){
	case 0:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
			break;
	case 2:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			break;
	case 4:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
			break;
	case 8:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
			break;		
	case 16:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED);
			break;
	case 32:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
			break;	
	case 64:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
			break;
	case 128:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
			break;
	case 256:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
			break;
	case 512:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
			break;		
	case 1024:	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED);
			break;
		
		}	
	
	
			cout<<w1[i][j].num<<'\t';
		}
		cout<<endl;
	}
}
int main(){
	_2048 d;
	int a=1;
	int b=0;
	while(b!=1){
		d.display();
		a=d.move();
		b=d.end(a);
		if(a==0){
			d.create();
		}
		Sleep(100);
	}
	
	gotoxy(5,6);
	
	
	return 0;
}
