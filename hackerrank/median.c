#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

void median(vector<char> s, vector<int> X)
{
}


int main(void)
{

    //Helpers for input and output

    int N;
    cin >> N;

    vector<char> s;
    vector<int> X;
    char temp;
    int tempint;
    for (int i = 0; i < N; i++)
    {
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }

    median(s, X);
    return 0;
}
