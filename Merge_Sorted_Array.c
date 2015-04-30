#include <stdio.h>
void merge(int A[], int m, int B[], int n)
{
    int p = m + n - 1;

    int p1 = m - 1;
    int p2 = n - 1;

    while (p >= 0)
    {
        if ((p1 >= 0 && p2 < 0) || (p1 >= 0 && p2 >= 0 && A[p1] >= B[p2]))
        {
            A[p--] = A[p1--];
        }
        else if ((p2 >= 0 && p1 < 0) || (p1 >= 0 && p2 >= 0 && B[p2] >= A[p1]))
        {
            A[p--] = B[p2--];
        }
    }
}

int main()
{
    int A[10] = {1,3, 5};
    int B[3] = {2,4, 6};

    merge(A, 3, B, 3);

    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", A[i]);
        
    }
    printf("\n");
}
