#include <stdio.h>

void rotate(int nums[], int n, int k)
{
    int temp;

    for (int i = 0; i < k; ++i)
    {

        temp = nums[n - 1];
        for (int i = n - 1; i > 0; --i)
            nums[i] = nums[i - 1];

        nums[0] = temp;
    }
}

int main()
{
    int nums[7] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(nums) / sizeof(int);

    rotate(nums, len, 3);

    for (int i = 0; i < len; ++i)
    {
        printf("%d\n", nums[i]);
    }
}
