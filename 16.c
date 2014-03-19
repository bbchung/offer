#include "node.h"

ListNode* ReverseLinkList(ListNode* pHead)
{
    ListNode* curr = pHead;
    ListNode* prev = NULL;

    while (curr != NULL)
    {
        pHead = curr;
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return pHead;
}

int main()
{
    ListNode* pHead = CreateSimpleLinkList();
    pHead = ReverseLinkList(pHead);
    DumpLinkList(pHead);
    DeleteLinkList(pHead);
}
