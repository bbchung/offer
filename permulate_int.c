#include <stdio.h>


void print_permulate(int *data, int len, int *print, int size, int *count)
{
    for (int i = 0; i < len; ++i)
    {
        char dup = 0;
        for (int j = 0; j < size; ++j)
        {
            if (data[i] == print[j])
            {
                dup = 1;
                break;
            }
        }

        if (!dup)
        {
            print[size] = data[i];

            if (size + 1 == len)
            {
                (*count)++;
                /*for (int k = 0; k < len; k++)*/
                    /*printf("%d ", print[k]);*/

                /*printf("\n");*/
                return;
            }

            print_permulate(data, len, print, size+1, count);
        }
    }
}

int permulate(int *data, int len)
{
    int print[len];
    int count = 0;
    print_permulate(data, len, print, 0, &count);

    return count;
}

int main()
{
    int data[10];
    int size = sizeof(data)/sizeof(int);

    for (int i = 0; i < size; ++i) {
       data[i]  = i;
    }


    int count = permulate(data, size);

    printf("total permulating: %d\n", count);
}
