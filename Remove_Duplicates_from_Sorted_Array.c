#include <stdio.h>


int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return numsSize;

    int p = 1;

    int current = nums[0];

    for (int i = 1; i < numsSize; ++i)
    {
        if (nums[i] != current)
        {
            current = nums[i];
            nums[p] = nums[i];
            p++;
        }
    }

    return p;
}

int main()
{
    int a[5] = {1, 3, 3, 3, 5};

    printf("%d\n", removeDuplicates(a, 5));
}
