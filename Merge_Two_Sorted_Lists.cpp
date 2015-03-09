#include <iostream>

using namespace std;

typedef struct __Node
{
    int value;
    struct __Node *next;
} Node;

Node *list_from_stdin(int len)
{
    Node *pre = NULL;
    Node *head = NULL;

    for (int i = 0; i < len; ++i)
    {
        Node *n = new Node();
        *n = {i+1, NULL};
        cin >> n->value;

        if (pre)
            pre->next = n;

        if (!head)
            head = n;

        pre = n;
    }

    return head;
}

void DumpList(Node *head)
{
    Node *p = head;

    while (p)
    {
        cout << p->value << " ";
        p = p->next;
    }

    cout << endl;
}

int main()
{
    int m, n;
    cin >> m;
    cin >> n;

    Node *head1 = list_from_stdin(m);
    Node *head2 = list_from_stdin(n);

    Node *p1 = head1;
    Node *p2 = head2;

    Node *head = NULL;
    Node *pre = NULL;

    while (p1 || p2)
    {
        Node *next = NULL;

        if (p1 && p2)
        {
            if (p1->value >= p2->value)
            {
                next = p2;
                p2 = p2->next;
            }
            else
            {
                next = p1;
                p1 = p1->next;
            }
        }
        else if (p1)
        {
            next = p1;
            p1 = p1->next;
        }
        else if (p2)
        {
            next = p2;
            p2 = p2->next;
        }

        if (pre)
            pre->next = next;

        pre = next;

        if (!head)
            head = next;
    }

    DumpList(head);
}
