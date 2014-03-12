#include <stdio.h>

void PrintContinousSequence(int number)
{
    int begin = 1;
    int end = 1;
    int curr = begin;

    while (begin <= number)
    {
        int sum = 0;
        for (curr = begin; curr <= end; curr++) sum += curr;

        if (sum == number)
        {
            for (int i = begin; i <= end; i++) printf("%d ", i);

            printf("\n");
            end++;
        }
        else if (sum > number)
        {
            begin++;
        }
        else
        {
            end++;
        }
    }
}

int main()
{
    PrintContinousSequence(200);
}
