#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isIsomorphic(char *s, char *t)
{
    char map[256] = {0};
    char map2[256] = {0};

    int p = 0;

    while (s[p] != 0)
    {
        if (t[p] == 0)
            return false;

        if (map[s[p] - 0] == 0 && map2[t[p] - 0] == 0)
        {
            map[s[p] - 0] = t[p];
            map2[t[p] - 0] = s[p];
        }
        else
        {
            if (map[s[p] - 0] != t[p] || map2[t[p] - 0] != s[p])
                return false;
        }

        p++;
    }

    return t[p] == 0;
}

int main()
{
    bool iso = isIsomorphic("aa", "bb");

    printf("%d\n", iso);
}
