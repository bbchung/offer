#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> V;

    for (int i = 0; i < N; ++i)
    {
        int v;
        cin >> v;
        V.push_back(v);
    }

    if(V.size() <= 1)
        return 0;

    int c = 1;
    int index = 1;

    if (V.size() <= 1)
        return 0;

    for (int i = 1; i < V.size(); ++i)
    {
        if (V[i] == V[i-1])
        {
            c++;
            if (c <= 2)
            {
                V[index++] = V[i];
            }
        }
        else
        {
            c = 1;
            V[index++] = V[i];
        }
    }

    for (int i = 0; i < index; ++i)
    {
        cout << V[i] << " ";
    }
    cout << endl;
}
