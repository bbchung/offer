#include <stdio.h>

#define MAX(x, y) (((x) >= (y)) ? (x) : (y))
#define MIN(x, y) (((x) <= (y)) ? (x) : (y))

struct IntArray
{
    int *elements;
    int size;
};

int maxProduct(struct IntArray *nums)
{
    int positive[nums->size + 1];
    int negtive[nums->size + 1];

    positive[0] = -999999;
    negtive[0] = 999999;

    int max = -999999;
    int local_max = -999999;

    for (int i = 0; i < nums->size; ++i)
    {
        if (nums->elements[i] > 0)
        {
            positive[i + 1] = MAX(nums->elements[i] * positive[i], nums->elements[i]);
            negtive[i + 1] = MIN(nums->elements[i] * negtive[i], nums->elements[i]);
        }
        else if (nums->elements[i] < 0)
        {
            positive[i + 1] = MAX(nums->elements[i] * negtive[i], nums->elements[i]);
            negtive[i + 1] = MIN(nums->elements[i] * positive[i], nums->elements[i]);
        }
        else
        {
            positive[i + 1] = 0;
            negtive[i + 1] = 0;
        }

        local_max = MAX(local_max, positive[i + 1]);
        local_max = MAX(local_max, negtive[i + 1]);

        if (nums->elements[i] == 0)
        {
            max = MAX(max, local_max);
            local_max = -999999;
        }
    }

    max = MAX(max, local_max);
    return max;
}


int main()
{
    int a[5] = {9, 0, -1, -1, -1};
    struct IntArray ia;
    ia.elements = a;
    ia.size = sizeof(a) / sizeof(int);

    int max = maxProduct(&ia);
    printf("%d\n", max);
}
