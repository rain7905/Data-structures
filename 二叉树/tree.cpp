#include"tree.h"

void prev(treenode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d", root->data);
	prev(root->left);
	prev(root->right);
}
void midprev(treenode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	prev(root->left);
	printf("%d", root->data);
	prev(root->right);
}
void backprev(treenode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	prev(root->left);
	prev(root->right);
	printf("%d", root->data);
}
int  treesize(treenode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return treesize(root->left) + treesize(root->right)+1;
}
//´íÎóÊ¾·¶
//int treesize1(treenode* root)
//{
//	static int size = 0;
//	if (root == NULL)
//	{
//		return 0;
//	}
//	size++;
//	treesize1(root->left);
//	treesize1(root->right);
//	return size;
//}
int leavetreesize(treenode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return leavetreesize(root->left) + leavetreesize(root->right);
}
int height(treenode* root)
{
	if (root == NULL)
		return 0;
	int left = height(root->left);
	int right = height(root->right);
	int a = left > right ? left : right;
	return a + 1;
}