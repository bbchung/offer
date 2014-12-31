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
        unsigned long long int N;
        scanf("%llu", &N);

        unsigned long long int f0 = 1;
        unsigned long long int f1 = 1;

        if (N == 0 || N == 1)
        {
            printf("IsFibo\n");
            continue;
        }

        while (1)
        {
            unsigned long long int tmp = f1;
            f1 = f0 + f1;
            f0 = tmp;

            if (N == f1)
            {
                printf("IsFibo\n");
                break;
            }
            else if (N < f1)
            {
                printf("IsNotFibo\n");
                break;
            }
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
