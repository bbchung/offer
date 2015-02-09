#include <stdio.h>
#include <stdbool.h>

bool Find(int *matrix, int row, int col, int num)
{
    if (matrix == NULL)
        return false;

    int i = 0;
    int j = col - 1;
    while (i < row && j > 0)
    {
        int val = matrix[i * col + j];
        if (val == num)
        {
            return true;
        }
        else if (val < num)
        {
            i++;
        }
        else if (val > num)
        {
            j--;
        }
    }

    return false;
}

int main()
{
    int data[4][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};


    bool found = Find((int *)data, 4, 4, 0);

    printf("%d\n", found);
}
