#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

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

        unsigned long long int A1[N1], A2[N2];

        for (int j = 0; j < N1; ++j)
            scanf("%llu", A1 + j);

        for (int j = 0; j < N2; ++j)
            scanf("%llu", A2 + j);

        qsort(A1, N1, sizeof(unsigned long long int), compare);
        qsort(A2, N2, sizeof(unsigned long long int), compare);

        unsigned long long int S1[N1], S2[N2]; // sum1, sum2
        memset(S1, 0, N1 * sizeof(unsigned long long int));
        memset(S2, 0, N2 * sizeof(unsigned long long int));

        unsigned long long int S[2][N1 + N2 - 1]; // space
        int C[2] = {0};                           // count for space
        int SI;                                   // space index

        int lc; // last count
        for (int j = 0; j < N1 + N2 - 1; j++)
        {
            SI = j % 2;

            int m = j, n = 0;

            if (j == 0)
            {
                S1[j] = A1[j];
                S2[j] = A2[j];
            }
            else
            {
                if (j < N1)
                    S1[j] = S1[j - 1] + A1[j];

                if (j < N2)
                    S2[j] = S2[j - 1] + A2[j];
            }

            C[SI] = 0;


            while (m >= 0 && n < N2)
            {
                if (m < N1 && n >= 0)
                {
                    unsigned long long int choice1 = ((C[SI] >= C[(j + 1) % 2])) ? A1[m] + 2 * S2[n] : A1[m] + S[(j + 1) % 2][C[SI]] + S2[n];
                    unsigned long long int choice2 = (C[SI] == 0) ? A2[n] + 2 * S1[m] : A2[n] + S[(j + 1) % 2][C[SI] - 1] + S1[m];
                    S[SI][C[SI]] = MIN(choice1, choice2);
                    lc = C[SI];
                }

                C[SI]++;
                m--;
                n++;
            }
        }

        printf("%llu\n", S[SI][lc] % (1000000000 + 7));
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
