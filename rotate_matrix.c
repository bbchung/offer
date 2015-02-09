#include <stdio.h>
#define NULL 0

void rotate_matrix(int *m, int N)
{
    printf("rotate\n");
    if (m == NULL || N <= 0)
        return;


    for (int i = 0; i < (N + 1) / 2; ++i)
    {
        for (int j = 0; j < N / 2; ++j)
        {
            int tmp = *(m + i * N + j);
            printf("rotate(%d, %d) %d\n", i, j, *(m + i * N + j));
            *(m + i * N + j) = *(m + j * N + N - 1 - i);
            *(m + j * N + N - 1 - i) = *(m + (N - 1 - i) * N + N - 1 - j);
            *(m + (N - 1 - i) * N + N - 1 - j) = *(m + (N - 1 - j) * N + i);
            *(m + (N - 1 - j) * N + i) = tmp;
        }
    }
}

void dump(int *m, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", *(m + i * N + j));
        }

        printf("\n");
    }
}

int main()
{
    int a[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    dump(a, 4);

    rotate_matrix(a, 4);
    dump(a, 4);
}
