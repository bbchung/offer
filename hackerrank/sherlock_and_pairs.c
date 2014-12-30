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
        int A[1000000] = {0};
        int N;
        scanf("%d", &N);

        for (int j = 0; j < N; j++)
        {
            int V;
            scanf("%d", &V);
            A[V - 1]++;
        }


        unsigned long long int count = 0;
        for (int j = 0; j < 1000000; ++j)
        {
            count += (unsigned long long int)A[j] * (unsigned long long int)(A[j] - 1);
            printf("%d x %d\n", A[j], (A[j] - 1));
        }

        printf("%llu\n", count);
    }


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
