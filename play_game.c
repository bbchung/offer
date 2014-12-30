#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


unsigned long long int max3(unsigned long long int i1, unsigned long long int i2, unsigned long long int i3)
{
    unsigned long long int max = i1;
    if (i2 > max)
        max = i2;

    if (i3 > max)
        max = i3;

    return max;
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        int N;
        scanf("%d", &N);

        unsigned long long int *A = malloc(N * sizeof(unsigned long long int)); // value
        unsigned long long int *StoN = malloc(N * sizeof(unsigned long long int)); // sum of index to N
        unsigned long long int *PtoN = malloc(N * sizeof(unsigned long long int)); // point of index to N;

        memset(A, 0, N * sizeof(unsigned long long int));
        memset(PtoN, 0, N * sizeof(unsigned long long int));
        memset(StoN, 0, N * sizeof(unsigned long long int));

        for (int j = 0; j < N; ++j)
        {
            scanf("%llu", A + j);
        }

        for (int j = N-1; j >= 0; j--)
        {
            if (j == N-1)
            {
                StoN[j] = A[j];
            }
            else
            {
                StoN[j] = StoN[j+1] + A[j];
            }

            if (j == N-1)
            {
                PtoN[j] = A[j];
            }
            else if (j == N-2 || j == N-3)
            {
                PtoN[j] = PtoN[j+1] + A[j];
            }
            else
            {

                unsigned long long int p0 = A[j];
                unsigned long long int p1 = p0 + A[j+1];
                unsigned long long int p2 = p1 + A[j+2];

                unsigned long long int i1 = p0 + StoN[j+1] - PtoN[j+1];
                unsigned long long int i2 = p1 + StoN[j+2] - PtoN[j+2];
                unsigned long long int i3 = p2 + StoN[j+3] - PtoN[j+3];

                PtoN[j] = max3(i1, i2, i3);
            }
        }

        printf("%llu\n", PtoN[0]);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
