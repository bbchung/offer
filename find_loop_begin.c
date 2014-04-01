#include "node.h"

ListNode* FindFirstCross(ListNode* pHead)
{
    if (pHead == NULL)
        return NULL;

    ListNode* p1 = pHead;
    ListNode* p2 = pHead;

    do
    {
        if (p1 == NULL || p2 == NULL)
            return NULL;

        p1 = p1->next;

        if (p2->next != NULL)
        {
            p2 = p2->next->next;
        }
        else
        {
            return NULL;
        }

    } while (p1 != p2);

    return p1;
}

ListNode* FindLoopBegin(ListNode* pHead)
{
    if (pHead == NULL)
        return NULL;

    ListNode* cross = FindFirstCross(pHead);

    if (cross == NULL)
        return NULL;

    ListNode* p1 = pHead;
    ListNode* p2 = cross;

    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}

int main()
{
    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
    n1->value = 1;

    ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
    n2->value = 2;

    ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
    n3->value = 3;

    ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
    n4->value = 4;

    ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
    n5->value = 5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n1;

    ListNode* begin = FindLoopBegin(n1);
    printf("%d\n", begin->value);
}
