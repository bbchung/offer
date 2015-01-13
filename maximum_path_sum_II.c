#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {

        int N;
        scanf("%d", &N);
        int s[2][N];
        int max=0;

        for (int j = 0; j <= N; ++j)
        {
            int si = j % 2;
            int lsi= (j+1) % 2;
            for (int k = 0; k <= N; ++k)
            {
                if (j == 0 || k == 0 || k > j)
                {
                    s[si][k] = 0;
                    continue;
                }
                
                int V;
                scanf("%d", &V);

                s[si][k] = MAX(s[lsi][k-1], s[lsi][k]) + V;

                if (s[si][k] > max)
                    max = s[si][k];
            }
        }

        printf("%d\n", max);
    }
}
