#include <stdio.h>

int eq_count(int *A, int m, int *B, int n)
{
    int p1=0, p2=0;

    int count=0;
    while (p1 < m && p2 < n)
    {
        if (A[p1] == B[p2])
        {
            count++;
            p1++;
            p2++;
        }
        else if (A[p1] < B[p2])
        {
            p1++;
        }
        else
        {
            p2++;
        }
    }

    return count;
}

int main()
{
    int A[] = {1,3,4,7,9};
    int B[] = {3,5,7,8,10};

    printf("%d\n", eq_count(A, 5, B, 5));
}

