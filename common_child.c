#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    char A[5001] = {0};
    char B[5001] = {0};

    scanf("%s", A);
    scanf("%s", B);

    int S[2][5001] = {{0}, {0}};
    int SI;

    for (unsigned int i = 1; i <= strlen(B); ++i)
    {
        SI = i % 2;
        int LSI = (i - 1) % 2;

        for (unsigned int j = 1; j <= strlen(A); ++j)
        {
            if (A[j - 1] == B[i - 1])
            {
                S[SI][j] = S[LSI][j - 1] + 1;
            }
            else
            {
                S[SI][j] = MAX(S[SI][j - 1], S[LSI][j]);
            }
        }
    }

    printf("%d\n", S[SI][strlen(A)]);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
