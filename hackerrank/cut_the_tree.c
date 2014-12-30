#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct Node
{
    int value;

    int num_nb;
    int *nb;
    int size_nb;
};

int find_min(struct Node *nodes, int total, int *min, int root, int from)
{
    struct Node *node = nodes + root-1;

    int sum = node->value;

    for (int i=0;i<node->num_nb;++i)
    {
        if (node->nb[i] == from)
            continue;

        sum += find_min(nodes, total, min, node->nb[i], root);
    }

    int sub = abs(total - 2 * sum);
    if (sub < *min)
        *min = sub;

    return sum; 
}

int main()
{
    struct Node nodes[100000];

    int N=0;
    scanf("%d", &N);

    int total = 0;
    for (int i=0;i<N;++i)
    {
        int V;
        scanf("%d", &V);

        nodes[i].value = V;
        nodes[i].num_nb=0;
        nodes[i].nb = malloc(10*sizeof(int));
        nodes[i].size_nb = 10;
        
        total += V;
        
    }

    for (int i=0;i<N-1;++i)
    {
        int N1, N2;
        scanf("%d", &N1);
        scanf("%d", &N2);

        if (nodes[N1-1].num_nb >=  nodes[N1-1].size_nb)
        {
            void* tmp = nodes[N1-1].nb;
            nodes[N1-1].nb = malloc(nodes[N1-1].num_nb*2*sizeof(int));
            memcpy(nodes[N1-1].nb, tmp, nodes[N1-1].size_nb);
            nodes[N1-1].size_nb = nodes[N1-1].num_nb*2;
            free(tmp);
        }
        nodes[N1-1].nb[nodes[N1-1].num_nb++] = N2;

        if (nodes[N2-1].num_nb >=  nodes[N2-1].size_nb)
        {
            void* tmp = nodes[N2-1].nb;
            nodes[N2-1].nb = malloc(nodes[N2-1].num_nb*2*sizeof(int));
            memcpy(nodes[N2-1].nb, tmp, nodes[N2-1].size_nb);
            nodes[N2-1].size_nb = nodes[N2-1].num_nb*2;
            free(tmp);
        }

        nodes[N2-1].nb[nodes[N2-1].num_nb++] = N1;
    }

    int min = 1001 * 100000;

    int sum = find_min(nodes, total, &min, 1, 0);
    
    printf("%d\n", min);
}
