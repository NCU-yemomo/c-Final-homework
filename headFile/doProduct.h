#include "type.h"
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <Windows.h>
#include<time.h>
#include "Cursor.h"

//选择用户，用户可以输入对应的用户名返回对应的用户id
int choseUser(User *users,int userNum){
    
    char merchantName[20];
    int state=1;
    while (1){
        fflush(stdin);
        fgets(merchantName,20,stdin);
        for (int i=0;i<userNum;i++){
            //进行比较，
            if (strcmp(merchantName,users[i].username)==0){
                return users[i].id;
            }
        }
        return -1;
    }
}
/*寻找对应的用户*/
int findUserProductIndex(int userId,UserProduct *userProducts,int userNum){
    for (int i=0;i<userNum;i++){
        if (userProducts[i].userid==userId){
            return i;
        }
    }
    return -1;
}
//上架商品
void productsUpon(int userId,UserProduct *userUponProducts,int usersNum){
    //在所有用户上传的商品列表里面找该商户
    int i=findUserProductIndex(userId,userUponProducts,usersNum);
    cursorJump(40,3);
    if (i==-1){
        printf("您不是一名商户,或许需要重新登录");
        cursorJump(40,4);
        printf("按任意键继续:");
        goOn();
        return;
    }
    //找到该商户后，找到该商户的商品列表,寻找未上架的
    int productNum;
    //先检测上架是否满了
    if (userUponProducts[i].productUponNum==10){
        printf("您已经上架了10个商品,无法再上架了");
        cursorJump(40,4);
        printf("按任意键继续:");
        goOn();
        return;
    }
    for (int j=0;j<10;j++){
        if (userUponProducts[i].uponProduct[j].id==-1){
            //找到未上架的商品列表，进行上架
            productNum=j;
            break;
        }
    }
    //输入商品信息
    cursorJump(18,3);
    printf("-----------------上架商品----------------------\n");
    cursorJump(25,5);
    printf("商品名字:");
    cursorJump(25,7);
    printf("请输入商品价格(单位/元):");
    cursorJump(25,9);
    printf("商品描述:");
    cursorJump(35,5);
    fflush(stdin);
    fgets(userUponProducts[i].uponProduct[productNum].name,20,stdin);
    cursorJump(50,7); 
    scanf("%d",&userUponProducts[i].uponProduct[productNum].price);
    cursorJump(35,9);
    fflush(stdin);
    fgets(userUponProducts[i].uponProduct[productNum].description,20,stdin);
    //根据商品列表索引，存储商品id，id从1开始
    userUponProducts[i].uponProduct[productNum].id=productNum+1;
    system("cls");
    cursorJump(18,3);
    printf("上架成功!\n");
    cursorJump(18,4);
    printf("您上架的商品如下:\n");
    cursorJump(18,5);
    printf("-----------------------------");
    cursorJump(28,6);
    printf("    名称:%s",userUponProducts[i].uponProduct[productNum].name);
    cursorJump(28,7);
    printf("    价格:%d",userUponProducts[i].uponProduct[productNum].price);
    cursorJump(28,8);
    printf("    描述:%s",userUponProducts[i].uponProduct[productNum].description);
    cursorJump(18,9);
    printf("-----------------------------\n");
    cursorJump(18,10);
    printf("按任意键继续:");
    goOn();
    //商品数量加1；
    userUponProducts[i].productUponNum+=1;
}


//查看商品
int showProduct(int merchantId,UserProduct *userProduct,int userNum){
    //寻找该商户
    system("cls");
    int i=findUserProductIndex(merchantId,userProduct,userNum);
    if (i==-1){
        cursorJump(18,3);
        printf("您不是一名商户,或许需要重新登录");
        cursorJump(18,4);
        printf("按任意键继续:");
        goOn();
        return -1;
    }
    //进行展示      
    int productNum=userProduct[i].productUponNum;
    //检验是否有商品
    if (productNum==0){
        cursorJump(18,3);
        printf("这名商户没有商品上架 OVO!!\n");
        cursorJump(18,4);
        printf("按任意键继续:");
        goOn();
        return -1;
    }
    cursorJump(18,3);
    printf("-------------商品列表-----------------\n");
    cursorJump(18,5);
    printf("id     名称          价格        描述");
    int num=0;
    for (int j=0;j<10;j++){
        if (userProduct[i].uponProduct[j].id!=-1){
            cursorJump(18,6+j);
            printf("%d",userProduct[i].uponProduct[j].id);
            cursorJump(25,6+j);
            printf("%s",userProduct[i].uponProduct[j].name);
            cursorJump(40,6+j);
            printf("%d",userProduct[i].uponProduct[j].price);
            cursorJump(50,6+j);
            printf("%s",userProduct[i].uponProduct[j].description);
            num++;
        }
    }
    cursorJump(18,7+num);
    printf("-------------------------------\n");
    cursorJump(18,8+num);
    printf("按任意键继续:");
    goOn();
    return 1;
}


