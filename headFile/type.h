#ifndef TYPE_H
#define TYPE_H

#define UP 72         //代表向上，其ASCII码为72
#define DOWN 80       //代表向下，其ASCII码为80 
#define LEFT 75       //代表向左，其ASCII码为75
#define RIGHT 77      //代表向右，其ASCII码为77
#define ENTER 13      //代表回车，其ASCII码为13
typedef struct Products
{
    int id;
    char name[20];
    int price;
    char description[20];
}Product;

typedef struct CartProducts{
    int id;
    char name[20];
    int price;
    char description[20];
    //来源商家的id，目的，方便后期双方通知
    int fromId;
    int fromProductId;
}CartProduct;

//定义使用用户
typedef struct Users
{
    char username[20];
    char password[20];
    int id;

}User;
//用户上架商品/购物车
//这个后期会做动态内存规划！
typedef struct UserProducts{
    int userid;
    int productUponNum;
    int productCartNum;
    //已经被购买的商品数量
    int saleNum;
    //每个用户最多上架10个，使用嵌套结构体
    Product uponProduct[10];
    //购物车最多存储10个
    CartProduct cartProduct[10];
}UserProduct;

#endif


