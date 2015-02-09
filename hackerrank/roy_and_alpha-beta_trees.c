#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct _Liking
{
    int permulate;
    int liking;
} Liking;

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}


Liking count_liking(int *A, int root, int left, int left_size, int right, int right_size, int level, int alpha, int beta);

Liking count_sum_liking(int *A, int offset, int num, int level, int alpha, int beta)
{
    Liking liking_sum = {0, 0};

    if (num == 0)
    {
        liking_sum.permulate = 1;
        liking_sum.liking = 0;
    }
    else if (num == 1)
    {
        liking_sum.permulate = 1;
        liking_sum.liking = A[offset] * ((level % 2 == 0) ? alpha : -beta);
    }
    else
    {
        for (int i = offset; i < offset + num; ++i)
        {
            Liking liking = count_liking(A, i, offset, i - offset, i + 1, num - (i + 1 - offset), level, alpha, beta);
            liking_sum.permulate += liking.permulate;
            liking_sum.liking += liking.liking;
        }
    }


    return liking_sum;
}

Liking count_liking(int *A, int root, int left, int left_size, int right, int right_size, int level, int alpha, int beta)
{
    Liking lliking = count_sum_liking(A, left, left_size, level + 1, alpha, beta);
    Liking rliking = count_sum_liking(A, right, right_size, level + 1, alpha, beta);

    Liking liking;
    liking.permulate = lliking.permulate * rliking.permulate;
    liking.liking = A[root] * liking.permulate * ((level % 2 == 0) ? alpha : -beta) + lliking.liking * rliking.permulate + rliking.liking * lliking.permulate;


    return liking;
}


int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        int N;
        scanf("%d", &N);

        int alpha, beta;

        scanf("%d", &alpha);
        scanf("%d", &beta);

        int A[N];

        qsort(A, N, sizeof(int), compare);

        for (int j = 0; j < N; ++j)
            scanf("%d", A + j);

        Liking liking_sum = count_sum_liking(A, 0, N, 0, alpha, beta);
        printf("%d\n", liking_sum.liking);
    }


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
