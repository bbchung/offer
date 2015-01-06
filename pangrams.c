#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char upper_to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return ('a' + c - 'A');
    else
        return c;
}

int main()
{
    char buf[1000] = {0};
    scanf("%[^\n]", buf);

    char record[26] = {0};

    for (unsigned int i = 0; i < strlen(buf); ++i)
    {
        char c = upper_to_lower(buf[i]);

        if (c >= 'a' && c <= 'z')
            record[c-'a'] = 1;
    }

    for (int i = 0; i < 26; ++i)
    {
        if (record[i] == 0)
        {
            printf("not pangram\n");
            return 0;
        }
    }

    printf("pangram\n");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