//下架商品
void productsSoldOut(int userId,UserProduct *userProducts,int userNum,int productId,int select){
    //先根据用户id找到用户
    int i=findUserProductIndex(userId,userProducts,userNum);
    if (i==-1){
        if (select==0){
            cursorJump(18,4);
            printf("您的登录已过期,或许需要重新登录");
            cursorJump(18,5);
            printf("按任意键继续:");
            goOn();
            return;
        }
        // if (select==1){
        //     cursorJump(18,4);
        //     printf("您想购买的商品用户已经注销,无法购买");
        //     cursorJump(18,5);
        //     printf("按任意键继续:");
        //     goOn();
        //     return;
        // }
        return;
    }
    if (userProducts[i].productUponNum==0){
        if (select==0){
            cursorJump(18,4);
            printf("您没有商品上架,无法下架");
            cursorJump(18,5);
            printf("按任意键继续:");
            goOn();
            return;
        }else{
            cursorJump(18,4);
            printf("您想购买的商品已经被购买,无法购买");
            cursorJump(18,5);
            printf("按任意键继续:");
            return;
        }
    }
    //寻找该商品
    for (int j=0;j<10;j++){
        if (userProducts[i].uponProduct[j].id==productId){
            //找到该商品，进行下架
            userProducts[i].uponProduct[j].id=-1;
            userProducts[i].productUponNum-=1;
            if (select==0){
                cursorJump(18,4);
                printf("成功下架\n");
                cursorJump(18,5);
                printf("按任意键继续:");
                goOn();
            }
            return;
        }
    }
    if (select==0){
        cursorJump(18,4);
        printf("对不起，您输入的商品id不存在\n");
        printf("按任意键继续:");
        goOn();
    }
    if (select==1){
        printf("对不起，您输入的商品已经被购买\n");
    }
}


//加入购物车
void addCart(int userId,int merchantId,UserProduct *userProduct,int userNum){
    //寻找要购买的商户
    int productId;
    int indexUser;
    int indexMerchant;
    int productCartNum;
    //存储对应的索引
    indexMerchant=findUserProductIndex(merchantId,userProduct,userNum);
    indexUser=findUserProductIndex(userId,userProduct,userNum);
    if (indexMerchant==-1||indexUser==-1){
        cursorJump(18,4);
        printf("对不起，您输入的商家或用户id不存在\n");
        cursorJump(18,5);
        printf("按任意键继续:");
        goOn();
        return;
    } 
    cursorJump(18,4);
    printf("请输入您想加入购物车的商品id");
    scanf("%d",&productId);
    for (int j=0;j<10;j++){
        if (userProduct[indexMerchant].uponProduct[j].id==productId){
            //将商品加入购物车,进行深拷贝
            if (userProduct[indexUser].productCartNum==10){
                cursorJump(18,5);
                printf("购物车已满，无法加入购物车");
                cursorJump(18,6);
                printf("按任意键继续:");
                goOn();
                return;
            }
            for (int k=0;k<10;k++){
                if (userProduct[indexUser].cartProduct[k].id==-1){
                    //找到未上架的商品列表，进行上架
                    productCartNum=k;
                    break;
                }
            }
            userProduct[indexUser].cartProduct[productCartNum].id=productCartNum+1;
            strcpy(userProduct[indexUser].cartProduct[productCartNum].name,userProduct[indexMerchant].uponProduct[j].name);
            userProduct[indexUser].cartProduct[productCartNum].price=userProduct[indexMerchant].uponProduct[j].price;
            strcpy(userProduct[indexUser].cartProduct[productCartNum].description,userProduct[indexMerchant].uponProduct[j].description);
            //存入商户的id，便于之后购买的时候搜寻，进行假双向通讯
            userProduct[indexUser].cartProduct[productCartNum].fromId=merchantId;
            userProduct[indexUser].cartProduct[productCartNum].fromProductId=productId;
            //购物车商品数量加1
            userProduct[indexUser].productCartNum+=1;
            cursorJump(18,5);
            printf("成功加入购物车\n");
            cursorJump(18,6);
            printf("按任意键继续:");
            goOn();
            return;
        }
    }
}

