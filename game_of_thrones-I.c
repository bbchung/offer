
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
void findPalind(char *arr)
{
    int rc[26] = {0};
    int len = strlen(arr);

    int r = 0;
    for (int i = 0; i < len; ++i)
        rc[arr[i]-'a']++;

    char flag = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (rc[i] %2 !=0)
        {
            if (flag)
            {
                printf("NO\n");
                return;
            }
            else
            {
                flag = 1;
            }
        }
    }

    printf("YES\n");
}
int main() {

    char arr[100001];
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}

