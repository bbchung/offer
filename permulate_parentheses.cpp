#include <stdio.h>
#include <list>
#include <string>

std::list<std::string> permulate_parentheses(int n)
{
    std::list<std::string> list;
    if (n < 1)
    {
    }
    else if (n == 1)
    {
        list.push_back("()");
    }
    else
    {
        std::list<std::string> inner_list = permulate_parentheses(n - 1);
        std::list<std::string>::iterator it;

        for (it = inner_list.begin(); it != inner_list.end(); it++)
        {
            if (it != inner_list.begin())
                list.push_back("()" + *it);

            list.push_back(*it + "()");
            list.push_back("(" + *it + ")");
        }
    }

    return list;
}

int main()
{
    std::list<std::string> list = permulate_parentheses(4);

    std::list<std::string>::iterator it;
    for (it = list.begin(); it != list.end(); it++)
    {
        printf("%s\n", (*it).c_str());
    }
}