//展示购物车
int showCart(int userId,UserProduct *userProduct,int userNum){
    //寻找该用户
    int i=findUserProductIndex(userId,userProduct,userNum);
    //进行判断
    if (i==-1){
        cursorJump(18,4);
        printf("对不起，你所搜寻的用户不存在\n");
        return -1;
    }
    //进行展示
     
    int productNum=userProduct[i].productCartNum;
    if (productNum==0){
        cursorJump(18,4);
        printf("啊哦，购物车为空！(OVO!!)\n");
        cursorJump(18,5);
        printf("按任意键继续:");
        goOn();
        return -1;
    }
    cursorJump(18,4);
    printf("---------------购物车---------------------\n");   
    cursorJump(18,5);
    printf("id     名称          价格        描述");  
    //检验此烂是否有商品
    for (int j=0;j<10;j++){
        if (userProduct[i].cartProduct[j].id!=-1){
            cursorJump(18,6+j);
            printf("%d",userProduct[i].cartProduct[j].id);
            cursorJump(25,6+j);
            printf("%s",userProduct[i].cartProduct[j].name);
            cursorJump(40,6+j);
            printf("%d",userProduct[i].cartProduct[j].price);
            cursorJump(50,6+j);
            printf("%s",userProduct[i].cartProduct[j].description);
        }
    }
    cursorJump(18,6+productNum);
    printf("-------------------------------\n");
    cursorJump(18,7+productNum);
    printf("按任意键继续:");
    goOn();
    return 0;
}

//删除购物车商品
void deleteCart(int userId,UserProduct *userProducts,int userNum,int productId,int select){
    //先根据用户id找到用户
        int i=findUserProductIndex(userId,userProducts,userNum);
        if (i==-1){
            cursorJump(18,4);
            printf("登录已过期，请重新登录\n");
            cursorJump(18,5);
            printf("按任意键继续:");
            goOn();
            return;
        }
        if (userProducts[i].productCartNum==0){
            cursorJump(18,4);
            printf("你的购物车为空！！无法删除\n");
            cursorJump(18,5);
            printf("按任意键继续:");
            goOn();
            return;
        }
        //寻找该商品
        for (int j=0;j<10;j++){
            if (userProducts[i].cartProduct[j].id==productId){
                //找到该商品，进行下架
                userProducts[i].cartProduct[j].id=-1;
                userProducts[i].productCartNum-=1;
                if (select==0){
                    cursorJump(18,4);
                    printf("成功删除!\n");
                    cursorJump(18,5);
                    printf("按任意键继续:");
                    goOn();
                    return;
                }
                return;
            }
        }
        cursorJump(18,4);
        printf("对不起，这个商品不存在\n");
        cursorJump(18,5);
        printf("按任意键继续:");
        goOn();

}   
//在所有用户商品中找对应索引
void purchaseProduct(int userId,UserProduct *userProducts,int userNum){
    int indexUser=findUserProductIndex(userId,userProducts,userNum);
    if (indexUser==-1){
        cursorJump(18,4);
        printf("用户不存在\n");
        cursorJump(18,5);
        printf("按任意键继续:");
        goOn();
        return;
    }
    int productId;
    int indexCart;
    int state=showCart(userId,userProducts,userNum);
    if (state==-1){
        return;
    }
    while (1){
        cursorJump(18,4);
        printf("请输入你想购买的商品id:");
        scanf("%d",&productId);
        int findIndexCart(int productId,UserProduct *userProducts,int i){
            for (int j=0;j<10;j++){
                //先找到该商家，然后在商家的商品列表中找到该商品 
                if (userProducts[i].cartProduct[j].id==productId){
                    return j;
                }
            }
            return -1;
        }
        //找到购物车对应索引
        indexCart=findIndexCart(productId,userProducts,indexUser); 
        if (indexCart==-1){
            cursorJump(18,5);
            printf("抱歉，您所购买的商品不在购物车内，请重新输入:\n");
            cursorJump(18,6);
            printf("按任意键继续:");
            goOn();
        }else{
            break;
        }
    }

    int formProductId=userProducts[indexUser].cartProduct[indexCart].fromProductId;
    int merchantId=userProducts[indexUser].cartProduct[indexCart].fromId;
    productsSoldOut(merchantId,userProducts,userNum,productId,1);//删除对应的上架
    deleteCart(userId,userProducts,userNum,productId,1);//删除对应的购物车
    cursorJump(18,5);
    printf("成功购买!\n");
    cursorJump(18,6);
    printf("按任意键继续:");
    goOn();

}