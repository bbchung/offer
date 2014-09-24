#include <stdio.h>

typedef struct _Node
{
    int value;
    struct _Node *left;
    struct _Node *right;
} Node;

bool IsBalanced(Node *root, int *height)
{
    if (root == NULL)
        return true;

    int leftHeight = 0;
    int rightHeight = 0;
    bool leftBalance = true;
    bool rightBalance = true;
    if (root->left != NULL)
        leftBalance = IsBalanced(root->left, &leftHeight);

    if (root->right)
        rightBalance = IsBalanced(root->right, &rightHeight);

    *height = (leftHeight >= rightHeight) ? leftHeight + 1 : rightHeight + 1;

    if (!leftBalance || !rightBalance)
        return false;

    int diff = leftHeight - rightHeight;

    if (-1 <= diff && diff <= 1)
        return true;

    return false;
}

int main()
{
    Node n1;
    n1.value = 1;
    n1.left = NULL;
    n1.right = NULL;

    Node n2;
    n2.value = 2;
    n2.left = NULL;
    n2.right = NULL;

    Node n3;
    n3.value = 3;
    n3.left = NULL;
    n3.right = NULL;

    Node n4;
    n4.value = 4;
    n4.left = NULL;
    n4.right = NULL;

    Node n5;
    n5.value = 5;
    n5.left = NULL;
    n5.right = NULL;

    Node n6;
    n6.value = 6;
    n6.left = NULL;
    n6.right = NULL;

    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;
    n2.right = &n5;

    n5.left = &n6;

    int height = 0;
    bool balance = IsBalanced(&n1, &height);

    printf("%d\n", balance);
}
