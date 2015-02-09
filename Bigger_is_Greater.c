#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        char w[101] = {0};
        scanf("%s", w);

        int len = strlen(w);

        char f = 0;
        for (int j = len-1; j > 0; --j)
        {

            for (int k = j; k < len-1; ++k)
            {
                if (w[k] > w[k+1])
                {
                    char temp = w[k];
                    w[k] = w[k+1];
                    w[k+1] = temp;
                }
            }

            for (int k = j; k < len; ++k) // here can use binary search to boost
            {
                if (w[k] > w[j-1])
                {
                    char temp = w[k];
                    w[k] = w[j-1];
                    w[j-1] = temp;
                    f = 1;
                    break;
                }
            }

            if (f)
                break;
        }

        if (f)
            printf("%s\n", w);
        else
            printf("no answer\n");
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
