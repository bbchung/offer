#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);


    for (int i=0;i<T;++i)
    {
        int N;
        scanf("%d", &N);

        int sum = 0, sum1=0;
        int continue_max = -100000;
        int max = -100000;
        for (int j=0;j<N;++j)
        {
            int V;
            scanf("%d", &V);
            
            if (sum1 <= 0 || V > 0)
                sum1 += V;

            if (sum1 > max)
                max = sum1;

            if (sum1 < 0)
                sum1 = 0;

            sum += V;
            
            if (sum > continue_max)
                continue_max = sum;
           
            if (sum < 0)
                sum = 0;
        }

        printf("%d %d\n", continue_max, max);
    }

    return 0;
}

