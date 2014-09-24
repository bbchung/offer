#include <stdio.h>

int FindMaxPos(int *pData, int len, int begin, int end, int number)
{
    if (begin < 0 || end >= len || begin > len)
        return -1;

    if (begin == end)
    {
        if (number == pData[begin])
            return begin;
        else
            return -1;
    }

    int max = -1;
    int center = (begin + end) / 2;

    if (pData[center] <= number)
    {
        if (pData[center] == number)
            max = center;

        int temp = FindMaxPos(pData, len, center + 1, end, number);

        if (temp != -1)
            max = temp;
    }
    else
    {
        int temp = FindMaxPos(pData, len, begin, center - 1, number);

        if (temp != -1)
            max = temp;
    }

    return max;
}

int FindMinPos(int *pData, int len, int begin, int end, int number)
{
    if (begin < 0 || end >= len || begin > end)
        return -1;

    if (begin == end)
    {
        if (number == pData[begin])
            return begin;
        else
            return -1;
    }

    int min = -1;
    int center = (begin + end) / 2;

    if (pData[center] >= number)
    {
        if (pData[center] == number)
            min = center;

        int temp = FindMinPos(pData, len, begin, center - 1, number);

        if (temp != -1)
            min = temp;
    }
    else
    {
        int temp = FindMinPos(pData, len, center + 1, end, number);

        if (temp != -1)
            min = temp;
    }

    return min;
}

int CountNumberK(int *pData, int len, int number)
{
    int min = FindMinPos(pData, len, 0, len - 1, number);
    int max = FindMaxPos(pData, len, 0, len - 1, number);

    if (min == -1 || max == -1)
        return 0;

    return max - min + 1;
}

int main()
{
    int data[] = { 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 4, 5, 6 };

    int count = CountNumberK(data, 13, 9);
    //    int min = FindMinPos(data, 13, 0, 12, 1);
    //    int max = FindMaxPos(data, 13, 0, 12, 1);

    printf("%d\n", count);
}
