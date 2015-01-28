#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX(x, y) ((x) >= (y) ? (x) : (y))

typedef struct
{
    int from;
    int to;
} Range;

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

Range intersect(Range r1, Range r2)
{

    Range r;
    r.from = (r1.from >= r2.from) ? r1.from : r2.from;
    r.to = (r1.to <= r2.to) ? r1.to : r2.to;

    return r;
}

int main()
{
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", A + i);

    qsort(A, N, sizeof(int), compare);

    int P, Q;

    scanf("%d", &P);
    scanf("%d", &Q);

    int max = -1;
    int ans = 0;
    Range R = {P, Q};

    for (int i = 0; i < N; ++i)
    {
        Range r;
        r.from = -1;
        r.to = 1000000001;

        if (i > 0)
        {
            r.from = (A[i] + A[i - 1] + 1) / 2;
        }

        if (i < N - 1)
        {
            r.to = (A[i + 1] + A[i] - 1) / 2;
        }

        r = intersect(R, r);

        if (r.from > r.to)
            continue;

        int d1 = abs(r.from - A[i]);
        int d2 = abs(r.to - A[i]);

        if (d1 > max)
        {
            max = d1;
            ans = r.from;
        }
        if (d2 > max)
        {
            max = d2;
            ans = r.to;
        }
    }

    printf("%d\n", ans);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
