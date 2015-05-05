#include <stdio.h>
#include <stdlib.h>

int countPrimes(int n)
{
    int *primes = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n-1; ++i)
        primes[i] = 1;

    primes[0] = 0;

    int count = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (primes[i] == 1)
        {
            ++count;
            int p = i + 1;
            int next = p + p;

            while (next <= n-1)
            {
                primes[next - 1] = 0;
                next += p;
            }
        }
    }

    free(primes);

    return count;
}

int main()
{
    int ret = countPrimes(3);
    printf("%d\n", ret);
}
