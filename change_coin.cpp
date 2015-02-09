#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;
int M[4] = {2, 3, 5, 6};
int c[1000 + 1];

void change(int m) // 看看 {5, 2, 6, 11, 17} 湊得價位 m 的湊法有幾種
{
    memset(c, 0, sizeof(c)); // 預設為湊不到，每一格都為 0。
    c[0] = 1;                // 預設價位為 0 時一定湊得到

    for (int i = 0; i < 4; ++i)
        for (int j = M[i]; j <= m; ++j)
        {
            c[j] += c[j - M[i]]; // 湊、湊、湊
            if (j == 5)
            {
                printf("+=c[%d](%d)\n", j - M[i], c[j - M[i]]);
            }
        }

    //cout << "湊得價位" << m
    //<< "的湊法有" << c[m] << "種" << endl;

    for (int i = 0; i <= 5; ++i)
    {
        cout << "湊得價位" << i
             << "的湊法有" << c[i] << "種" << endl;
    }
}

int main()
{
    change(5);
}
