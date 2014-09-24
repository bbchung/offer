#include <stdio.h>

#include "node.h"

ListNode *FindKthFromTail(ListNode *pHead, int k)
{
    if (pHead == NULL)
        return NULL;

    ListNode *p1 = pHead;

    for (int i = 0; i < k - 1; ++i)
    {
        p1 = p1->next;
        if (p1 == NULL)
            return NULL;
    }

    ListNode *p2 = pHead;

    while (1)
    {
        if (p1->next == NULL)
            break;

        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

int main()
{
    ListNode n1;
    n1.value = 1;
    ListNode n2;
    n2.value = 2;
    ListNode n3;
    n3.value = 3;
    ListNode n4;
    n4.value = 4;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = NULL;

    ListNode *kth = FindKthFromTail(&n1, 8);

    printf("%d\n", kth->value);
}
