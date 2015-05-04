#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sum(struct TreeNode *root, int value)
{
    if (!root)
        return 0;

    int total = root->val + value * 10;
    if (!root->left && !root->right)
        return total;

    return sum(root->left, total) + sum(root->right, total);
}


int sumNumbers(struct TreeNode *root)
{
    return sum(root, 0);
}

int main()
{
}
