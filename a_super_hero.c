#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        int N, M;
        scanf("%d", &N);
        scanf("%d", &M);

        unsigned int P[N][M], B[N][M];

        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                scanf("%u", &P[j][k]);
            }
        }
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                scanf("%u", &B[j][k]);
            }
        }

        // Start here

        unsigned int S[2][1000] = {{0}};
        int SI;
        for (int j = 0; j < N; ++j)
        {
            SI = j % 2;
            int LSI = (j + 1) % 2;
            memset(S[SI], 0, 1000*sizeof(unsigned int));

            unsigned int r = UINT_MAX;
            for (int k = 0; k < M; ++k)
            {
                unsigned int s; // spend
                if (j == 0)
                {
                    s = P[j][k];
                }
                else
                {
                    s = UINT_MAX;
                    for (int l = 0; l < 1000; ++l)
                    {
                        if (S[LSI][l] == 0)
                            continue;

                        int need = P[j][k] - (l + 1);
                        if (need < 0)
                            need = 0;

                        unsigned c = S[LSI][l] + need;
                        if (c < s)
                            s = c;
                    }
                }

                if (s <= S[SI][B[j][k] - 1] || S[SI][B[j][k] - 1] == 0)
                    S[SI][B[j][k] - 1] = s;

                if (j == N - 1)
                {
                    if (s <= r)
                        r = s;
                }
            }

            if (j == N - 1)
                printf("%u\n", r);
        }
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
