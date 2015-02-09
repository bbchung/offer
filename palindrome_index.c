#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        char S[100005] = {0};

        scanf("%s", S);
        int len = strlen(S);

        int index = -1;
        for (int i = 0; i < len; ++i)
        {
            if (S[i] != S[len - 1 - i])
            {
                index = i;

                int j = 0, k = len - 1;

                while (j < len && k >= 0)
                {
                    if (j == i)
                    {
                        j++;
                        continue;
                    }

                    if (k == i)
                    {
                        k--;
                        continue;
                    }

                    if (S[j] != S[k])
                    {
                        index = len - 1 - index;
                        break;
                    }

                    j++;
                    k--;
                }

                break;
            }
        }

        printf("%d\n", index);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
