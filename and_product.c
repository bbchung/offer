#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int get_left_most_0_to_1(unsigned int a, unsigned int b)
{
    int result = 0;
    for (int i = 1; i <= 32; ++i)
    {
        if ((a & 1) == 0 && (b & 1) == 1)
            result = i;

        a >>= 1;
        b >>= 1;
    }

    return result;
}


int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        unsigned int A, B;
        scanf("%u", &A);
        scanf("%u", &B);

        int e = get_left_most_0_to_1(A, B);
        if (e == 0)
            e = 1;
        unsigned int result = A & (~0 << (e - 1));

        printf("%d\n", result);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
