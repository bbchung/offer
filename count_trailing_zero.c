#include <stdio.h>


int compute_traling_zeros_of_factorial(unsigned int n)
{
    int count = 0;
    int i;

    for (i=5; i<n; i*=5)
        count += n/i;

    return count;
}

int main()
{
    compute_traling_zeros_of_factorial(10);
}

