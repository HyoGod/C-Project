#include <stdio.h>
#include <windows.h> //윈도우 
#include <conio.h> //키보드입력(방향키) 
 
#define Xmax 79 //X축 
#define Ymax 1 //Y축 

void move_arrow_key(char key, int *x, int *y, int x_b, int y_b){
    int crt ;
	switch(key){
    case 72: // 방향키 위 
        break;
    case 75: // 방향키 왼쪽
	        *x=*x-1;
        if(*x<1) *x=1; 
    	crt = key;
    	
        break;
    case 77: // 방향키 오른쪽 
	        *x=*x+1;
        if(*x<1) *x=1; 
        break;
    case 80: // 방향키 밑 

        break;
    default:
        return;
    }
 
}
 
void gotoxy(int x, int y){
    COORD Pos={x-1,y-1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}


int main(){
    char key;
    int x=35,y=25,star1=82,star2=1;
    
    do{
    	
    	system("mode con:lines=25  cols=82"); //콘솔 창 가로세로크기조절 
	COORD Pos={x-1,y+1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
	
        gotoxy(x,y);
        printf("Θ");
        key=getch();
        move_arrow_key(key, &x,&y,Xmax, Ymax);
        if(x>=80){
        	
        	x=80;
        	y=25;
		}    	
    }while(key!=27);
}
