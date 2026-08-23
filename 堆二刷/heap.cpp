#include"heap.h"
void heapinit(hp* a)
{
	assert(a);
	a->hpnode = NULL;
	a->size = a->space = 0;
}
void heapdestroy(hp*a)
{
	assert(a);
	free(a->hpnode);
	a->hpnode = NULL;
	a->space = a->size = 0;
}
void swap(hpdata* a, hpdata* b)
{
	hpdata tmp = *a;
	*a = *b;
	*b = tmp;
}
void adjustup(hpdata* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void heappush(hp* a, hpdata data)
{
	assert(a);
	if (a->space == a->size) 
	{
		hpdata newspace = a->space == 0 ? 4 : a->space * 2;
		a->hpnode = (hpdata*)realloc(a->hpnode, newspace * sizeof(hpdata));
		if (a->hpnode == NULL)
		{
			perror("realloc fail");
			return;
		}
		a->space = newspace;
	}
	a->hpnode[a->size] = data;
	a->size++;
	adjustup(a->hpnode, a->size - 1);
}
void adjustdown(hpdata* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child<size)
	{
		if (child+1<size && a[child] > a[child+1])
		{
			child++;
		}
		if (a[parent] > a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void heappop(hp* a)
{
	assert(a);
	assert(a->size > 0);
	swap(&a->hpnode[0], &a->hpnode[a->size - 1]);
	a->size--;
	adjustdown(a->hpnode, a->size, 0);
}
void heapsort(hpdata* a, int size)
{
	assert(a);
	for (int i = (size-2)/2; i>=0 ; i--)
	{
		adjustdown(a, size,i);
	}
	int end = size - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		adjustdown(a, end , 0);
		end--;
	}
}