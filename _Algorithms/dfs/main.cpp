#include <iostream>

using namespace std;

bool visited[8];
bool adj[8][8]{{0, 1, 1, 0, 0, 0, 0, 1},
               {1, 0, 1, 1, 0, 1, 0, 0},
               {1, 1, 0, 0, 0, 0, 0, 0},
               {0, 1, 0, 0, 1, 0, 0, 0},
               {0, 0, 0, 1, 0, 1, 0, 0},
               {0, 1, 0, 0, 0, 0, 1, 0},
               {0, 0, 0, 0, 0, 1, 0, 0},
               {1, 0, 0, 0, 0, 0, 0, 0}};

int dfs(int u)
{
    int visitedVert = 1;
    visited[u] = true;
    for(int i = 0; i < 8; i++)
        if(adj[u][i] == 1 && !visited[i])
        {
            visitedVert += dfs(i);
            cout << "from " << u << " to " << i << ": " << visitedVert << endl;
        }
    cout << u << " return: " << visitedVert << endl;
    return visitedVert;
}

int main()
{
    cout << dfs(0);
}
