#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    int max = 0;
    int p = 0;
    int p2 = 0;

    int front[26] = {0};
    while (p2 < len)
    {
        int index = s[p2]-'a';
        if (front[index] != 0)
        {
            int plat = (p2 - p);
            if (plat >= max)
                max = plat;

            p = front[index];
        }

        front[index] = p2 + 1;
        p2++;
    }

    int plat = (p2 - p);
    if (plat >= max)
        max = plat;

    return max;
}

int main()
{
    int len = lengthOfLongestSubstring("abcbdefgg");
    printf("%d\n", len);
}
