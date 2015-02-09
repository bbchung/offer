#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int batoi(char *binary)
{
    int len = strlen(binary);
    int value = 0;
    for (int i = 0; i < len; ++i)
        value += (binary[i] - '0') * pow(2, i);

    return value;
}

char *itoba(int v, int len)
{
    char *buf = malloc(len + 1);
    buf[len] = 0;

    for (int i = 0; i < len; ++i)
    {
        buf[len - 1 - i] = (v & 1) + '0';
        //        printf("buf[%d] = %c\n", len-1-i, (v & 1) + '0');
        v >>= 1;
    }

    return buf;
}

int main()
{
    int N;
    int Q;

    scanf("%d", &N);
    scanf("%d", &Q);

    char szA[N + 1];
    char szB[N + 1];

    scanf("%s", szA);
    scanf("%s", szB);

    int A = batoi(szA);
    int B = batoi(szB);

    char cmd[10] = {0};

    int retval = 0;
    int len = 0;

    for (int i = 0; i < Q; ++i)
    {
        scanf("%s", cmd);

        if (!strcmp(cmd, "set_a"))
        {
            int n;
            int v;
            scanf("%d", &n);
            scanf("%d", &v);

            int s = 1;
            s <<= n;

            if (v)
                A |= s;
            else
                A &= ~s;
        }
        else if (!strcmp(cmd, "set_b"))
        {
            int n;
            int v;
            scanf("%d", &n);
            scanf("%d", &v);

            int s = 1;
            s <<= n;

            if (v)
                B |= s;
            else
                B &= ~s;
        }
        else if (!strcmp(cmd, "get_c"))
        {
            retval <<= 1;

            int v = A + B;
            int n;
            scanf("%d", &n);

            int s = 1 << n;

            v = v & s;
            v >>= n;

            len++;
            retval |= v;
        }
    }

    printf("%s\n", itoba(retval, len));
}
