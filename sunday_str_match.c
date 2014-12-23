#include <string.h>
#include <stdio.h>

int sunday(char *text, char *pattern)
{
    if (text == NULL || pattern == NULL)
        return -1;

    int p1 = 0; // text pointer

    int len1 = strlen(text);
    int len2 = strlen(pattern);

    int dist[256];
    for (int i = 0; i < 256; ++i)
        dist[i] = -1;

    for (int i = 0; i < len2; ++i)
        dist[pattern[i]] = len2 - i;


    while (p1 + len2 <= len1)
    {
        if (!strncmp(text + p1, pattern, len2))
            return p1;

        if (p1 + len2 == len1)
            break;

        if (dist[text[p1 + len2]] != -1)
        {
            p1 += dist[text[p1 + len2]];
        }
        else
        {
            p1 += (len2 + 1);
        }
    }

    return -1;
}

int main()
{
    printf("%d\n", sunday("ababacab", "ababacab"));
}
