#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./headFile/type.h"
#include "./headFile/Cursor.h"
#include "./headFile/regLogin.h"
#include "./headFile/doProduct.h"
#include "./headFile/showInfo.h"
#include "./headFile/readWriteFile.h"
//全部用中文printf
int main(){
    //定义数据
    int select;
    
    int userId;//当前登录的用户id
    int merchantId;
    int productId;
    int innerState;//每个函数返回的状态判断
    //程序说明
    int userNum;//用户数量
    int state;//作为以后每个循环退出的判断量
    //定义用户，之后会做动态内存规划
    //每次注册增加一个用户
    User *users=NULL;//用户结构体指针
    UserProduct *userProduct=NULL;//用户上架商品列表
    //判断是否需要初始化
    FILE *fp=fopen("./bin/userNum.bin","rb");
    if (fp==NULL){
        //创建文件,初始化
        userNum=0;
        userProduct=(UserProduct*)malloc(sizeof(UserProduct)*0);
        users = (User*)malloc(sizeof(User)*0);
        //保存初始化数据
        saveFileUserNum(userNum);
        saveFileUserProduct(userNum,userProduct);
        saveFileUser(userNum,users);
        fclose(fp);
    }else{
        //读取文件
        fread(&userNum,sizeof(int),1,fp);
        fclose(fp);
        userProduct=(UserProduct*)malloc(sizeof(UserProduct)*userNum);
        users = (User*)malloc(sizeof(User)*userNum);
        //读取文件
        readFileUserProduct(userNum,userProduct);
        readFileUser(userNum,users);
        // printf("%d",userNum);
        // printf("%s",users[0].username);//无输出
        // printf("按任意键继续");
        // goOn();
    }
    
    openAppShow();
    showAppInfo();
    //页面中间
    cursorJump(18,2);
    printf("-----------这是一个商店系统，欢迎您的使用------------\n");
    //用户注册和登录
    while (1){
        select=0;
        cursorJump(29,4);
        printf("请输入您的选择:");
        cursorJump(29,5);
        printf("请将光标位于您想选择的选项上（键盘上下可控制光标）,如果确定请按Enter");
        cursorJump(29,7);
        printf("1.登录");
        cursorJump(29,9);
        printf("2.注册");
        cursorJump(18,11);
        printf("***************************************************");
        int height=7;
        int width=36;
        cursorJump(width,height); 
        int cursorNum=0;
        int maxCursorNum=1;
        select=getCursor(height,width,cursorNum,maxCursorNum);
        system("cls");
        if (select==2){
            //动态内存进行扩宽,每次扩宽一个用户，先除法计算在加1
            userNum++;
            //内存修改必须在主函数进行，因为函数内部的话指针指向的内存会小时
            users=(User*)realloc(users,sizeof(User)*(userNum));
            userProduct=(UserProduct*)realloc(userProduct,sizeof(UserProduct)*(userNum));

            regis(users,userProduct,userNum);
        }else if(select==1){
            userId=login(users,userNum);
            break;
        }else{
            printf("请输入数字1或数字2:");        
        }
        //先创建用户上架的仓库
}
   
    while (1){
        cursorJump(18,3);
        printf("-----------------商店选项----------------------\n");
        cursorJump(29,4);
        printf("在选项中想退出请按ese");
        //前期先自己本地一次性存着，后期可以考虑使用mysql数据库来存储把。CursorJump(29,4);
        cursorJump(29,5);
        printf("1.上架商品\n");
        cursorJump(29,7);
        printf("2.下架商品\n");
        cursorJump(29,9);
        printf("3.浏览某人的商品\n");
        cursorJump(29,11);
        printf("4.将商品加入购物车\n");
        cursorJump(29,13);
        printf("5.查看购物车\n");
        cursorJump(29,15);
        printf("6.删除购物车里面的商品\n");
        cursorJump(29,17);
        printf("7.购买商品\n");
        cursorJump(29,19);
        printf("8.切换用户\n");
        cursorJump(29,21);
        printf("9.退出\n");
        cursorJump(29,23);
        printf("0.关于与帮助\n");
        cursorJump(18,25);
        printf("-------------------------------------------\n");
        int height=5;
        int width=28;
        cursorJump(width,height);
        int cursorNum=0;
        int maxCursorNum=9;
        select=getCursor(height,width,cursorNum,maxCursorNum);
        select=select%10;
        system("cls");
        switch (select){
            case 0:
                printf("请输入数字(1.关于/2.帮助/3.返回)");
                scanf("%d",&select);
                switch(select){
                    case 1:
                        about();
                        break;
                    case 2:
                        help();
                        break;
                    case 3:
                        break;
                }
                break;
            case 1:
                //上架商品,传入用户id和用户上架商品的结构体数组，这样才能找到嘛
                productsUpon(userId,userProduct,userNum);
                break;
            case 2:
                //下架商品
                state=showProduct(userId,userProduct,userNum);
                if (state==-1){
                    break;
                }
                cursorJump(18,3);
                printf("请输入您要下架的商品id:\n ");
                cursorJump(42,3);
                scanf("%d",&productId);
                productsSoldOut(userId,userProduct,userNum,productId,0);
                break;
            case 3:
                //选择商品
                while (1){
                    cursorJump(29,4);
                    printf("请输入您想查看的商家名:");
                    merchantId=choseUser(users,userNum);
                    if (merchantId==-1){
                        cursorJump(29,5);
                        printf("请输入正确的商家名:\n");
                        cursorJump(29,6);
                        printf("按任意键继续");
                        goOn();
                        system("cls");
                    }
                    else{
                        system("cls");
                        break;
                    }
                }
                showProduct(merchantId,userProduct,userNum);
                break;
            //加入购物车
            case 4:
                while (1){
                    cursorJump(29,4);
                    printf("请输入您想加入商品的商家名:");
                    merchantId=choseUser(users,userNum);
                    if (merchantId==-1){
                        cursorJump(29,5);
                        printf("您输入的商家名不存在，请输入正确的商家名:\n");
                        cursorJump(29,6);
                        printf("按任意键继续");
                        goOn();
                    }else{
                        system("cls");
                        break;
                    }
                }
                //看看能不能两者兼顾,正常情况下这里是个接口，但是没有网络通信，临时先这样，此处可以自己购买自己的商品
                addCart(userId,merchantId,userProduct,userNum);
                break;
            //查看购物车
            case 5:
                showCart(userId,userProduct,userNum);
                break;
            //删除购物车
            case 6:
                state=showCart(userId,userProduct,userNum);
                if (state==-1){
                    break;
                }
                cursorJump(18,3);
                printf("请输入您想删除的商品id:");
                scanf("%d",&productId);
                deleteCart(userId,userProduct,userNum,productId,0);
                break;
            case 7:
                purchaseProduct(userId,userProduct,userNum);
                break;
            case 8:
             //似乎不能函数封装，realloc需要在主函数里面进行，不然返回的指针无所指引
             //保存数据
                saveFileUserNum(userNum);
                saveFileUserProduct(userNum,userProduct);
                saveFileUser(userNum,users);
                 while (1){
                    select=0;
                    cursorJump(29,4);
                    printf("请输入您的选择:");
                    cursorJump(29,5);
                    printf("请将光标位于您想选择的选项上（键盘上下可控制光标）,如果确定请按Enter");
                    cursorJump(29,7);
                    printf("1.登录");
                    cursorJump(29,9);
                    printf("2.注册");
                    cursorJump(18,11);
                    printf("***************************************************");
                    int height=7;
                    int width=36;
                    cursorJump(width,height); 
                    int cursorNum=0;
                    int maxCursorNum=1;
                    select=getCursor(height,width,cursorNum,maxCursorNum);
                    system("cls");
                    if (select==2){
                        //动态内存进行扩宽,每次扩宽一个用户，先除法计算在加1
                        userNum++;
                        //内存修改必须在主函数进行，因为函数内部的话指针指向的内存会小时
                        users=(User*)realloc(users,sizeof(User)*(userNum));
                        userProduct=(UserProduct*)realloc(userProduct,sizeof(UserProduct)*(userNum));

                        regis(users,userProduct,userNum);
                    }else if(select==1){
                        userId=login(users,userNum);
                        break;
                    }else{
                        printf("请输入数字1或数字2:");        
                    }
        //先创建用户上架的仓库
                }
                break;
            case 9:
                //修改文件
                saveFileUserNum(userNum);
                saveFileUserProduct(userNum,userProduct);
                saveFileUser(userNum,users);
                return 0;
            default:
                printf("请输入正确的数字:\n");
                break; 
    }
}
}

