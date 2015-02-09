#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long int lpow(int i, int n)
{
    unsigned long long int b = 1;
    for (int j = 0; j < n; ++j)
    {
        b *= i;
    }

    return b;
}

int main()
{
    int N;
    scanf("%d", &N);

    unsigned long long int max = pow(10, N) - 1;
    unsigned long long int min = pow(10, N - 1);

    unsigned long long int max_root = floor(pow(max, 1.0 / N));
    unsigned long long int min_root = ceil(pow(min, 1.0 / N));

    for (unsigned long long int i = min_root; i <= max_root; ++i)
    {
        printf("%llu\n", lpow(i, N));
    }


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
