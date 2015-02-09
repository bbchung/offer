#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int Count(unsigned long long int n, unsigned long long int *last)
{
    int c = 0;

    while (n != 0)
    {
        c++;
        n = n & (n - 1);

        if (n != 0)
            *last = n;
    }

    return c;
}


int main()
{

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        unsigned long long int N;
        scanf("%llu", &N);
        int count = 0;

        while (N != 1)
        {
            unsigned long long int last;

            if (Count(N, &last) == 1)
            {
                N = N >> 1;
            }
            else
            {
                N -= last;
            }


            count++;
        }

        if (count % 2 == 0)
            printf("Richard\n");
        else
            printf("Louise\n");
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
