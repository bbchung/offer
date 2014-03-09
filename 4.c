#include <stdio.h>

void ReplaceSpace(char str[], int len)
{

    if (str == NULL || len == 0)
        return;

    int i = 0;
    int count = 0;
    for (i; i < len; i++)
    {
        if (str[i] == ' ')
            count++;
    }

    int len2 = len + count * 2;

    char* p1 = str + len;
    char* p2 = str + len2;

    while (p1 != p2)
    {
        if (*p1 == ' ')
        {
            *p2 = '0';
            *(--p2) = '2';
            *(--p2) = '%';
        }
        else
        {
            *p2 = *p1;
        }

        --p2;
        --p1;
    }
}

int main() 
{
    char str[100] = "we are happy";
    
    ReplaceSpace(str, 12);

    printf("%s\n", str);
}
