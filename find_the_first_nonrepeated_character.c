#include <stdio.h>
#include <string.h>

int main()
{
    char S[101] = {0};

    scanf("%s", S);
    int len = strlen(S);

    int H[26][2] = {{0}};
    for (int i = 0; i < len; ++i)
    {
        H[S[i]-'a'][0]++;

        if (H[S[i]-'a'][0] == 1)
            H[S[i]-'a'][1] = i;

    }


    int ans = 10000;
    for (int i = 0; i < 26; ++i)
    {
        if (H[S[i]-'a'][0] == 1 && H[S[i]-'a'][1] < ans)
            ans = H[S[i]-'a'][1];

    }

    if (ans != 10000)
        printf("%c\n", S[ans]);
    else
        printf("no ans\n");


}
