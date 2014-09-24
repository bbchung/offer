#include <stdio.h>

void NthThreeBits(int *pos1, int *pos2, int *pos3, unsigned int n)
{
    if (--n == 0)
        return;

    if (*pos2 - *pos1 > 1)
    {
        *pos1 = *pos1 + 1;
        NthThreeBits(pos1, pos2, pos3, n);
        return;
    }
    else
    {
        *pos1 = 0;
    }

    if (*pos3 - *pos2 > 1)
    {
        *pos2 = *pos2 + 1;
        NthThreeBits(pos1, pos2, pos3, n);
        return;
    }
    else
    {
        *pos2 = 1;
    }

    if (*pos3 < 7)
        *pos3 = *pos3 + 1;
    else
        return;

    NthThreeBits(pos1, pos2, pos3, n);
}

int main()
{
    int pos1 = 0;
    int pos2 = 1;
    int pos3 = 2;

    NthThreeBits(&pos1, &pos2, &pos3, 1000000);

    printf("%d %d %d\n", pos1, pos2, pos3);
}
