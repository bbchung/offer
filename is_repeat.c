#include <stdio.h>
#include <string.h>

int is_repeat(char *A)
{
    int n = strlen(A);
    int len = 0;
    int p = 0;

    for (int i = 0; i < n; ++i)
    {
        if (A[i] == A[p])
        {
            if (len > 0)
                p = (p+1) % len;
        }
        else
        {
            len = i+1;
            p=0;
        }

        if (len == 0)
            len = 1;
    }

    return len;
}

int main()
{
    printf("%d\n", is_repeat("aabaac"));
}
