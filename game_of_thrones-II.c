#include <stdio.h>
#include <string.h>
#include <math.h>
#define m 1000000007
char s[100005];

int prime_table[100005] = {2, 3, 5};

int main()
{
    scanf("%s", s);
    int len = strlen(s);
    int a[26] = {0};

    for (int i = 0; i < len; ++i)
        a[s[i] - 'a']++;


    int flag = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (a[i] % 2 == 1)
        {
            if (flag)
            {
                printf("%d\n", 0);
                return 0;
            }
            else
            {
                flag = 1;
            }
        }
    }

    len /= 2;
    for (int i = 0; i < 26; ++i)
        a[i] /= 2;

    int f[10005] = {0};

    int i = 0;
    while (1)
    {
        if (prime_table[i] == 0)
        {
            int j = prime_table[i - 1] + 1;
            while (1)
            {
                char is_p = 1;
                for (int k = 0; k < i; ++k)
                {
                    if (j % prime_table[k] == 0)
                    {
                        is_p = 0;
                        break;
                    }
                }

                if (is_p)
                {
                    prime_table[i] = j;
                    break;
                }

                j++;
            }
        }

        if (prime_table[i] > len)
            break;

        int tmp = len;
        while (tmp >= prime_table[i])
        {
            int n = tmp / prime_table[i];

            f[i] += n;
            tmp = n;
        }

        i++;
    }

    for (int j = 0; j < 26; ++j)
    {
        if (a[j] == 0)
            continue;

        int k = 0;
        while (1)
        {
            if (prime_table[k] > a[j])
                break;

            int tmp = a[j];
            while (tmp >= prime_table[k])
            {
                int n = tmp / prime_table[k];

                f[k] -= n;
                tmp = n;
            }

            k++;
        }
    }

    unsigned long long ans = 1;
    for (int j = 0; j < i; ++j)
    {
        for (int k = 0; k < f[j]; ++k)
        {
            ans = (ans * prime_table[j]) % m;
        }
    }

    printf("%llu\n", ans);
}
