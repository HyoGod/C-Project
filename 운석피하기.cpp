#include <stdio.h>
#include <windows.h> //������ 
#include <conio.h> //Ű�����Է�(����Ű) 
 
#define Xmax 79 //X�� 
#define Ymax 1 //Y�� 

void move_arrow_key(char key, int *x, int *y, int x_b, int y_b){
    int crt ;
	switch(key){
    case 72: // ����Ű �� 
        break;
    case 75: // ����Ű ����
	        *x=*x-1;
        if(*x<1) *x=1; 
    	crt = key;
    	
        break;
    case 77: // ����Ű ������ 
	        *x=*x+1;
        if(*x<1) *x=1; 
        break;
    case 80: // ����Ű �� 

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
    	
    	system("mode con:lines=25  cols=82"); //�ܼ� â ���μ���ũ������ 
	COORD Pos={x-1,y+1};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
	
        gotoxy(x,y);
        printf("��");
        key=getch();
        move_arrow_key(key, &x,&y,Xmax, Ymax);
        if(x>=80){
        	
        	x=80;
        	y=25;
		}    	
    }while(key!=27);
}
