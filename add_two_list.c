#include "node.h"
#include <stdlib.h>
#include <stdbool.h>

ListNode* DoAddTwoList(ListNode* pHead1, ListNode* pHead2, bool carry)
{
    if (pHead1 == NULL && pHead2 == NULL && !carry)
        return NULL;

    ListNode* curr = (ListNode*)malloc(sizeof(ListNode));
    curr->next = NULL;
    curr->value = 0;

    ListNode* next1 = NULL;
    ListNode* next2 = NULL;

    if (pHead1 != NULL)
    {
        curr->value += pHead1->value;
        next1 = pHead1->next;
    }

    if (pHead2 != NULL)
    {
        curr->value += pHead2->value;
        next2 = pHead2->next;
    }

    if (carry)
        curr->value += 1;

    bool nextCarry = (curr->value >= 10);
    curr->value %= 10;

    curr->next = DoAddTwoList(next1, next2, nextCarry);

    return curr;
}

ListNode* AddTwoList(ListNode* list1, ListNode* list2)
{
    ListNode* pList = DoAddTwoList(list1, list2, false);
    return pList;
}

int main()
{
    ListNode* n1 = (ListNode*)malloc(sizeof(ListNode));
    n1->value = 9;

    ListNode* n2 = (ListNode*)malloc(sizeof(ListNode));
    n2->value = 9;

    ListNode* n3 = (ListNode*)malloc(sizeof(ListNode));
    n3->value = 4;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    ListNode* n4 = (ListNode*)malloc(sizeof(ListNode));
    n4->value = 1;

    ListNode* n5 = (ListNode*)malloc(sizeof(ListNode));
    n5->value = 9;

    ListNode* n6 = (ListNode*)malloc(sizeof(ListNode));
    n6->value = 9;

    n4->next = NULL;
    n5->next = n6;
    n6->next = NULL;


    ListNode* added = AddTwoList(n1, n4);

    DumpLinkList(added);
}
