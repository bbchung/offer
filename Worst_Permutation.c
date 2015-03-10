#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);

    int A[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", A + i);

    int B[N];

    for (int i = 0; i < N; ++i)
        B[A[i] - 1] = i;

    int p1 = 0;
    int p2 = N - 1;

    while (K > 0 && p1 < N && p2 >= 0)
    {
        if (B[p2] == p1)
        {
            ++p1;
            --p2;
            continue;
        }

        int temp = A[p1];
        A[p1] = A[B[p2]];
        A[B[p2]] = temp;

        int i1 = A[p1] - 1;
        int i2 = A[B[p2]] - 1;

        temp = B[i1];
        B[i1] = B[i2];
        B[i2] = temp;


        --K;
        ++p1;
        --p2;
    }
    for (int i = 0; i < N; ++i)
    {
        printf("%d ", A[i]);
    }

    printf("\n");
}
