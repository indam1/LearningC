#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

bool kuhn(int v)
{
    if(used[v]) return false;
    used[v] = true;
    for(size_t i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];

        if(mt[to] == -1 || kuhn(mt[to]))
        {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    const int n = 26;
    string words[n];

    for(int i = 0; i < n; i++)
        cin >> words[i];

    for(int i = 0; i < n; i++)
    {
        g.push_back(vector<int>());
        for(int j = 0; j < (int)words[i].length(); j++)
        {
            bool kek = true;
            int index = words[i][j] - 97;
            for(int k = 0; k < j; k++)
            {
                int index2 = words[i][k] - 97;
                if(index2 == index)
                {
                    kek = false;
                    break;
                }
            }
            if(kek)
                g[i].push_back(index);
        }
    }

    cout << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (int)g[i].size(); j++)
            cout << g[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    mt.assign (n, -1);

    for(int v = 0; v < n; v++)
    {
        used.assign(n, false);
        kuhn(v);
    }

    for(int i = 0; i < n; i++)
        if(mt[i] != -1)
            cout << mt[i]+1 << " " << i + 1 << " " << words[mt[i]] << " " << char(i+97) << endl;

    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        if(mt[i] != -1)
            counter++;
    }
    if(counter == 26)
        cout << "true: " << counter << endl;
    else
        cout << "false: " << counter << endl;
}
