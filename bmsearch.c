#include <stdio.h>

int bmsearch(int *data, int start, int end, int value)
{
    int mid = (start + end) / 2;

    if (data[mid] == value)
    {
        return mid;
    }
    else if (data[mid] < value)
    {
        if (mid + 1 > end)
            return mid;

        return bmsearch(data, mid + 1, end, value);
    }
    else
    {
        if (mid - 1 < start)
            return mid-1;

        return bmsearch(data, start, mid - 1, value);
    }
}


int main()
{
    const char *str[2][3] = 
    {
        {"1", "2", "3"},
        {"1", "2", "3"},
    };
    int data[2] = {1, 2};

    int ret = bmsearch(data, 0, 1, 0);
    printf("%d\n", ret);
}
