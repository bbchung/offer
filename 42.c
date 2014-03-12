#include <stdio.h>

void ReverseString(char* pBegin, char* pEnd)
{
    if (pBegin == NULL || pEnd == NULL)
        return;

    while (pBegin < pEnd )
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin++;
        pEnd--;
    }
}

void ReverseSentence(char* pString)
{
    if (pString == NULL)
        return;

    char* curr = pString;
    while (*curr != '\0')
        curr++;

    ReverseString(pString, --curr);

    curr = pString;
    char* pBegin = pString;
    while (1)
    {
        if ((*curr == ' ' || *curr == '\0'))
        {
            if  (curr > pBegin)
            {
                ReverseString(pBegin, --curr);
                ++curr;
            }

            if (*curr == '\0')
                break;

            pBegin = ++curr;
        }
        else
        {
            ++curr;
        }
    }
}

int main()
{
    char str[] = "";
    ReverseSentence(str);

    printf("%s\n", str);
}
