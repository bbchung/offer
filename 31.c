#include <stdio.h>

int FindGreatestSumofSubArray(int *pData, int count)
{
    if (pData == NULL || count == 0)
        return 0;

    int max = 0x80000000;

    int sum = 0;

    for (int i = 0; i < count; ++i)
    {
        if (sum < 0)
            sum = pData[i];
        else
            sum += pData[i];

        if (sum > max)
            max = sum;
    }

    return max;
}

int main()
{
    int data[] = { -1, -2 };

    int max = FindGreatestSumofSubArray(data, 2);
    printf("%d\n", max);
}
