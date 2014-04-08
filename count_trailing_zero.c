#include <stdio.h>


int compute_traling_zeros_of_factorial(int n)
{
    return n/5;
}

unsigned long long int test()
{
    unsigned int i;
    unsigned long long int f=1;
    for(i=1;i<=15;++i)
        f *= i;

    return f;
}

int main()
{
    printf("%llu\n", test());
}

