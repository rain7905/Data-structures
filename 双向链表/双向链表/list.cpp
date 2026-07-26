#include "list.h"

list* buyspace(ltdatatype x)
{
    list* node = (list*)malloc(sizeof(list));

    if (node == NULL)
    {
        perror("malloc fail");
        exit(1);
    }

    node->data = x;
    node->next = node;
    node->prev = node;

    return node;
}

//初始化
void init(list** phead)
{
    *phead = buyspace(-1);
}

//打印
void print(list* phead)
{
    assert(phead);

    list* cur = phead->next;

    while (cur != phead)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    printf("\n");
}

//指定位置后插
void insertafter(list* pos, ltdatatype x)
{
    assert(pos);

    list* newnode = buyspace(x);

    newnode->next = pos->next;
    newnode->prev = pos;

    pos->next->prev = newnode;
    pos->next = newnode;
}

//指定位置前插
void insertbefore(list* pos, ltdatatype x)
{
    assert(pos);

    list* newnode = buyspace(x);

    newnode->prev = pos->prev;
    newnode->next = pos;

    pos->prev->next = newnode;
    pos->prev = newnode;
}

//尾插
void ltpushback(list* phead, ltdatatype x)
{
    assert(phead);

    insertbefore(phead, x);
}

//头插
void ltpushfront(list* phead, ltdatatype x)
{
    assert(phead);

    insertafter(phead, x);
}

//尾删
void popback(list* phead)
{
    assert(phead);

    // 空链表
    if (phead->next == phead)
        return;

    lterase(phead->prev);
}

//头删
void popfront(list* phead)
{
    assert(phead);

    // 空链表
    if (phead->next == phead)
        return;

    lterase(phead->next);
}

//查找
list* ltfind(list* phead, ltdatatype x)
{
    assert(phead);

    list* cur = phead->next;

    while (cur != phead)
    {
        if (cur->data == x)
            return cur;

        cur = cur->next;
    }

    return NULL;
}

//删除指定节点
void lterase(list* pos)
{
    assert(pos);

    // 防止删除哨兵节点
    if (pos->next == pos && pos->prev == pos)
        return;

    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;

    free(pos);
}

//销毁
void destroy(list* phead)
{
    assert(phead);

    list* cur = phead->next;

    while (cur != phead)
    {
        list* next = cur->next;

        free(cur);

        cur = next;
    }

    free(phead);
}