#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


#define TOBYTE(X) X == '1'

int main()
{

    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);

    char buf[N + K];
    scanf("%s", buf);


    char bit[N + K];
    memset(bit, 0, N + K);

    for (int i = K - 1; i < N + K - 1; ++i)
    {
        for (int j = i - (K - 1); j < i; ++j)
            bit[i] ^= bit[j];

        bit[i] ^= TOBYTE(buf[i - (K - 1)]);
    }

    for (int i = K - 1; i < N + K - 1; ++i)
        bit[i] += '0';

    printf("%s\n", bit + K - 1);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
