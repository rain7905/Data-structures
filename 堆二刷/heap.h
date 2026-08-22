#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int hpdata;
typedef struct heap
{
	hpdata* hpnode;
	int size;
	int space;
}hp;
void heapinit(hp* a);
void heapdestroy(hp* a);
void heappush(hp* a, hpdata data);
void heappop(hp* a);