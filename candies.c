#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);

    int count = 1;
    int dr = 0;
    int need = 0;
    int pre;
    int pre_count = 0;
    for (int i = 0; i < N; ++i)
    {
        int v;
        scanf("%d", &v);

        if (i == 0)
        {
            pre = v;
            need = 1;
            continue;
        }

        if (dr > 0)
        {
            if (v > pre)
            {
                count++;
                need += count;
            }
            else if (v < pre)
            {
                need -= 1;
                pre_count = count;
                count = 2;
                need += 3;
            }
            else
            {
                need += 1;
                need -= 1;
                pre_count = count;
                count = 1;
            }
        }
        else if (dr < 0)
        {
            if (v < pre)
            {
                count++;
                need += count;
            }
            else if (v > pre)
            {
                need -= (count < pre_count) ? count : pre_count;
                pre_count = count;
                count = 2;
                need += 3;
            }
            else
            {
                need += 1;
                need -= (count < pre_count) ? count : pre_count;
                pre_count = count;
                count = 1;
            }
        }
        else
        {
            if (v != pre)
            {
                count = 2;
                need += 3;
            }
            else
            {
                need += 1;
            }
        }

        if (v > pre)
            dr = 1;
        else if (v < pre)
            dr = -1;
        else
            dr = 0;

        pre = v;
    }

    if (dr < 0)
    {
        need -= (count < pre_count) ? count : pre_count;
    }
    else if (dr > 0)
        need -= 1;

    printf("%d\n", need);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
