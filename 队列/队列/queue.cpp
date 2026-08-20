#include"queue.h"
void queueinit(queue* x)
{
	assert(x);
	x->ptail = x->phead = NULL;
	x->size = 0;
}
void queuepush(queue* x, qddata y)
{
	assert(x);
	qd* newnode = (qd*)malloc(sizeof(qd));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = y;
	newnode->next = NULL;
	if (x->phead == NULL)
	{
		x->phead = x->ptail = newnode;
	}
	else
	{
		x->ptail->next = newnode;
		x->ptail = newnode;
	}
	x->size++;
}
void queuepop(queue* x)
{
	assert(x);
	assert(x->phead);
	qd* pcr = x->phead->next;
	if (x->ptail == x->phead)
	{
		free(x->phead);
		x->phead = x->ptail = NULL;
	}
	else
	{
		free(x->phead);
		x->phead = pcr;
	}
	x->size--;
}
int queuesize(queue* x)
{
	assert(x);
	return x->size;
}
void queuedestroy(queue* x)
{
	assert(x);
	qd* pcr = x->phead;
	while (pcr)
	{
		qd* next = pcr->next;
		free(pcr);
		pcr = next;
	}
	x->ptail = x->phead = NULL;
	x->size = 0;
}