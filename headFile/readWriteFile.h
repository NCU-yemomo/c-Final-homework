#include "type.h"
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <Windows.h>
#include<time.h>
//写入用户数据文件
void saveFileUserProduct(int userNum,UserProduct *userProduct){
    FILE *fp=fopen("./bin/userProduct.bin","wb");
    if (fp==NULL){
        perror("文件创建失败");
        return;
    }
    size_t n = fwrite(userProduct,sizeof(UserProduct),userNum,fp);
    if (n!=userNum){
        perror("文件写入失败");
        return;
    }
    fclose(fp);
}
//写入用户文件
void saveFileUser(int userNum,User *user){
    FILE *fp=fopen("./bin/user.bin","wb");
    if (fp==NULL){
        perror("文件创建失败");
        return ;
    }
    size_t n = fwrite(user,sizeof(User),userNum,fp);
    if (n!=userNum){
        perror("文件写入失败");
        return ;
    }
    fclose(fp);
}
void saveFileUserNum(int userNum){
    FILE *fp=fopen("./bin/userNum.bin","wb");
    if (fp==NULL){
        perror("文件创建失败");
        return ;
    }
    size_t n = fwrite(&userNum,sizeof(int),1,fp);
    if (n!=1){
        perror("文件写入失败");
        return ;
    }
    fclose(fp);
}
//读取用户文件
void readFileUserProduct(int userNum,UserProduct *userProduct){
    FILE *fp=fopen("./bin/userProduct.bin","rb");
    if (fp==NULL){
        perror("文件创建失败");
        return ;
    }
    size_t n = fread(userProduct,sizeof(UserProduct),userNum,fp);
    if (n!=userNum){
        perror("文件读取失败");
        return ;
    }
    fclose(fp);
}
//读取用户数据文件
void readFileUser(int userNum,User *user){
    FILE *fp=fopen("./bin/user.bin","rb");
    if (fp==NULL){
        perror("文件创建失败");
        return ;
    }
    size_t n = fread(user,sizeof(User),userNum,fp);
    if (n!=userNum){
        perror("文件读取失败");
        return ;
    }
    fclose(fp);
}
