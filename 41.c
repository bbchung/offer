#include <stdio.h>

bool FindPairWithSum(int *pData, int len, int number)
{
    if (pData == NULL || len <= 0)
        return false;

    int *pBegin = pData;
    int *pEnd = pData + len - 1;

    while (pBegin != pEnd)
    {
        if (*pBegin + *pEnd < number)
        {
            pBegin++;
        }
        else if (*pBegin + *pEnd > number)
        {
            pEnd--;
        }
        else
        {
            printf("%d %d\n", *pBegin, *pEnd);
            return true;
        }
    }

    return false;
}

int main()
{
    int data[] = { 1, 2, 4, 7, 11, 15 };

    FindPairWithSum(data, 6, 15);
}
