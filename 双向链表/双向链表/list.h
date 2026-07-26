#pragma once
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ltdatatype;

typedef struct listnode
{
    ltdatatype data;
    struct listnode* next;
    struct listnode* prev;
}list;

//初始化
void init(list** phead);

//打印
void print(list* phead);

//尾插
void ltpushback(list* phead, ltdatatype x);

//头插
void ltpushfront(list* phead, ltdatatype x);

//尾删
void popback(list* phead);

//头删
void popfront(list* phead);

//查找
list* ltfind(list* phead, ltdatatype x);

//指定位置后插入
void insertafter(list* pos, ltdatatype x);

//指定位置前插入
void insertbefore(list* pos, ltdatatype x);

//删除指定节点
void lterase(list* pos);

//销毁
void destroy(list* phead);