#include <stdio.h>

int swap(int *data, int len)
{
    int p = data[0];
    int i = 1;
    int j = len - 1;

    while (j > i)
    {
        if (data[j] < p && data[i] > p)
        {
            int tmp = data[j];
            data[j] = data[i];
            data[i] = tmp;
        }

        if (data[j] >= p)
            j--;

        if (data[i] <= p)
            i++;
    }
    printf("%d\n", data[0]);

    int tmp = data[0];
    data[0] = data[j];
    data[j] = tmp;
    
    return j;
}

void qsort(int *data, int len)
{
    if (len <= 1)
        return;

    int k = swap(data, len);
    qsort(data, k);
    qsort(data + k + 1, len - k - 1);
}

void dump(int *data, int len)
{
    for (int i=0;i<len;i++)
        printf("%d ", data[i]);

    printf("\n");
}

int main()
{
    int data[] = {3, 2, 4, 5, 1, 9, 0};
    int len = sizeof(data)/sizeof(int);

    dump(data, len);
    qsort(data, len);
    dump(data, len);
}
