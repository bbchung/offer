#include <stdio.h>

void swap(char* a, char* b)
{
    if (a == NULL || b == NULL)
        return;
    
    char temp = *a;
    *a = *b;
    *b = temp;
}

void Permutation2(char* str, char* pBegin)
{
    if (*pBegin == '\0')
    {
        printf("%s\n", str);
        return;
    }

    char* curr = pBegin;

    while (*curr != '\0')
    {
        swap(pBegin, curr);
        Permutation2(str, pBegin + 1);
        swap(pBegin, curr);
        curr++;
    }
}

void Permutation(char* str)
{
    if (str == NULL)
        return;

    Permutation2(str, str);
}

int main()
{
    char str[] = "abc";

    Permutation(str);
}
