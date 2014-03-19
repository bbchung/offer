#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode
{
    int value;
    struct _TreeNode* left;
    struct _TreeNode* right;
} TreeNode;

typedef struct _ListNode
{
    int value;
    struct _ListNode* next;
} ListNode;

ListNode* CreateSimpleLinkList()
{
    ListNode *n1 = (ListNode*) malloc(sizeof(ListNode));
    ListNode *n2 = (ListNode*) malloc(sizeof(ListNode));
    ListNode *n3 = (ListNode*) malloc(sizeof(ListNode));
    ListNode *n4 = (ListNode*) malloc(sizeof(ListNode));
    ListNode *n5 = (ListNode*) malloc(sizeof(ListNode));

    n1->value = 1;
    n2->value = 2;
    n3->value = 3;
    n4->value = 4;
    n5->value = 5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;

    return n1;
}

void DeleteLinkList(ListNode* pHead)
{
    ListNode* curr = pHead;
    while (curr != NULL)
    {
        ListNode* next = curr->next;
        free(curr);
        curr = next;
    }
}

void DumpLinkList(ListNode* pHead)
{
    ListNode* curr = pHead;
    while (curr != NULL)
    {
        printf("%d ", curr->value);
        curr = curr->next;
    }

    printf("\n");
}

#endif
