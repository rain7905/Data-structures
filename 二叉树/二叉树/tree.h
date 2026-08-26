#pragma once
#include<stdio.h>
#include<stdlib.h>
static int size = 0;
typedef int treedata;

typedef struct treenode
{
	struct treenode* left;
	struct treenode* right;
	treedata data;
}tn;
int  treesize(treenode* root);
int  leavetreesize(treenode* root);
int height(treenode* root);
void prev(treenode* root);
void midprev(treenode* root);
void backprev(treenode* root);