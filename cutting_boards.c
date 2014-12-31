#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; ++i)
    {
        
        int S = 0;
        int N1, N2;
        scanf("%d", &N1);
        scanf("%d", &N2);
        --N1;
        --N2;

        int A1[N1], A2[N2];

        for (int j = 0; j < N1; ++j)
            scanf("%d", A1 + j);

        for (int j = 0; j < N2; ++j)
            scanf("%d", A2 + j);

        qsort(A1, N1, sizeof(int), compare);
        qsort(A2, N2, sizeof(int), compare);

        printf("%d\n", S % (1000000000+7));

        /*W(i, j)
         * 2 * min(Rn[i], Rn[j]) + max(Rn[i], Rn[j]), if i == 0 or j == 0
         * or
         * min(M[i] + W(i-1, j) + Rn[j], N[j] + W(i, j-1) + Rm[i])
         */
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
