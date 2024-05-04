#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int numVert = 7;
const int s = 0;
const int t = 6;

struct Edge
{
    int cap;
    int flow;
    int s;
    int t;
    Edge *rev = 0;
};

int d[numVert];

int c[numVert][numVert] =
{
    {0, 3, 0, 3, 0, 0, 0},
    {0, 0, 4, 0, 0, 0, 0},
    {3, 0, 0, 1, 2, 0, 0},
    {0, 0, 0, 0, 2, 6, 0},
    {0, 1, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 9},
    {0, 0, 0, 0, 0, 0, 0}
};

int f[numVert][numVert] =
{
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
};

vector<Edge> edges =
{
    {3, 0, 0, 1}, {0, 0, 1, 0},
    {3, 0, 0, 3}, {0, 0, 3, 0},
    {4, 0, 1, 2}, {0, 0, 2, 1},
    {3, 0, 2, 0}, {0, 0, 0, 2},
    {1, 0, 2, 3}, {0, 0, 3, 2},
    {2, 0, 2, 4}, {0, 0, 4, 2},
    {2, 0, 3, 4}, {0, 0, 4, 3},
    {6, 0, 3, 5}, {0, 0, 5, 3},
    {1, 0, 4, 1}, {0, 0, 1, 4},
    {1, 0, 4, 6}, {0, 0, 6, 4},
    {9, 0, 5, 6}, {0, 0, 6, 5}
};

vector<vector<Edge*>> graph =
{
    {&edges[0], &edges[2], &edges[7]},
    {&edges[4], &edges[1], &edges[17]},
    {&edges[6], &edges[8], &edges[10], &edges[5]},
    {&edges[12], &edges[14], &edges[3], &edges[9]},
    {&edges[16], &edges[18], &edges[11], &edges[13]},
    {&edges[20], &edges[15]},
    {&edges[19], &edges[21]}
};

int p[numVert];

bool bfs()
{
    for(int i = 0; i < numVert; i++)
        d[i] = 1000000;

    d[s] = 0;
    queue<int> Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < 22; i++)
        {
            int v = edges[i].t;
            if(f[u][v] < c[u][v] && d[v] == 1000000)
            {
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
    return d[t] != 1000000;
}

int dfs(int u, int minC)
{
    if (u == t || minC == 0)
        return minC;
    for(int v = p[u]; v < 7; v++)
    {
        if(d[v] == d[u] + 1)
        {
            int delta = dfs(v, min(minC, c[u][v] - f[u][v]));
            if(delta != 0)
            {
                f[u][v] += delta;
                f[v][u] -= delta;
                return delta;
            }
        }
        p[u]++;
    }
    return 0;
}

int main()
{
    for(int i = 0; i < 22; i++)
        if(i % 2 == 0)
            edges[i].rev = &edges[i+1];
        else
            edges[i].rev = &edges[i-1];

    int maxFlow = 0;
    while(bfs())
    {
        for(int i = 0; i < 7; i++)
            p[i] = 0;
        int flow = dfs(s, 1000000);
        while(flow != 0)
        {
            maxFlow += flow;
            flow = dfs(s, 1000000);
        }
    }
    cout << maxFlow << endl;
}
