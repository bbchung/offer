#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <queue>

int diff_len(char *p, char *q, int M)
{
    int ans = 0;
    int len = 0;
    int diff = 0;

    int i = 0;
    std::queue<int> queue;

    while (1)
    {
        if (p[i] == '\0' || q[i] == '\0')
            break;

        if (p[i] == q[i])
        {
            ++len;
            if (len >= ans)
                ans = len;
        }
        else
        {
            ++diff;
            queue.push(i);
            if (diff > M)
            {
                len = i - queue.front();
                queue.pop();
                --diff;
            }
            else
            {
                ++len;
                if (len >= ans)
                    ans = len;
            }
        }

        ++i;
    }

    return ans;
}

int main()
{
    //    diff_len("abc", "bc", 0);

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        int S;
        char P[1501] = {0};
        char Q[1501] = {0};

        scanf("%d", &S);
        scanf("%s", P);
        scanf("%s", Q);

        int ans = 0;

        int j = 0;

        while (Q[j] != '\0')
        {
            int v = diff_len(P, Q + j, S);

            if (v >= ans)
                ans = v;

            ++j;
        }

        j = 1;
        while (P[j] != '\0')
        {
            int v = diff_len(Q, P + j, S);

            if (v >= ans)
                ans = v;

            ++j;
        }

        printf("%d\n", ans);
    }


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
