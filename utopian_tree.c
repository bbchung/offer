#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        int h = 1;
        int N;
        scanf("%d", &N);

        for (int j = 1; j <= N; ++j)
        {
            if (j % 2 == 1)
            {
                h *= 2;
            }
            else
            {
                h += 1;
            }
        }

        printf("%d\n", h);
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
