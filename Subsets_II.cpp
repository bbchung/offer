#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S)
    {
        std::sort(S.begin(), S.end());

        vector<vector<int> > ret;
        vector<int> history;

        vector<int>::iterator it = S.begin();
        subset(ret, S, it, history);

        return ret;
    }

private:
    void subset(vector<vector<int> > &ret, vector<int> &S, vector<int>::iterator it, vector<int> history)
    {
        int count = 0;
        vector<int>::iterator current = it;

        for (; it != S.end(); it++)
        {
            if (*current != *it)
            {
                for (int i = 0; i <= count; ++i)
                {
                    vector<int> v = history;
                    for (int j = 0; j < i; ++j)
                        v.push_back(*current);

                    subset(ret, S, it, v);
                }

                return;
            }
            else
            {
                count++;
            }
        }

        for (int i = 0; i <= count; ++i)
        {
            vector<int> v = history;
            for (int j = 0; j < i; ++j)
                v.push_back(*current);

            //            std::sort(v.begin(), v.end());
            ret.push_back(v);
        }
    }
};

int main()
{
    Solution s;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);

    vector<vector<int> > ret = s.subsetsWithDup(v);

    for (vector<vector<int> >::iterator it1 = ret.begin(); it1 != ret.end(); it1++)
    {
        for (vector<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
        {
            cout << *it2 << " ";
        }

        cout << endl;
    }
}
