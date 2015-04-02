#include <stdio.h>

double my_pow(int x, int n)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return x;


    if (n < 0)
    {
        n = -n;
        int half = my_pow(x, n/2);
        return 1.0/(half * half * my_pow(x, n%2));
    }
    else
    {
        int half = my_pow(x, n/2);
        return half * half * my_pow(x, n%2);
    }
}

int main()
{
    int X, N;

    scanf("%d", &X);
    scanf("%d", &N);

    printf("%f\n", my_pow(X, N));
    
}
