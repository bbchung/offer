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

ListNode* CreateSimpleLinkList(int len)
{
    int i =0;
    ListNode* pHead = NULL;
    ListNode* pTail = NULL;
    for (; i<len;++i)
    {
        ListNode *n = (ListNode*) malloc(sizeof(ListNode));
        n->value = i+1;
        n->next = NULL;

        if (pHead == NULL)
            pHead = n;

        if (pTail != NULL)
            pTail->next = n;

        pTail = n;
    }

    return pHead;
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
