#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int stdatatype;

typedef struct stack
{
    stdatatype* a;
    int top;
    int capacity;
} st;

// 初始化与销毁
void stinit(st* pst);
void stdestroy(st* pst); // 修正拼写：stdestory -> stdestroy

// 入栈与出栈
void stpush(st* pst, stdatatype x);
void stpop(st* pst);

// 查询操作
stdatatype sttop(st* pst);
bool stempty(st* pst);
int stsize(st* pst);

// 打印栈（调试用）
void stprint(st* pst);