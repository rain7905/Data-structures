#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int hpdata;
typedef struct heap
{
	hpdata* hpnode;
	int capacity;
	int size;
}hp;
void hpinit(hp* php);
void hpdestroy(hp* php);
void hppush(hp* php, hpdata x);
void hppop(hp* php);
hpdata hptop(hp* php);
bool hpempty(hp* php);