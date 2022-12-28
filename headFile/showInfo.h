#include "type.h"
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <Windows.h>
#include<time.h>

#include "Cursor.h"
//关于
void about(){
    printf("程序名称：购物商城\n");
    printf("版本:1.0\n");
    printf("开发时间:2020年12月18号-\n");
    printf("作者信息:\n");
    printf("姓名:颜宇航\n");
    printf("学号:8008122218\n");
    printf("专业班级:计算机II类2207班\n");
    printf("按任意键继续");
    goOn();
}
//帮助
void help(){
    printf("使用说明:");
    printf("你可以按照操作注册,登录自己的账号，\
然后与别人进行交易，由于现在是在本地跑，没有数据库因此可能需要多次注册,自己创造多个用户交易\n");
    printf("功能说明:");
    printf("登录后，你可以上下架自己的商品，将他人商品加入购物车，以及购买他人商品\n");
    printf("按任意键继续");
    goOn();
}

//开屏界面
void openAppShow(){
  system("cls");
  // Move the cursor to the specified position and display "小叶工作室"
  
  cursorJump(4, 6);
  printf("       ■                            ■                               ■        ■                  ■ \n");
  cursorJump(4, 7);  
  printf("       ■           ■■■■         ■       ■■■■■■■■    ■■■     ■ ■ ■ ■      ■ ■ ■ ■ ■ ■ ■         \n");
  cursorJump(4, 8); 
  printf("       ■           ■    ■         ■              ■        ■     ■   ■   ■         ■                    ■\n");
  cursorJump(4, 9);              
  printf("   ■  ■   ■      ■    ■  ■■■ ■ ■■■       ■      ■       ■ ■     ■ ■ ■ ■      ■ ■ ■ ■ ■     \n");
  cursorJump(4, 10);      
  printf("■■   ■    ■■   ■■■■         ■              ■               ■        ■                  ■      ■  \n");
  cursorJump(4, 11);
  printf("       ■                            ■              ■               ■        ■ ■ ■ ■        ■■■■■■  \n");
  cursorJump(4, 12);
  printf(" ■    ■                            ■        ■■■■■■■■       ■        ■                     ■     ■\n");
  cursorJump(4, 13);
  printf("   ■  ■                            ■                               ■        ■                     ■\n");
  cursorJump(4, 14);
  printf("     ■■                            ■                               ■        ■             ■■■■■■■■■\n");
  cursorJump(4, 15);
  printf("                                                                      ■        ■     \n");
  cursorJump(32, 16);
  //用终端代码控制颜色
  printf("\033[0;31m");
  printf("按任意键继续");
  //恢复颜色
  printf("\033[0m");
  char ch;
  ch=getch();
  if (ch){
       system("cls");
  }
}
void showAppInfo(){
    //居中
    cursorJump(42,2);
    printf("   ■    ");
    cursorJump(42,3);
    printf("    ■                    ■"); 
    cursorJump(42,4);
    printf(" ■■■■■■■            ■");
    cursorJump(42,5);
    printf("     ■  ■        ■■■■■■■■");
    cursorJump(42,6);
    printf("■■■■■■■■■ ■      ");
    cursorJump(42,7);
    printf("  ■ ■  ■ ■    ■       ■");
    cursorJump(42,8);
    printf("  ■■    ■■    ■       ■■■");
    cursorJump(42,9);
    printf("  ■ ■■■ ■    ■       ■");
    cursorJump(42,10);
    printf("  ■ ■  ■ ■   ■    ■■■■■");
    cursorJump(42,11);
    printf("  ■ ■■■ ■   ■    ■      ■");
    cursorJump(42,12);
    printf("  ■        ■   ■    ■      ■");
    cursorJump(42,13);
    printf("  ■        ■  ■     ■■■■■");
   

    cursorJump(0, 25);
     
      
    printf("版本:1.0\n");
    
    cursorJump(90, 25);
    printf("版权:@2022Ncu-8008122218\n");
    cursorJump(45, 21);
    printf("\033[0;31m");
    printf("按任意键继续");
    //恢复颜色
    printf("\033[0m");
    char ch;
    ch=getch();
    if (ch){
        system("cls");
    }
}