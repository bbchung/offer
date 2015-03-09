#include <stdio.h>
#include <stdlib.h>

typedef struct __Node
{
    int value;
    struct __Node *next;
    struct __Node *random;
} Node;

Node *Copy(Node *head)
{
    Node *p = head;
    Node *head2 = NULL;

    while (p != NULL)
    {
        Node *new = malloc(sizeof(Node));
        new->value = p->value;
        new->random = NULL;
        new->next = p->next;

        if (head2 == NULL)
            head2 = new;

        p->next = new;

        p = new->next;
    }

    p = head;

    while (p != NULL)
    {
        if (p->random != NULL)
            p->next->random = p->random->next;

        p = p->next->next;
    }

    p = head;

    while (p != NULL)
    {
        Node *tmp = p->next;

        if (tmp != NULL)
            p->next = tmp->next;

        p = tmp;
    }

    return head2;
}


int main()
{
    Node n1, n2, n3, n4;

    n1.value = 1;
    n1.next = &n2;
    n1.random = &n3;

    n2.value = 2;
    n2.next = &n3;
    n2.random = &n4;

    n3.value = 3;
    n3.next = &n4;
    n3.random = &n4;

    n4.value = 4;
    n4.next = NULL;
    n4.random = &n1;

    Node *copy = Copy(&n1);

    Node *p = copy;
    while (p != NULL)
    {
        printf("%d, %d\n", p->value, (p->random == NULL) ? 0 : p->random->value);
        p = p->next;
    }
}
