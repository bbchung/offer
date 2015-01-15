#include <stdio.h>

int plateau(int *A, int n)
{
    int len = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((i - len) >= 0)
        {
            if (A[i] == A[i - len])
            {
                len++;
            }
        }
    }

    return len;
}

int main()
{
    int A[] = {1, 2, 2, 2, 3, 3, 3, 3};
}
