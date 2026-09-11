#include"tree.h"
treenode* buyspace(treedata x)
{
	treenode* newnode = (treenode*)malloc(sizeof(treenode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return 0;
	}
	newnode->data = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}
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
		printf("N");
		return;
	}
	midprev(root->left);
	printf("%d", root->data);
	midprev(root->right);
}
void backprev(treenode* root)
{
	if (root == NULL)
	{
		printf("N");
		return;
	}
	backprev(root->left);
	backprev(root->right);
	printf("%d", root->data);
}
int treesize(treenode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return treesize(root->left) + treesize(root->right) + 1;
}
int leave_treesize(treenode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == root->right && root->left == NULL)
	{
		return 1;
	}
	return leave_treesize(root->left) + leave_treesize(root->right);
}
int height(treenode* root)
{
	if (root == NULL)
		return 0;
	int left = height(root->left) + 1;
	int right = height(root->right) + 1;
	if (left > right)
	{
		return left ;
	}
	else
		return right;
}
int findsolo(treenode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right != NULL)
	{
		return findsolo(root->left) + findsolo(root->right) + 1;
	}
	if (root->left != NULL && root->right == NULL)
	{
		return findsolo(root->left) + findsolo(root->right) + 1;
	}
	return findsolo(root->left) + findsolo(root->right)+1;
}