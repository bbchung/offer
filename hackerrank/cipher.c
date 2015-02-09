#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define TOBYTE(X) (X == '1')

int main()
{

    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);

    char CT[N + K];
    scanf("%s", CT);

    char PT[N + 1];
    memset(PT, 0, N + 1);

    PT[0] = TOBYTE(CT[0]);

    for (int i = 1; i < N; ++i)
    {
        PT[i] = TOBYTE(CT[i]) ^ TOBYTE(CT[i - 1]);

        if (i >= K)
            PT[i] ^= PT[i - K];
    }

    for (int i = 0; i < N; ++i)
        PT[i] += '0';

    printf("%s\n", PT);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
