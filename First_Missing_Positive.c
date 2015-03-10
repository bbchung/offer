#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", A+i);

    int p = 0;
    while (p < N)
    {
        if (A[p] != p+1 && A[p] - 1 < N && A[p] >= 1)
        {
            int temp = A[p];
            A[p] = A[temp-1];
            A[temp-1] = temp;
        }
        else
        {
            ++p;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        if (A[i] != i+1)
        {
            printf("%d\n", i+1);
            return 0;
        }
    }
}
