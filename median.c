#include <stdio.h>

void dump(int *data, int len)
{
    for (int i = 0; i < len; ++i)
        printf("%d ", data[i]);

    printf("\n");
}

int partition(int *data, int len)
{
    if (data == NULL || len <= 1)
        return -1;

    int pivot = data[0];

    int i = 1, j = len - 1;

    char fi = 0, fj = 0;
    while (i <= j)
    {
        if (data[i] <= pivot)
            i++;
        else
            fi = 1;

        if (data[j] >= pivot)
            j--;
        else
            fj = 1;

        if (fi & fj)
        {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;

            fi = 0;
            fj = 0;
        }
    }

    int temp = data[0];
    data[0] = data[i - 1];
    data[i - 1] = temp;

    return i - 1;
}

float median(int *arr, int len)
{
    char is_odd = (len % 2) == 1;

    int rank = len;
    int m1 = (len - 1) / 2;
    int m2 = m1 + 1;
    int m = m1;
    int offset = 0;
    int count = 0;
    while (1)
    {
        if (rank < m)
        {
            rank += partition(arr + rank + 1, len - rank - 1) + 1;
            offset = rank + 1;
        }
        else
        {
            rank = partition(arr + offset, rank - offset);
        }

        if (rank == m)
        {
            if (is_odd)
            {
                return arr[rank];
            }
            else
            {
                count++;
                if (count == 1)
                    m = m2;
                else
                    return (arr[rank] + arr[rank - 1]) / 2.0;
            }
        }
    }
}

int main()
{
    int arr[] = {0, 9, 1, 5, 6, 3, 4, 2, 7, 8, 10};
    int len = sizeof(arr) / sizeof(int);

    float m = median(arr, len);

    printf("%f\n", m);
}
