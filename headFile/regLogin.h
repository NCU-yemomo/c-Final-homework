#include "type.h"
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <Windows.h>
#include<time.h>

#include "./Cursor.h"
//注册函数
void regis(User *users,UserProduct *userProducts,int length){
    User person;
    
    
    //输入用户名，并且检测是否有重复输入
    while (1){
        cursorJump(40,3);
        printf("-----------注册------------");
        cursorJump(49,5);
        printf("用户名:");
        cursorJump(49,7);
        printf("密码:");
        cursorJump(40,9);
        printf("------------------------------");
        cursorJump(56,5);
        int state=0;
        fflush(stdin);//清空缓存
        fgets(person.username,20,stdin);
        cursorJump(55,7);
    
        for (int i=0;i<length;i++){
            //检测是否存有重复用户名
            if (strcmp(person.username,users[i].username)==0){

                cursorJump(44,11);
                printf("\033[0;31m");
                printf("您输入的用户名已经被使用,请重新输入(按任意键继续):");
                printf("\033[0;m");
                goOn();
                break;
            }else{
                state=1;
                break;
            }
        }
        if (state==1){
            break;
        }
    }
    fgets(person.password,20,stdin);
    cursorJump(44,11);
    printf("注册成功!!!,用户名:%s",person.username);
    //根据数组长度存储id
    person.id=length;
    //最后一个添加此用户
    users[length-1]=person;
    //创建该用户上传的商品储存位置
    //建立一个用户上传的商品列表仓库,并且初始化
    UserProduct userProduct;
    userProduct.userid=person.id;
    userProduct.productUponNum=0;
    userProduct.productCartNum=0;
    for (int i=0;i<10;i++){
        //id=-1代表没有商品
        userProduct.uponProduct[i].id=-1;
        userProduct.cartProduct[i].id=-1;
    }
    userProducts[length-1]=userProduct;
    cursorJump(44,12);
    printf("按任意键继续:");
    goOn();
}

//登录函数
int login(User *users,int length){
    while (1){
        
        cursorJump(40,3);
        printf("-----------登录------------");
        cursorJump(49,5);
        printf("用户名:");
        cursorJump(49,7);
        printf("密码:");
        cursorJump(40,9);
        printf("------------------------------");
        cursorJump(56,5);
        int state=0;
        char username[20];
        fflush(stdin);//清空缓存
        fgets(username,20,stdin);
        for (int i=0;i<length;i++){
            if (strcmp(username,users[i].username)==0){
                state=1;            
                while (1){
                    system("cls");
                    cursorJump(40,3);
                    printf("-----------登录------------");
                    cursorJump(49,5);
                    printf("用户名:%s",users[i].username);
                    cursorJump(49,7);
                    printf("密码:");
                    cursorJump(40,9);
                    printf("------------------------------");
                    cursorJump(55,7);
                    char password[20];
                    fgets(password,20,stdin);
                    if (strcmp(password,users[i].password)==0){
                        cursorJump(44,11);
                        printf("成功登录!\n");
                        cursorJump(44,12);
                        printf("按任意键继续:");
                        goOn();
                        //返回用户id，便于创建用户上架商品列表
                        return users[i].id;
                    }else{
                        cursorJump(44,11);
                        printf("密码错误,请重新输入(按任意键继续):");
                        goOn();
                    }
                }
            }
        }

        if (state==0){
            cursorJump(44,11);
            printf("您输入的用户名不存在,请重新输入(按任意键继续):");
            goOn();
        }
    }
}
