#include <stdio.h>

int weight_recursive(int N, int *A, int *W, int head, int min)
{
    if (head >= N || head < 0)
        return 0;

    int next_head = -1;
    for (int i=head+1;i<N;++i)
    {
        if (A[i] > A[head])
        {
            next_head = i;
            break;
        }
    }

    int with_head = (A[head] > min) ? W[head] + weight_recursive(N, A, W, next_head, A[head]) : 0;
    int without_head = weight_recursive(N, A, W, head+1, min);

    if (with_head > without_head)
        return with_head;
    else
        return without_head;
}

int main()
{

    int T;
    scanf("%d", &T); 

    for (int i = 0; i < T; ++i)
    {
        int N;
        scanf("%d", &N); 

        int A[N];
        for (int j = 0; j < N; ++j)
            scanf("%d", A + j);

        int W[N];
        for (int j = 0; j < N; ++j)
            scanf("%d", W + j);

        int w = weight_recursive(N, A, W, 0, 0);

        printf("%d\n", w);
    }

}
