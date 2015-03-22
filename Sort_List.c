#include <stdio.h>

typedef struct _Node
{
    int value;
    struct _Node *next;
} Node;

void dump(Node *head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}

Node *mid(Node *list)
{
    if (!list)
        return NULL;

    Node *p1 = list;
    Node *p2 = list;

    while (p1->next && p1->next->next)
    {
        p1 = p1->next->next;
        p2 = p2->next;
    }

    return p2;
}

Node *merge(Node *head1, Node *head2)
{
    if (!head1 && !head2)
        return NULL;

    if (head1 && (!head2 || head1->value <= head2->value))
    {
        Node *head = head1;
        head->next = merge(head1->next, head2);
        return head;
    }
    else
    {
        Node *head = head2;
        head->next = merge(head1, head2->next);
        return head;
    }
}

Node *sort(Node *list)
{
    if (!list)
        return NULL;

    if (!list->next)
        return list;

    Node *m = mid(list);

    Node *head1 = list;
    Node *head2 = m->next;

    m->next = NULL;

    return merge(sort(head1), sort(head2));
}

int main()
{
    Node n1 = {4, NULL};
    Node n2 = {3, NULL};
    Node n3 = {4, NULL};
    Node n4 = {1, NULL};
    Node n5 = {9, NULL};
    Node n6 = {8, NULL};

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    Node *head = sort(&n1);
    dump(head);
}
