#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.length();
        int max = 0;
        int p = 0;
        int p2 = 0;

        map<char, int> front;
        while (p2 < len)
        {
            if (front.find(s[p2]) != front.end() && front[s[p2]] >= p)
            {
                int plat = (p2 - p);
                if (plat >= max)
                    max = plat;

                p = front[s[p2]] + 1;
            }

            front[s[p2]] = p2;
            p2++;
        }

        int plat = (p2 - p);
        if (plat >= max)
            max = plat;

        return max;
    }
};

int main()
{
    Solution s;
    int len = s.lengthOfLongestSubstring("abba");

    cout << len << endl;
}
