#include <string.h>
#include <stdio.h>

int kmp_search(char *text, char *pattern)
{
    int p1 = 0; // text pointer

    int len1 = strlen(text);
    int len2 = strlen(pattern);

    int f[len2];

    for (int i = 0; i < len2; i++)
    {
        if (i == 0)
        {
            f[i] = -1;
        }
        else
        {
            if (pattern[0] == pattern[i])
                f[i] = f[i - 1] + 1;
            else
                f[i] = -1;
        }
    }

    while (p1 + len2 <= len1)
    {
        int p2 = 0;

        while (1)
        {
            if (p2 == len2)
                return p1;

            if (text[p1 + p2] != pattern[p2])
                break;

            p2++;
        }

        if (p2 == 0)
            p1 += 1;
        else
            p1 = p1 + p2 - 1 - f[p2 - 1];
    }

    return -1;
}

int main()
{
    printf("%d\n", kmp_search("ababcab", "xyz"));
}
