#include <stdio.h>

typedef struct _Node
{
    int value;
    struct _Node* next;
} Node;

Node* MergeSortedList(Node* pHead1, Node* pHead2)
{
    if (pHead1 == NULL && pHead2 == NULL)
    {
        return NULL;
    }
    else if (pHead1 == NULL)
    {
        return pHead2;
    }
    else if (pHead2 == NULL)
    {
        return pHead1;
    }
    else
    {
        if (pHead1->value <= pHead2->value)
        {
            Node* next = MergeSortedList(pHead1->next, pHead2);
            pHead1->next = next;
            return pHead1;
        }
        else
        {
            Node* next = MergeSortedList(pHead1, pHead2->next);
            pHead2->next = next;
            return pHead2;
        }
    }
}

void Dump(Node* pHead)
{
    while (pHead != NULL)
    {
        printf("%d\n", pHead->value);
        pHead = pHead->next;
    }
}

int main()
{
    Node n1;
    n1.value = 1;
    Node n2;
    n2.value = 6;
    Node n3;
    n3.value = 7;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    Node n4;
    n4.value = 4;
    Node n5;
    n5.value = 8;

    n4.next = &n5;
    n5.next = NULL;

    Node* pHead = MergeSortedList(NULL, &n4);

    Dump(pHead);
}

