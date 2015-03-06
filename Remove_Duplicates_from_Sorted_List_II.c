#include <stdio.h>
#include <stdlib.h>

typedef struct __Node
{
    int v;
    struct __Node *next;
} Node;

int main()
{
    int N;
    scanf("%d", &N);

    Node *dummy = malloc(sizeof(Node));
    dummy->next = NULL;

    Node *pre = NULL;

    for (int i = 0; i < N; ++i)
    {
        Node *n = malloc(sizeof(Node));
        n->next = NULL;
        scanf("%d", &n->v);

        if (dummy->next == NULL)
            dummy->next = n;

        if (pre != NULL)
            pre->next = n;

        pre = n;
    }

    Node *p = dummy;
    pre = NULL;
    Node *n = dummy->next;

    char dup = 0;
    while (n != NULL) 
    {
        if (pre != NULL)
        {
            if (n->v == pre->v)
            {
                dup = 1;
                free(pre);
                p->next = n;
            }
            else
            {
                if (dup)
                {
                    free(pre);
                    p->next = n;
                }
                else
                {
                    p = pre;
                }
                 
                dup = 0;
            }
        }

        pre = n;
        n = n->next;
    }

    if (dup)
        p->next = NULL;

    n = dummy->next;

    while (n != NULL)
    {
        printf("%d ", n->v);
        n = n->next;
    }

    printf("\n");
}
