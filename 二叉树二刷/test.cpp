
#include "tree.h"

int main()
{

    treenode* n1 = buyspace(1);
    treenode* n2 = buyspace(2);
    treenode* n3 = buyspace(3);
    treenode* n4 = buyspace(4);
    treenode* n5 = buyspace(5);
    treenode* n6 = buyspace(6);

    n1->left = n2;
    n1->right = n3;

    n2->left = n4; 

    n3->left = n5;
    n3->right = n6;

    printf("前序遍历 (PreOrder):  ");
    prev(n1);
    printf("\n");

    printf("中序遍历 (InOrder):   ");
    midprev(n1);
    printf("\n");

    printf("后序遍历 (PostOrder): ");
    backprev(n1);
    printf("\n");

    printf("\n--- 树的相关属性测试 ---\n");
    printf("节点总数: %d (预期结果: 6)\n", treesize(n1));


    printf("叶子节点数: %d (预期结果: 3 [节点4, 5, 6])\n", leave_treesize(n1));

    printf("树的高度: %d (预期结果: 3)\n", height(n1));

    printf("单孩子节点数: %d\n", findsolo(n1));

    free(n4);
    free(n5);
    free(n6);
    free(n2);
    free(n3);
    free(n1);

    return 0;
}
