#include <stdio.h>

int gt_count(int *A, int m, int *B, int n)
{
    int p2 = 0;

    int sum=0;
    for (int i = 0; i < m; ++i)
    {
        while (p2 < n)
        {
            if (A[i] <= B[p2])
                break;

            p2++;
        }

        sum += p2;
    }

    return sum;
}

int main()
{
    int A[] = {1,3,5,7,9};
    int B[] = {2,3,4,7,8};

    printf("%d\n", gt_count(A, 5, B, 5));
}
