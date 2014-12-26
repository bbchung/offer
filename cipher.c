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

    char C[N + K];
    scanf("%s", C);

    char P[N + 1];
    memset(P, 0, N+1);

    P[0] = TOBYTE(C[0]);

    for (int i=1;i<N;++i)
    {
        P[i] = TOBYTE(C[i]) ^ TOBYTE(C[i-1]);

        if (i >= K)
            P[i] ^= P[i-K];
    }

    for (int i=0;i<N;++i)
        P[i] += '0';

    printf("%s\n", P);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
