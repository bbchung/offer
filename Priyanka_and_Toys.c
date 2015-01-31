#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}


int main()
{
    int N;
    scanf("%d", &N);

    int W[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", W + i);

    qsort(W, N, sizeof(int), compare);

    int c = W[0];
    int ans = 1;
    for (int i = 0; i < N; ++i)
    {
        if (W[i] > c + 4)
        {
            ans++;
            c = W[i];
        }
    }

    printf("%d\n", ans);
}
