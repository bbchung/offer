#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int lcs(char *A, int n, char *B, int m)
{

    /*
     * W(m, n) = 
     * W(m, n-1) + W(m-1, n) + W(m-1, n-1)
     * + 2 *W(m-1, n-1) + 1, if A[m] == B[n]
     * 
     */
    /*
     * W(m, n) = 
     * 2 * W(m-1, n-1) + 1, if A[m] == B[n]
     * W(m, find(B, A[m])) + W(m, find(A, B[n])), if A[m] != B[n]
     *
     *
     */


    int r[m+1][n+1][2];

    int LI = 0; //last index
    for (int i = m-1; i >= 0; --i)
    {
        if (B[i] == A[n-1])
        {
            LI = i;
            break;
        }
    }

    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0 || j == 0)
            {
                r[i][j][0] = 0;
                r[i][j][1] = 1;
                continue;
            }

            if (A[j - 1] == B[i - 1])
            {
                r[i][j][0] = r[i - 1][j - 1][0] + 1;
                r[i][j][1] = 1;
            }
            else
            {
                int c1 = r[i][j - 1][0];
                int c2 = r[i - 1][j][0];
                if (c1 > c2)
                {
                    r[i][j][0] = c1;
                    r[i][j][1] = 2;
                }
                else
                {
                    r[i][j][0] = c2;
                    r[i][j][1] = 0;
                }
            }
        }
    }

    printf("lcs=%d\n", r[LI+1][n][0]);
    return r[LI+1][n][0];
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
        {
            C += lcs(S + j, j + 1, S + j + 1, len - j - 1);
        }

        printf("%d\n", C);
    }
}
