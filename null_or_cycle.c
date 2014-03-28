#include "node.h"
#include <stdbool.h>

bool NullOrCycle(ListNode* pHead)
{
    if (pHead == NULL)
        return false;

    ListNode* p1 = pHead;
    ListNode* p2 = pHead;

    while (p1 != NULL)
    {
        p1 = p1->next;

        p2 = p2->next;
        if (p2 == NULL)
            return false;
        p2 = p2->next;
        if (p2 == NULL)
            return false;

        if (p2 == p1)
            return true;
    }

    return false;
}

int main()
{
    ListNode* pHead = CreateCircleLinkList();
    ListNode* pHead2 = CreateSimpleLinkList(5);

    ListNode* pHead3 = (ListNode*)malloc(sizeof(ListNode)); 
    pHead3->next =NULL;
    bool b= NullOrCycle(pHead3);

    printf("%d\n", b);
}
