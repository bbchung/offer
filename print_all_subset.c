#include <stdio.h>

void print_all_subset(int *A, int len, int *B, int len2, int index, int *c)
{
    if (index >= len)
    {
        for (int i = 0; i < len2; ++i)
        {
            printf("%d ", B[i]);
        }
        printf("\n");
        (*c)++;

        return;
    }
    print_all_subset(A, len, B, len2, index + 1, c);

    B[len2] = A[index];
    print_all_subset(A, len, B, len2 + 1, index + 1, c);
}


int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    int B[7] = {0};

    int c = 0;
    print_all_subset(A, 7, B, 0, 0, &c);

    printf("%d\n", c);
}
