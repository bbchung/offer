#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_digit_or_alphabet(char c)
{
    if (0 <= c - '0' && c - '0' <= 9)
        return true;

    if (0 <= c - 'a' && c - 'a' <= 25)
        return true;

    if (0 <= c - 'A' && c - 'A' <= 25)
        return true;

    return false;
}

char to_lower(char c)
{
    if (0 <= c - 'A' && c - 'A' <= 25)
        return 'a' + c - 'A';

    return c;
}

bool isPalindrome(char *s)
{
    int len = strlen(s);

    int p1 = 0;
    int p2 = len - 1;

    while (p1 < p2)
    {
        if (!is_digit_or_alphabet(s[p1]))
        {
            ++p1;
            continue;
        }

        if (!is_digit_or_alphabet(s[p2]))
        {
            --p2;
            continue;
        }

        if (to_lower(s[p1]) != to_lower(s[p2]))
            return false;

        ++p1;
        --p2;
    }

    return true;
}

int main()
{
    printf("%d\n", isPalindrome("12"));
}
