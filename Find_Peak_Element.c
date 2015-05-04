#include <stdio.h>

int find(int *nums, int start, int end)
{
    if (start == end)
        return start;

    int index = (start + end) / 2;

    if ((index == start || nums[index] > nums[index - 1]) && (nums[index] > nums[index + 1]))
        return index;

    if (index == start || nums[index] < nums[index + 1])
        return find(nums, index + 1, end);

    if (nums[index] < nums[index - 1])
        return find(nums, start, index - 1);

    return -1;
}

int findPeakElement(int *nums, int numsSize)
{
    return find(nums, 0, numsSize - 1);
}

int main()
{
    int data[3] = {2, 1, 2};

    printf("%d\n", findPeakElement(data, sizeof(data) / sizeof(int)));
}
