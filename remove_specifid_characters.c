#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *removeChars(const char *str, const char *remove)
{
    char H[26] = {0};

    int rlen = strlen(remove);
    for (int i = 0; i < rlen; ++i)
        H[remove[i] - 'a']++;

    int slen = strlen(str);
    char *ans = malloc(slen);
    memset(ans, 0, slen);

    const char *p1 = str;
    char *p2 = ans;

    while (*p1 != 0)
    {
        if (H[*p1 - 'a'] == 0)
        {
            *p2 = *p1;
            p2++;
        }

        p1++;
    }

    return ans;
}

int main()
{
    char a[101] = {0};
    char b[101] = {0};

    scanf("%s", a);
    scanf("%s", b);
    char *ans = removeChars(a, b);

    printf("%s\n", ans);
}
