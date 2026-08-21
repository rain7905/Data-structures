#include"heap.h"
void hpinit(hp* php)
{
	php->hpnode = NULL;
	php->size = php->capacity = 0;
}
void hpdestroy(hp* php)
{
	free(php->hpnode);
	php->hpnode = NULL;
	php->capacity = php->size = 0;
}
void swap(hpdata* a, hpdata* b)
{
	hpdata* tmp = a;
	*a = *b;
	*b = *tmp;
}
void adjustup(hpdata* hpnode,int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (hpnode[child] < hpnode[parent])
		{
			swap(&hpnode[child], &hpnode[parent]);
			child = parent;
			parent = (child - 1) / 2;

		}
		else
			break;
	}
}
void hppush(hp* php, hpdata x)
{
	int newcapacity = 0 ? 4 : php->capacity * 2;
	hpdata* tmp = (hpdata*)realloc(php->hpnode, sizeof(hpdata) * newcapacity);
	if (tmp == NULL)
	{
		perror("realloc fail");
		return;
	}
	php->capacity = newcapacity;
	php->hpnode[php->size] = x;
	php->size++;
	adjustup(php->hpnode, php->size - 1);
}
void adjustdown(hpdata*hpnode,int n,int parent)
{
	//假设左孩子更小
	int child = parent * 2 + 1;

	while (child<n)
	{
		if (child + 1 < n && hpnode[child] > hpnode[child + 1])
		{
			child++;
		}
		if (hpnode[parent] > hpnode[child])
		{
			swap(&hpnode[parent], &hpnode[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void hppop(hp* php)
{
	swap(&php->hpnode[0], &php->hpnode[php->size - 1]);
	php->size--;
	adjustdown(php->hpnode, php->size, 0);
}
hpdata hptop(hp* php)
{
	return php->hpnode[0];
}

bool hpempty(hp* php)
{
	return php->size == 0;
}
//降序，建小堆
void heapsort(int* a, int n)
{
	//建堆
	for (int i = 1; i < n; i++)
	{
		adjustup(a,i);
	}
	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		adjustdown(a, n, 0);
		end--;
	}
}