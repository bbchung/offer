#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    unsigned int A[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%u", A + i);
    }

    for (int i = 0; i < q; ++i)
    {
        int tp, l, r;
        scanf("%d", &tp);
        scanf("%d", &l);
        scanf("%d", &r);

        if (tp == 1)
        {
            for (int j = l - 1; j < r; j += 2)
            {
                int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
            }
        }
        else if (tp == 2)
        {
            unsigned long long int s = 0;
            for (int j = l - 1; j <= r - 1; ++j)
                s += A[j];

            printf("%llu\n", s);
        }
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
