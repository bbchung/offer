#include <stdio.h>
#include <string.h>

void remove_dup_char(char *src)
{
    if (src == NULL)
        return;

    int len = strlen(src);
    char dup[256] = {0};

    int p1 = 0;

    for (int i = 0; i < len; ++i)
    {
        dup[src[i]]++;

        if (dup[src[i]] <= 1)
        {
            src[p1] = src[i];
            p1++;
        }
    }

    src[p1] = 0;
}

int main()
{
    char text[256] = "abcadxyzcuz";
    remove_dup_char(text);
    printf("%s\n", text);
}
