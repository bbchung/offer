#include <stdio.h>
#include <string.h>

int main()
{
    char buf[200] = {0};

    scanf("%s", buf);
    int len = strlen(buf);

    int max_len = 0;
    int local_len = 0;
    int depth = 0;

    for (int i = 0; i < len; ++i)
    {
        if (buf[i] == '(')
        {
            ++depth;
        }
        else
        {
            --depth;
            if (depth < 0)
            {
                if (local_len >= max_len)
                    max_len = local_len;

                local_len = 0;
                depth = 0;
            }
            else
            {
                local_len += 2;
            }
        }
    }

    if (local_len >= max_len)
        max_len = local_len;

    printf("%d\n", max_len);
}
