#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode
{
    int value;
    struct _TreeNode *left;
    struct _TreeNode *right;
} TreeNode;

typedef struct _ListNode
{
    int value;
    struct _ListNode *next;
} ListNode;

ListNode *CreateCircleLinkList()
{
    ListNode *n1 = (ListNode *)malloc(sizeof(ListNode));
    n1->value = 1;

    ListNode *n2 = (ListNode *)malloc(sizeof(ListNode));
    n2->value = 2;

    ListNode *n3 = (ListNode *)malloc(sizeof(ListNode));
    n3->value = 3;

    ListNode *n4 = (ListNode *)malloc(sizeof(ListNode));
    n4->value = 4;

    ListNode *n5 = (ListNode *)malloc(sizeof(ListNode));
    n5->value = 5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n2;

    return n1;
}

ListNode *CreateSimpleLinkList(int len)
{
    int i = 0;
    ListNode *pHead = NULL;
    ListNode *pTail = NULL;
    for (; i < len; ++i)
    {
        ListNode *n = (ListNode *)calloc(1, sizeof(ListNode));
        n->value = i + 1;
        n->next = NULL;

        if (pHead == NULL)
            pHead = n;

        if (pTail != NULL)
            pTail->next = n;

        pTail = n;
    }

    return pHead;
}

void DeleteLinkList(ListNode *pHead)
{
    ListNode *curr = pHead;
    while (curr != NULL)
    {
        ListNode *next = curr->next;
        free(curr);
        curr = next;
    }
}

void DumpLinkList(ListNode *pHead)
{
    ListNode *curr = pHead;
    while (curr != NULL)
    {
        printf("%d ", curr->value);
        curr = curr->next;
    }

    printf("\n");
}

TreeNode *CreateTree2()
{
    TreeNode *n1 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n1->value = 10;

    TreeNode *n2 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n2->value = 5;

    TreeNode *n3 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n3->value = 12;

    TreeNode *n4 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n4->value = 4;

    TreeNode *n5 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n5->value = 7;

    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n4->left = NULL;
    n4->right = NULL;

    n5->left = NULL;
    n5->right = NULL;

    return n1;
}

TreeNode *CreateSimpleTree()
{
    TreeNode *n1 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n1->value = 1;

    TreeNode *n2 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n2->value = 2;

    TreeNode *n3 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n3->value = 3;

    TreeNode *n4 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n4->value = 4;

    TreeNode *n5 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n5->value = 5;

    TreeNode *n6 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n6->value = 6;

    TreeNode *n7 = (TreeNode *)calloc(1, sizeof(TreeNode));
    n7->value = 7;

    n1->left = n2;
    //n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->left = n6;
    n3->right = n7;

    return n1;
}

void DeleteTree(TreeNode *pRoot)
{
    if (pRoot == NULL)
        return;

    if (pRoot->left != NULL)
        DeleteTree(pRoot->left);

    if (pRoot->right != NULL)
        DeleteTree(pRoot->right);

    free(pRoot);
}

#endif
