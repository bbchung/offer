#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {


        unsigned long long int B, W;
        scanf("%llu", &B);
        scanf("%llu", &W);

        unsigned long long int X, Y, Z;
        scanf("%llu", &X);
        scanf("%llu", &Y);
        scanf("%llu", &Z);

        int x = MIN(X, Y + Z);
        int y = MIN(Y, X + Z);


        printf("%llu\n", B * x + W * y);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
