#include <stdio.h>

int rangeBitwiseAnd(int m, int n)
{
    if (m == n)
        return m;

    int x = m ^ n;

    int tmp;

    while ((tmp = (x & (x - 1))) != 0)
        x = tmp;

    x <<= 1;
    x -= 1;
    x = ~x;

    return x & m;
}

int main()
{
    printf("%d\n", rangeBitwiseAnd(5, 7));
}
