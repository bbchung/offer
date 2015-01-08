#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int CSC(char *A, char *B, int m, int n);
int CSCE(char *A, char *B, int m, int n)
{
    int c = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (B[i] == A[m])
            c += CSC(A, B, m - 1, i - 1) + 1;
    }

    return c;
}

int CSC(char *A, char *B, int m, int n)
{
    if (m < 0 || n < 0)
        return 0;

    if (m == 0)
    {
        int c = 0;
        for (int i = 0; i <= n; ++i)
        {
            if (B[i] == A[0])
                c++;
        }

        return c;
    }

    if (n == 0)
    {
        int c = 0;
        for (int i = 0; i <= m; ++i)
        {
            if (A[i] == B[0])
                c++;
        }

        return c;
    }

    int c = 0;

    c += CSCE(A, B, m, n - 1);
    c += CSCE(B, A, n, m - 1);
    c += CSC(A, B, m - 1, n - 1);

    if (A[m] == B[n])
        c += CSC(A, B, m - 1, n - 1) + 1;


    return c;
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        char S[201] = {0};

        scanf("%s", S);

        int C = 0;
        int len = strlen(S);
        for (int j = 0; j < len - 1; ++j)
            C += CSCE(S, S + j + 1, j, len - j - 2);

        printf("%d\n", C);
    }
}
