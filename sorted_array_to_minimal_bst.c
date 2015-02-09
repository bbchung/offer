#include "node.h"

TreeNode *ToTree(int *pData, int begin, int end)
{
    if (pData == NULL || end < begin)
        return NULL;

    if (end - begin == 0)
    {
        TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
        node->value = *pData;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    else
    {
        TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
        int center = (end + begin) / 2;
        node->value = pData[center];
        node->left = ToTree(pData, begin, center - 1);
        node->right = ToTree(pData, center + 1, end);
        return node;
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    TreeNode *root = ToTree(arr, 0, 4);

    printf("%d\n", root->value);
    printf("%d\n", root->left->value);
    printf("%d\n", root->right->value);
    printf("%d\n", root->left->right->value);
    return 0;
}
