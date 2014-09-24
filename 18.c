#include <stdio.h>

#include "node.h"

bool HasSubTree(TreeNode *pRoot1, TreeNode *pRoot2)
{
    if (pRoot1 == NULL || pRoot2 == NULL)
        return false;

    if (pRoot1->value == pRoot2->value)
    {
        bool has = true;
        if (pRoot2->left != NULL)
            has &= HasSubTree(pRoot1->left, pRoot2->left);

        if (pRoot2->right != NULL)
            has &= HasSubTree(pRoot1->right, pRoot2->right);

        return has;
    }
    else
    {
        if (HasSubTree(pRoot1->left, pRoot2))
            return true;

        if (HasSubTree(pRoot1->right, pRoot2))
            return true;

        return false;
    }
}

int main()
{
    TreeNode n1;
    n1.value = 1;
    n1.left = NULL;
    n1.right = NULL;

    TreeNode n2;
    n2.value = 2;
    n2.left = NULL;
    n2.right = NULL;

    TreeNode n3;
    n3.value = 3;
    n3.left = NULL;
    n3.right = NULL;

    TreeNode n4;
    n4.value = 4;
    n4.left = NULL;
    n4.right = NULL;

    TreeNode n5;
    n5.value = 5;
    n5.left = NULL;
    n5.right = NULL;

    TreeNode n6;
    n6.value = 6;
    n6.left = NULL;
    n6.right = NULL;

    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;
    n2.right = &n5;

    n5.left = &n6;

    bool has = HasSubTree(&n2, &n3);

    printf("%d\n", has);
}
