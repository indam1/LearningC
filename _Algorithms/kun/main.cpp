#include <iostream>

using namespace std;

bool adj[8][8] = {{0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 5, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0}
};

int matching[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
bool used[8];

bool dfs(int v)
{
    if(used[v])
        return false;
    used[v] = true;

    for(int i = 0; i < 8; i++)
    {
        if(adj[v][i] == true)
        {
            if(matching[i] == -1 || dfs(matching[i]))
            {
                matching[i] = v;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    for(int i = 0; i < 8; i++)
        matching[i] = -1;
    for(int i = 0; i < 8; i++)
    {
        for(int i = 0; i < 8; i++)
            used[i] = false;
        dfs(i);
    }
    for(int i = 0; i < 8; i++)
        cout << matching[i] << " ";

    return 0;
}
