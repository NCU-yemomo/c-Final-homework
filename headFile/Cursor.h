#ifndef CURSOR_H
#define CURSOR_H
#include "type.h"
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <Windows.h>
#include<time.h>

//移动光标函数
void cursorJump(int x, int y) {
	COORD pos; //定义光标位置的结构体变量
	pos.X = x; //横坐标设置
	pos.Y = y; //纵坐标设置
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
	SetConsoleCursorPosition(handle, pos); //设置光标位置
}
//按任意进行函数
void goOn(){
    char gh=getch();
     if (gh){
        system("cls");
     }
}
//获取登录与注册时的光标位置，后期可以改成获取光标位置
int getCursor(int height,int width,int cursorNum,int cursorNumMax){
    int heights=height;
        while (1){
            char gh=getch();
            switch(gh){
                case DOWN:
                    if (cursorNum==cursorNumMax){
                        break;
                    }
                    else{
                        cursorNum++;
                        heights+=2;
                        cursorJump(width,heights);
                        break;
                    }
                case UP:
                    if (cursorNum==0){
                        break;
                    }
                    else{
                        cursorNum--;
                        heights-=2;
                        cursorJump(width,heights);
                        break;
                    }
                case ENTER:
                    return cursorNum+1;
                    
            }
        }
    }
#endif
