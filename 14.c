#include <stdio.h>

void SwapOddBeforeEven(int *pData, int len)
{
    if (NULL == pData || len == 0)
        return;

    int *pBegin = pData;
    int *pEnd = pData + len - 1;

    while (1)
    {
        if (*pBegin % 2 == 1)
            pBegin++;

        if (*pEnd % 2 == 0)
            pEnd--;

        if (pBegin >= pEnd)
            break;

        if (*pBegin % 2 == 0 && *pEnd % 2 == 1)
        {
            *pBegin = *pBegin ^ *pEnd;
            *pEnd = *pBegin ^ *pEnd;
            *pBegin = *pBegin ^ *pEnd;
        }
    }
}

int main()
{
    int data[] = {1, 2, 4, 3, 5};

    SwapOddBeforeEven(data, 5);

    int i = 0;
    for (i; i < 5; i++) printf("%d, ", data[i]);

    printf("\n");
}
