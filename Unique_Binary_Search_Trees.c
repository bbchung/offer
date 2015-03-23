#include <stdio.h>

typedef struct __TreeNode
{
    int value;
    struct __TreeNode *left;
    struct __TreeNode *right;
} TreeNode;

int count_unique_bst(int from, int to)
{
    if (from >= to)
        return 1;

    int sum = 0;
    for (int i = from; i <= to; ++i)
        sum += count_unique_bst(from, i - 1) * count_unique_bst(i + 1, to);

    return sum;
}

int main()
{
    int c = count_unique_bst(1, 3);

    printf("%d\n", c);

    return 0;
}
