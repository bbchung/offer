#include <stdio.h>

char FindFirstNotDupCharacter(char *str, unsigned int len)
{
    if (str == NULL || len == 0)
        return '\0';

    int hash[256] = {0};

    int i;
    for (i = 0; i < len; ++i)
        hash[(int)str[i]]++;


    for (i = 0; i < len; ++i)
    {
        if (hash[str[i]] == 1)
            return str[i];
    }

    return '\0';
}

int main()
{

    char *str = "helhlo";
    char c = FindFirstNotDupCharacter(str, 5);

    printf("%c\n", c);
}
