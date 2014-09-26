#include "node.h"
#include <string.h>
#include <stdio.h>

void print(int *history, int start, int end)
{
    for (int i = start; i <= end; ++i)
        printf("%d ", history[i]);

    printf("\n");
}

void find_sum(TreeNode *root, int sum, int *history, int level)
{
    if (root == NULL)
        return;

    int buf[level + 1];
    if (level > 0 && history != NULL)
        memcpy(buf, history, level * 4);

    buf[level] = root->value;

    int tmp = 0;
    for (int i = level; i >= 0; --i)
    {
        tmp += buf[i];
        if (tmp == sum)
            print(buf, i, level);
    }

    find_sum(root->left, sum, buf, level + 1);
    find_sum(root->right, sum, buf, level + 1);
}

int main()
{
    TreeNode *tree = CreateSimpleTree();
    find_sum(tree, 3, NULL, 0);
}

