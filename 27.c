#include <stdio.h>
struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Interval
{
    struct Node *begin;
    struct Node *end;
};

struct Interval ToList(struct Node *root)
{
    struct Interval interval;

    if (root->left != NULL)
    {
        struct Interval itv = ToList(root->left);
        interval.begin = itv.begin;
        itv.end->right = root;
        root->left = itv.end;
    }
    else
        interval.begin = root;

    if (root->right != NULL)
    {
        struct Interval itv = ToList(root->right);
        interval.end = itv.end;
        root->right = itv.begin;
        itv.begin->left = root;
    }
    else
        interval.end = root;

    return interval;
}


struct Node *Convert(struct Node *root)
{
    if (root == NULL)
        return NULL;

    struct Interval interval = ToList(root);
    return interval.begin;
}

void Dump(struct Node *pHead)
{
    struct Node *curr = pHead;
    while (curr != NULL)
    {
        printf("%d ", curr->value);
        if (curr == curr->right)
            break;
        curr = curr->right;
    }

    printf("\n");
}

int main()
{
    struct Node left;
    left.value = 2;
    left.left = NULL;
    left.right = NULL;

    struct Node n1;
    n1.value = 6;
    n1.left = NULL;
    n1.right = NULL;

    struct Node n2;
    n2.value = 9;
    n2.left = NULL;
    n2.right = NULL;


    struct Node right;
    right.value = 8;
    right.left = NULL;
    right.right = &n2;

    struct Node root;
    root.value = 5;
    root.left = &left;
    root.right = &right;

    struct Node *pHead = Convert(&root);

    Dump(pHead);
}

