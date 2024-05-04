#include <iostream>

using namespace std;

int adj[6][6] = {{ 0,  0, 23,  0, 55,  0},
    { 0,  0, 10, 72,  0, 45},
    {23, 10,  0, 63,  4,  0},
    { 0, 72, 63,  0,  0,  0},
    {55,  0,  4,  0,  0,  0},
    { 0, 45,  0,  0,  0,  0}
};

void floyd()
{
    int d[6][6];

    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            if(adj[i][j] == 0)
                d[i][j] = 1000000;
            else
                d[i][j] = adj[i][j];
        }

    for(int i = 0; i < 6; i++)
        for(int u = 0; u < 6; u++)
            for(int v = 0; v < 6; v++)
                d[u][v] = (d[u][v] < d[u][i] + d[i][v]) ? d[u][v] : d[u][i] + d[i][v];

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    floyd();
    return 0;
}
