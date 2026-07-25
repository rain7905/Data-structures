#pragma once
#pragma once
#ifndef __SLIST_H__
#define __SLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int sltdatatype;

typedef struct sltnode
{
	sltdatatype data;
	struct sltnode* next;
} sltnode;

// 1. 初始化哨兵位头节点
sltnode* sltinit();

// 2. 打印链表
void sltprint(sltnode* phead);

// 3. 申请新节点
sltnode* buyspace(sltdatatype x);

// 4. 尾插/头插（由于哨兵位固定，传一级指针即可）
void sltpushback(sltnode* phead, sltdatatype x);
void sltpushfront(sltnode* phead, sltdatatype x);

// 5. 尾删/头删
void sltpopback(sltnode* phead);
void sltpopfront(sltnode* phead);

// 6. 查找
sltnode* slfind(sltnode* phead, sltdatatype x);

// 7. 任意位置插入/删除
void sltinsert(sltnode* phead, sltnode* pos, sltdatatype x);
void sltinsertafter(sltnode* pos, sltdatatype x);
void slterase(sltnode* phead, sltnode* pos);
void slteraseafter(sltnode* pos);

// 8. 销毁链表（需要释放包含哨兵位在内的所有节点）
void sltdestory(sltnode** pphead);

#endif // __SLIST_H__