#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        int len = s.length();

        vector<vector<string>> vv;

        for (int i = 1; i <= len; ++i)
        {
            string left = s.substr(0, i);

            if (!is_palindrome(left))
                continue;

            vector<vector<string>> ret = partition(s.substr(i, len - i));

            vector<string> v;
            v.push_back(left);

            if (ret.empty())
            {
                vv.push_back(v);
            }
            else
            {
                for (vector<vector<string>>::iterator it = ret.begin(); it != ret.end(); it++)
                {
                    vector<string> copy = v;
                    copy.insert(copy.end(), it->begin(), it->end());
                    vv.push_back(copy);
                }
            }
        }

        return vv;
    }


private:
    bool is_palindrome(string s)
    {
        if (s.empty())
            return false;

        size_t len = s.length();
        for (size_t i = 0; i < len / 2; ++i)
        {
            if (s[i] != s[len - 1 - i])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<string> v;
    v.push_back("a");
    vector<vector<string>> vv;
    vv.push_back(v);

    s.partition("ab");
}
