#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        int S;
        scanf("%d", &S);
        int N;
        scanf("%d", &N);
        int A[N];
        memset(A, 0, N * sizeof(int));
        for (int j = 0; j < N; ++j)
            scanf("%d", A+j);

        for (int j = 0; j < N; ++j)
        {
            for (int k = j+1; k < N; ++k)
            {
                if (A[j] + A[k] == S)
                    printf("%d %d\n", j+1, k+1);
            }
        }

    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
