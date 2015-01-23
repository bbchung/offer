#include<stdio.h>
#include<string.h>
#define m 1000000007
char s[100005]; 

int main()
{
    scanf("%s",s);
    int l = strlen(s);
    int a[26] = {0};

    for (int i = 0; i < l; ++i)
        a[s[i]-'a']++;

    int f=0;
    unsigned long long n = 1;
    int total = 0;
    int k = 0;
    while (k < 26)
    {
        if (a[k]/2 != 0)
            break;

        k++;
    }

    int v = 2;


    for (int i = 0; i < 26; ++i)
    {
        if (a[i] == 0)
            continue;

        if (a[i] % 2 == 1)
        {
            if (f)
            {
                printf("%d\n", 0);
                return 0;
            }
            else
            {
                f = 1;
            }
        }

        for (int j = 0; j < a[i]/2; ++j)
        {
            total++;
            n *= total;

            while (1)
            {
                if (v > a[k]/2)
                {
                    v = 2;

                    while (k < 26)
                    {
                        if (a[k]/2 > 1)
                            break;

                        k++;
                    }
                }

                if (n % v == 0)
                {
                    n /= v;
                    printf("%d %d\n", v, k);
                    v++;
                }
                else
                {
                    break;
                }
            }
        }
    }

    printf("%lld\n", n);
    return 0;
}

