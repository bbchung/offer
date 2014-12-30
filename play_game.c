#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int max3(int i1, int i2, int i3)
{
    int max = i1;
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


        int *A = malloc(N * sizeof(int)); // value
        int *PtoI = malloc(N * sizeof(int)); // point of current row to index
        int *StoN = malloc(N * sizeof(int)); // sum of index to N
        int *PtoN = malloc(N * sizeof(int)); // point of index to N;

        memset(A, 0, N * sizeof(int));
        memset(PtoN, 0, N * sizeof(int));
        memset(StoN, 0, N * sizeof(int));

        for (int j = 0; j < N; ++j)
        {
            scanf("%d", A + j);
        }

        for (int j = N-1; j >= 0; j--)
        {
            memset(PtoI, 0, N * sizeof(int));

            if (j == N-1)
            {
                StoN[j] = A[j];
            }
            else
            {
                StoN[j] = StoN[j+1] + A[j];
            }

            if (N-1-j<3)
            {
                for (int k=N-1;k>=j;--k)
                {
                    if (k == j+2)
                    {
                        PtoN[k] = A[k];
                    }
                    else
                    {
                        printf("PtoN[%d] = %d\n", k, PtoN[k-1] + A[k]);
                        PtoN[k] = PtoN[k+1] + A[k];
                    }
                }
            }
            else
            {
                for (int k=j;k<j+3;++k)
                {
                    if (k == j)
                    {
                        PtoI[k] = A[k];
                    }
                    else if (k-j < 3)
                    {
                        PtoI[k] = PtoI[k-1] + A[k];
                    }
                }

                int i1 = PtoI[j] + StoN[j+1] - PtoN[j+1];
                int i2 = PtoI[j+1] + StoN[j+2] - PtoN[j+2];
                int i3 = PtoI[j+2] + StoN[j+3] - PtoN[j+3];

                PtoN[j] = max3(i1, i2, i3);
            }
        }

        printf("%d\n", PtoN[0]);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
