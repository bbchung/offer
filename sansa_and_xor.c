#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        int N;
        scanf("%d", &N);
        unsigned int V;

        unsigned int ret = 0;
        for (unsigned int j = 0; j < N; ++j)
        {
            scanf("%u", &V);
            unsigned long long int c = (j + 1) * (N - j);
            if (c % 2 == 1)
            {

                ret ^= V;
            }
        }

        printf("%d\n", ret);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
