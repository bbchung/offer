#include <stdio.h>

typedef struct _Node
{
    int value;
    struct _Node *left;
    struct _Node *right;
} Node;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int LengthOfBinayrTree(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(LengthOfBinayrTree(root->left), LengthOfBinayrTree(root->right));
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

    int height = LengthOfBinayrTree(&n1);

    printf("%d\n", height);
}
