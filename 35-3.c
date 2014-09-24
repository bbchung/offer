#include <stdio.h>
#include <string.h>

void RemoveDupFast(char *str)
{
    if (str == NULL)
        return;

    char hash[256] = { 0 };

    char *p1 = str;
    char *p2 = str;

    while (*p2 != '\0')
    {
        hash[*p2]++;

        if (hash[*p2] == 1)
        {
            *p1 = *p2;
            p1++;
        }

        p2++;
    }

    *p1 = '\0';
}

void RemoveDup(char *str) // bad implement
{
    if (str == NULL)
        return;

    int len = 0;
    int i = 0;
    while (str[i] != '\0')
        ++i;

    len = i;

    char hash[256] = { 0 };
    for (i = 0; i < len; ++i)
        hash[str[i]]++;

    char *p1 = str + len - 1;
    char *p2 = NULL;

    while (p1 >= str)
    {
        if (hash[*p1] > 1)
        {
            if (p2 == NULL)
                p2 = p1 + 1;

            hash[*p1]--;
        }
        else
        {
            if (p2 != NULL)
            {
                strcpy(p1 + 1, p2);
                p2 = NULL;
            }
        }

        p1--;
    }
}

int main()
{
    char str[] = "hellohello";
    RemoveDupFast(str);

    printf("%s\n", str);
}
