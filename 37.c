#include <stdio.h>

typedef struct _Node
{
    int value;
    struct _Node* next;
} Node;

Node* FindFirstCommonNode(Node* pHead1, Node* pHead2)
{
    if (pHead1 == NULL || pHead2 == NULL)
        return NULL;

    Node* curr1 = pHead1;
    Node* curr2 = pHead2;

    int len1 = 0;
    while (curr1 != NULL)
    {
        len1++;
        curr1 = curr1->next;
    }

    int len2 = 0;
    while (curr2 != NULL)
    {
        len2++;
        curr2 = curr2->next;
    }

    printf("%d %d\n", len1, len2);

    curr1 = pHead1;
    curr2 = pHead2;

    if (len1 > len2)
    {
        for (int i=0; i<len1-len2;++i)
        {
            curr1 = curr1->next;
        }
    }
    else if (len2 > len1)
    {
        for (int i=0; i<len2-len1;++i)
        {
            curr2 = curr2->next;
        }
    }

    while (curr1 != NULL)
    {
        if (curr1 == curr2)
            return curr1;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return NULL;
}

int main()
{
    Node n1;
    n1.value=1;
    n1.next = NULL;
    Node n2;
    n2.value=2;
    n2.next = NULL;
    Node n3;
    n3.value=3;
    n3.next = NULL;
    Node n4;
    n4.value=4;
    n4.next = NULL;
    Node n5;
    n5.value=5;
    n5.next = NULL;
    Node n6;
    n6.value=6;
    n6.next = NULL;

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n6;
    n4.next = &n3;

    Node* common = FindFirstCommonNode(&n1, &n4);
    if (common != NULL)
        printf("%d\n", common->value);
}
