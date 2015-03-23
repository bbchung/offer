// there is a bug at cornet case!!!!!!!

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
    int n;

    scanf("%d", &N);
    scanf("%d", &n);

    n = n % N;
    if (n == 0)
        n = N;

    Node *head = NULL;
    Node *pre = NULL;
    for (int i = 0; i < N; ++i)
    {
        Node *n = malloc(sizeof(Node));
        scanf("%d", &n->v);
        n->next = NULL;

        if (head == NULL)
            head = n;

        if (pre != NULL)
            pre->next = n;

        pre = n;
    }

    Node *p1 = head;
    Node *p2 = head;


    int c = 0;
    while (p1 != NULL)
    {
        c++;
        p1 = p1->next;

        if (c > n + 1)
            p2 = p2->next;
    }

    printf("p2=%d\n", p2->v);

    Node *tmp = p2->next;
    p2->next = p2->next->next;
    free(tmp);

    p1 = head;

    while (p1 != NULL)
    {
        printf("%d ", p1->v);
        p1 = p1->next;
    }

    printf("\n");
}
