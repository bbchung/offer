#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MIN(x, y) (x) < (y) ? (x) : (y)
#define MAX(x, y) (x) > (y) ? (x) : (y)

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        int N1, N2;
        scanf("%d", &N1);
        scanf("%d", &N2);
        --N1;
        --N2;

        int A1[N1], A2[N2];

        for (int j = 0; j < N1; ++j)
            scanf("%d", A1 + j);

        for (int j = 0; j < N2; ++j)
            scanf("%d", A2 + j);

        qsort(A1, N1, sizeof(int), compare);
        qsort(A2, N2, sizeof(int), compare);

        int S1[N1], S2[N2]; // sum1, sum2
        memset(S1, 0, N1);
        memset(S2, 0, N2);

        int S[2][MAX(N1, N2)]; // space
        int C[2]; // count for space

        for (int j=0;j<N1+N2-1;j++)
        {
            int SI = j%2; // space index


            int m = j, n = 0;

            if (j == 0)
            {
                S1[j] = A1[j];
                S2[j] = A2[j];
            }
            else
            {
                if (j < N1)
                    S1[j] = S1[j-1] + A1[j];

                if (j < N2)
                    S2[j] = S2[j-1] + A2[j];
            }

            C[SI] = 0;
            while (m >= 0)
            {
                if (m < N1)
                {
                    if (m == 0 || n == 0)
                    {
                        S[SI][C[SI]] = 2 * MIN(S1[m], S2[n]) + MAX(S1[m], S2[n]);
                    }
                    else
                    {
                        S[SI][C[SI]] = MIN(A1[m] + ((C[SI] >= C[(j+1)%2]) ? S[(j+1)%2][C[SI]]+S2[n] : 111111111), A2[n] + ((C[SI] > 0) ? S[(j+1)%2][C[SI]-1] : 1111111) + S1[m]);
                    }

                    C[SI]++;
                }

                m--;
                n++;
            }
        }

        printf("%d\n", S[(N1+N2-2)%2][C[(N1+N2-2)%2]] % (1000000000 + 7));


        /*W(m, n)
         * 2 * min(S1[m], S2[n]) + max(S1[m], S2[n]), if m == 0 or n == 0
         * or
         * min(A1[m] + W(m-1, n) + S2[n], A2[n] + W(m, n-1) + S1[m])
         */
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
