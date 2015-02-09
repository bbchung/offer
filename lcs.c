#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int A[n], B[m];

    for (int i = 0; i < n; ++i)
        scanf("%d", A + i);

    for (int i = 0; i < m; ++i)
        scanf("%d", B + i);

    int r[m + 1][n + 1][2];

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

    int i = m, j = n;

    int path[m + n];
    int count = 0;

    while (i >= 1 && j >= 1)
    {
        if (r[i][j][1] == 0)
        {
            --i;
        }
        else if (r[i][j][1] == 1)
        {
            path[count++] = A[j - 1];
            --i;
            --j;
        }
        else if (r[i][j][1] == 2)
        {
            --j;
        }
    }

    for (int i = 0; i < count; ++i)
    {
        printf("%d ", path[count - 1 - i]);
    }
    printf("\n");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
