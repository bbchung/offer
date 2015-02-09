#include <stdio.h>
#include <stdlib.h>

int count_digit(int number)
{
    int len = 0;
    int q = number;
    while (1)
    {
        len++;

        q /= 10;
        if (q == 0)
            break;
    }

    if (number < 0)
        len++;

    return len;
}

char *itoa(int number)
{
    int len = count_digit(number) + 1;

    char *buf = malloc(len);
    buf[len - 1] = 0;
    int i = len - 2;

    if (number < 0)
    {
        buf[0] = '-';
        number = -number;
    }

    while (1)
    {
        buf[i] = number % 10 + '0';
        number = number / 10;
        i--;
        if (number == 0)
            break;
    }

    return buf;
}

int main()
{
    printf("%s\n", itoa(100));
}
