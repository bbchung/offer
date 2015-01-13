#include <stdio.h>

void part(int n, int max, int *path, int len)
{
    if (n < 0)
    {
        return;
    }
    else if (n == 0)
    {
        for (int i = 0; i < len; ++i)
        {
            printf("%d ", path[i]);
        }

        if (len > 0)
            printf("\n");
    }
    else
    {
        for (int i = max; i >= 1; --i)
        {
            path[len] = i;
            part(n-i, i, path, len+1);
        }
    }
}


int main()
{
    int N;
    scanf("%d", &N);

    int path[N];

    part(N, N, path, 0);
}
