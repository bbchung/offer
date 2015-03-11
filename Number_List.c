#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T, N, K;

    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        scanf("%d", &N);
        scanf("%d", &K);

        int A[N];

        for (int i = 0; i < N; ++i)
            scanf("%d", A+i);

        int B[N];
        int pos = N;

        for (int i = N-1; i >= 0; --i)
        {
            if (A[i] > K)
                pos = i;

            B[i] = pos;
        }

        int sum = 0;
        for (int i = 0; i < N; ++i)
            sum += ((N-i) - (B[i]-i));

        printf("%d\n", sum);
    }
}
