#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", A + i);

    int p1 = 0;
    int p2 = N - 1;

    while (p1 < p2)
    {
        int mid = (p1 + p2) / 2;
        if (A[mid] == mid)
        {
            printf("%d\n", mid);
            return 0;
        }
        else if (A[mid] > mid)
        {
            p2 = mid - 1;
        }
        else
        {
            p1 = mid + 1;
        }
    }

    printf("no\n");
}
