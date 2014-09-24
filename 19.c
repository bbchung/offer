#include <stdio.h>

#include "node.h"

void MirrorTree(TreeNode *pRoot)
{
    if (pRoot == NULL)
        return;

    TreeNode *temp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = temp;

    MirrorTree(pRoot->left);
    MirrorTree(pRoot->right);
}

int main()
{
}

