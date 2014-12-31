#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int count = 0;
        int N;
        scanf("%d", &N);

        int D = N;
        while (D != 0)
        {
            int R = D % 10;
            if (R != 0 && D % R == 0)
                count++;

            D = D / 10;
        }

        printf("%d\n", count);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
