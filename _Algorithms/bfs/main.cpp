#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool adj[8][8]{{0, 1, 1, 0, 0, 0, 0, 1},
               {1, 0, 1, 1, 0, 1, 0, 0},
               {1, 1, 0, 0, 0, 0, 0, 0},
               {0, 1, 0, 0, 1, 0, 0, 0},
               {0, 0, 0, 1, 0, 1, 0, 0},
               {0, 1, 0, 0, 0, 0, 1, 0},
               {0, 0, 0, 0, 0, 1, 0, 0},
               {1, 0, 0, 0, 0, 0, 0, 0}};

int bfs(int s, int dest)
{
    vector<int> d(8);
    fill(d.begin(), d.end(), INT_MAX);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            if(adj[u][i] && d[i] == INT_MAX)
            {
                d[i] = d[u] + 1;
                q.push(i);
            }
        }
    }
    return d[dest];
}

int main()
{
    cout << bfs(3, 0);
}
