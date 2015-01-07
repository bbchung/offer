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
        char S[101] = {0};
        scanf("%s", S);
        int len = strlen(S);

        int r[101][101][26]={{{0}}};


        for (int j = 1; j <= len; ++j)
        {
            for (int k = j; k <= len; ++k)
            {
                for (int l = 0; l < 26; ++l)
                {
                    r[j][k][l] = r[j][k-1][l];
                }
                    
                r[j][k][S[k-1]-'a']++;
            }
        }

        int count=0;

        for (int j = 1; j <= len; ++j)
        {
            for (int k = j; k <= len; ++k)
            {

                for (int l = j+1; l <= len; ++l)
                {
                    for (int m = k+1; m <= len; ++m)
                    {
                        char same=1;
                        for (int n = 0; n < 26; ++n)
                        {
                            if (r[j][k][n] != r[l][m][n])
                            {
                                same = 0;
                                break;
                            }

                        }

                        if (same)
                        {
                            count++;
                        }
                    }
                }

            }
        }
        printf("%d\n", count);


    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
