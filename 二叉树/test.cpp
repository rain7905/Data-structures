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
int main()
{
	treenode* node1 = buyspace(1);
	treenode* node2 = buyspace(2);
	treenode* node3 = buyspace(3);
	treenode* node4 = buyspace(4);
	treenode* node5 = buyspace(5);
	treenode* node6 = buyspace(6);
	node1->left = node2;
	node2->left = node3;
	node1->right = node4;
	node4->left = node5;
	node4->right = node6;
	printf("%d", treesize(node1));

}