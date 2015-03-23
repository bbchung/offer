#include <stdio.h>

int main()
{
    int N, K, Q;
    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%d", &Q);

    int A[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", A + i);

    int offset = -K;

    while (offset < 0)
        offset += N;

    for (int i = 0; i < Q; ++i)
    {
        int idx;
        scanf("%d", &idx);

        idx += offset;
        idx %= N;

        printf("%d\n", A[idx]);
    }
}
