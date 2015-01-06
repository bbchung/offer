#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        char buf[10001] = {0};

        scanf("%s", buf);

        int len = strlen(buf);
        if (len % 2 != 0)
        {
            printf("-1\n");
            continue;
        }

        int r[26] = {0};
        
        for (int j = 0; j < len/2; ++j)
            r[buf[j]-'a']++;

        for (int j = len/2; j < len; ++j)
            r[buf[j]-'a']--;


        int count=0;
        for (int j = 0; j  < 26; ++j )
        {
            if (r[j] > 0)
                count+=r[j];
        }

        printf("%d\n", count);

    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

