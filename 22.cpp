#include <stdio.h>
#include <stack>

using namespace std;
bool IsPopOrder(const int *push, const int *pop, int len)
{
    if (push == NULL || pop == NULL || len <= 0)
        return false;

    stack<int> helper;

    int p1 = 0;
    int p2 = 0;


    while (p2 < len)
    {
        if (helper.size() == 0 || helper.top() != pop[p2])
        {
            if (p1 >= len)
                return false;

            helper.push(push[p1]);
            p1++;
        }
        else
        {
            helper.pop();
            p2++;
        }
    }

    return true;
}

int main()
{
    int push[] = { 1, 2, 3, 4, 5 };
    int pop[] = { 4, 5, 3, 2, 1 };

    bool ret = IsPopOrder(push, pop, 5);
    printf("%d\n", ret);
}
