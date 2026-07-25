#include "list.h"

// 申请新节点
sltnode* buyspace(sltdatatype x)
{
	sltnode* newnode = (sltnode*)malloc(sizeof(sltnode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

// 初始化哨兵位头节点
sltnode* sltinit()
{
	sltnode* phead = buyspace(-1); // 传入哑值即可，不存储有效数据
	return phead;
}

// 打印链表（跳过哨兵位）
void sltprint(sltnode* phead)
{
	assert(phead);
	sltnode* pcur = phead->next; // 从第一个有效节点开始打印
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

// 尾插
void sltpushback(sltnode* phead, sltdatatype x)
{
	assert(phead);
	sltnode* newnode = buyspace(x);
	sltnode* pcr = phead;
	// 找到当前链表的最后一个节点
	while (pcr->next)
	{
		pcr = pcr->next;
	}
	pcr->next = newnode;
}

// 头插（插入到哨兵位之后，成为第一个有效节点）
void sltpushfront(sltnode* phead, sltdatatype x)
{
	assert(phead);
	sltnode* newnode = buyspace(x);
	newnode->next = phead->next;
	phead->next = newnode;
}

// 尾删
void sltpopback(sltnode* phead)
{
	assert(phead && phead->next); // 确保链表有有效节点可删
	sltnode* pcr = phead;
	while (pcr->next->next)
	{
		pcr = pcr->next;
	}
	free(pcr->next);
	pcr->next = NULL;
}

// 头删
void sltpopfront(sltnode* phead)
{
	assert(phead && phead->next);
	sltnode* del = phead->next;
	phead->next = del->next;
	free(del);
}

// 查找
sltnode* slfind(sltnode* phead, sltdatatype x)
{
	assert(phead);
	sltnode* pcr = phead->next; // 从第一个有效节点开始找
	while (pcr)
	{
		if (pcr->data == x)
		{
			return pcr;
		}
		pcr = pcr->next;
	}
	return NULL;
}

// 指定位置 pos 前插入
void sltinsert(sltnode* phead, sltnode* pos, sltdatatype x)
{
	assert(phead && pos);
	sltnode* pcr = phead;
	while (pcr->next != pos)
	{
		pcr = pcr->next;
		assert(pcr); // 防呆：确保 pos 在链表中
	}
	sltnode* newnode = buyspace(x);
	newnode->next = pos;
	pcr->next = newnode;
}

// 指定位置 pos 后插入
void sltinsertafter(sltnode* pos, sltdatatype x)
{
	assert(pos);
	sltnode* newnode = buyspace(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 删除指定位置 pos 的节点
void slterase(sltnode* phead, sltnode* pos)
{
	assert(phead && pos && pos != phead); // 不能把哨兵位删了
	sltnode* pcr = phead;
	while (pcr->next != pos)
	{
		pcr = pcr->next;
		assert(pcr);
	}
	pcr->next = pos->next;
	free(pos);
}

// 删除 pos 之后的节点
void slteraseafter(sltnode* pos)
{
	assert(pos && pos->next);
	sltnode* del = pos->next;
	pos->next = del->next;
	free(del);
}

// 销毁链表（释放所有节点并清空头指针）
void sltdestory(sltnode** pphead)
{
	assert(pphead && *pphead);
	sltnode* pcr = *pphead;
	while (pcr)
	{
		sltnode* next = pcr->next;
		free(pcr);
		pcr = next;
	}
	*pphead = NULL;
}