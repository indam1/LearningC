#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> net =
{
    {1, 2, 3, 4}, {2, 5}, {3, 6}, {4, 7, 8}, {8},
    {2, 9}, {3, 5, 10}, {6, 11, 12}, {7, 12}, {6, 13},
    {7, 11, 13}, {10, 13}, {11, 13}
};

const int numVert = 14;

int c[numVert][numVert] =
{
    {0, 6, 6, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 3, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 0, 0, 5, 10, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0},
    {0, 0, 9, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0},
    {0, 0, 0, 10, 0, 8, 0, 0, 0, 0, 5, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 5, 12, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 7, 0},
    {0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 6},
    {0, 0, 0, 0, 0, 0, 0, 12, 0, 8, 0, 0, 0, 9},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 7},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 6},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int f[numVert][numVert];

bool vis[numVert];

int dfs(int u, int Cmin)
{
    if(u == 13)
        return Cmin;
    vis[u] = true;
    for(int i = 0; i < (int)net[u].size(); i++)
    {
        int v = net[u][i];
        cout << u << " (vert): " << v << endl;
        if(!vis[v] && f[u][v] < c[u][v])
        {
            int delta = dfs(v, min(Cmin, c[u][v]-f[u][v]));
            cout << u << " (delta): " << delta << endl;
            if(delta > 0)
            {
                f[u][v] += delta;
                f[v][u] -= delta;
                return delta;
            }
        }
    }
    return 0;
}

int main()
{
    for(int i = 0; i < numVert; i++)
        for(int j = 0; j < numVert; j++)
            f[i][j] = 0;
    int a = 1;
    while(a)
    {
        for(int i = 0; i < numVert; i++)
            vis[i] = 0;
        a = dfs(0, 29);
    }
    for(int i = 0; i < numVert; i++)
    {
        for(int j = 0; j < numVert; j++)
            cout << f[i][j] << " ";
        cout << endl;
    }
    return 0;
}
