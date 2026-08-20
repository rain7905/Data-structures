#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int qddata;
typedef struct queuenode
{
	struct queuenode*next;
	qddata data;
}qd;
typedef struct queue
{
	qd* phead;
	qd* ptail;
	int size;
}queue;
void queueinit(queue* x);
void queuepush(queue* x, qddata y);
void queuepop(queue* x);
int queuesize(queue* x);
void queuedestory(queue* x);
