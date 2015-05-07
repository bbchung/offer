#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *p = head;

    struct ListNode *p1 = NULL;
    struct ListNode *p2 = NULL;

    struct ListNode *p3 = NULL;
    struct ListNode *p4 = NULL;

    while (p)
    {
        if (p->val < x)
        {
            if (p1 == NULL)
            {
                p1 = p;
                p2 = p;
            }
            else
            {
                p2->next = p;
                p2 = p;
            }
        }
        else
        {
            if (p3 == NULL)
            {
                p3 = p;
                p4 = p;
            }
            else
            {
                p4->next = p;
                p4 = p;
            }
        }

        p = p->next;
    }

    if (p2)
        p2->next = p3;
    
    if (p4)
        p4->next = NULL;

    return (p1) ? p1 : p3;
}

int main()
{
    struct ListNode n1;
    n1.val = 2;
    n1.next = NULL;

    struct ListNode n2;
    n2.val = 1;
    n2.next = NULL;

    /*struct ListNode n3;*/
    /*n3.val = 2;*/
    /*n3.next = NULL;*/

    /*struct ListNode n4;*/
    /*n4.val = 4;*/
    /*n4.next = NULL;*/

    /*struct ListNode n5;*/
    /*n5.val = 5;*/
    /*n5.next = NULL;*/

    n1.next = &n2;
//    n2.next = &n3;
    /*n3.next = &n4;*/
    /*n4.next = &n5;*/

    struct ListNode *head = partition(&n1, 2);

    while (head) 
    {
        printf("%d ", head->val);
        head = head->next;
    }
}
