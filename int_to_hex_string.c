#include <stdio.h>
#include <stdlib.h>

void ReverseStr(char *begin, char *end)
{
    if (begin == NULL || end == NULL)
        return;

    while (end > begin)
    {
        char temp = *begin;
        *begin = *end;
        *end = temp;

        end--;
        begin++;
    }
}

char *IntToHexStr(int number)
{
    bool signbit = (number < 0);

    int curr = number;

    if (signbit)
        curr = -curr;

    int len = 0;

    while (true)
    {
        len++;
        if ((curr /= 16) == 0)
            break;
    }

    if (signbit)
        len++;

    char *str = (char *)malloc(len + 1);
    str[len] = '\0';

    curr = number;
    if (signbit)
        curr = -curr;

    for (int i = 0; i < len; i++)
    {
        int r = curr % 16;
        curr /= 16;
        if (0 <= r && r <= 9)
            str[i] = r + '0';
        else
            str[i] = r - 10 + 'a';
    }

    if (signbit)
        str[len - 1] = '-';

    ReverseStr(str, str + len - 1);

    return str;
}

int main()
{
    char *str = IntToHexStr(-0xffdd11);

    printf("%s\n", str);
}
