#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);

    int r = 2;
    for (int d=2; d<=N; ++d)
    {
        if (d == r*r)
        {
            r++;
            continue;
        }
        int x = 1;
        int y = 1;
        while (1)
        {
            char found=0;
            for (y=1;y<=x;++y)
            {
                if (x*x-d*y*y == 1)
                {
                    found = 1;
                    break;
                }
            }
            
            if (found)
                break;

            x++;
        }

        printf("%d\n", x);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

