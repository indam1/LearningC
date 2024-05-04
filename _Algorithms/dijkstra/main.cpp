#include <iostream>

using namespace std;

struct Vert
{
    int a;
    int b;
    int cost;
};

int adj[6][6] = {{ 0,  0, 23,  0, 55,  0},
                 { 0,  0, 10, 72,  0, 45},
                 {23, 10,  0, 63,  4,  0},
                 { 0, 72, 63,  0,  0,  0},
                 {55,  0,  4,  0,  0,  0},
                 { 0, 45,  0,  0,  0,  0}};

Vert ribs[14] = {{0, 2, 23}, {0, 4, 55}, {1, 2, 10}, {1, 3, 72}, {1, 5, 45}, {2, 3, 63}, {2, 4, 4},
                 {2, 0, 23}, {4, 0, 55}, {2, 1, 10}, {3, 1, 72}, {5, 1, 45}, {3, 2, 63}, {4, 2, 4}};

void dijkstra(int s)
{
    int d[6];
    bool used[6];
    for(int i = 0; i < 6; i++)
        d[i] = 1000000;
    d[s] = 0;
    for(int i = 0; i < 6; i++)
    {
        int v = -1;
        for(int j = 0; j < 6; j++)
        {
            if(!used[j] && (v == -1 || d[j] < d[v]))
               v = j;
        }
        if(d[v] == 1000000)
            break;
        used[v] = true;
        for(int j = 0; j < 6; j++)
        {
            if(adj[v][j] > 0 && d[v] + adj[v][j] < d[j])
                d[j] = d[v] + adj[v][j];
        }
    }
    for(int i = 0; i < 6; i++)
        cout << d[i] << " ";
    cout << endl;
}

int main()
{
    dijkstra(0);
    return 0;
}
