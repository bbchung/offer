#include "stdio.h"

#define MIN(x, y) ((x) <= (y)) ? (x) : (y)

int trap(int *height, int heightSize)
{
    int left_highest[heightSize];
    int right_highest[heightSize];

    int highest = 0;
    for (int i = 0; i < heightSize; ++i)
    {
        left_highest[i] = highest;

        if (height[i] > highest)
            highest = height[i];
    }

    highest = 0;
    for (int i = heightSize - 1; i >= 0; --i)
    {
        right_highest[i] = highest;

        if (height[i] > highest)
            highest = height[i];
    }

    int water = 0;
    for (int i = 0; i < heightSize; ++i)
    {
        int min = MIN(left_highest[i], right_highest[i]);

        if (min > height[i])
            water += (min - height[i]);
    }

    return water;
}

int main()
{
    int height[12] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    int water = trap(height, 12);

    printf("%d\n", water);
}
