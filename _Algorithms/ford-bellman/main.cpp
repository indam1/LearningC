#include <iostream>

using namespace std;

struct Vert
{
    int a;
    int b;
    int cost;
};

Vert ribs[20] =
{
    {0, 1, 3}, {1, 2, 6}, {2, 3, 15}, {3, 4, 7}, {4, 0, 14},
    {0, 2, 8}, {0, 3, 5}, {1, 3, 4}, {1, 4, 2}, {2, 4, 1},
    {1, 0, 3}, {2, 1, 6}, {3, 2, 15}, {4, 3, 7}, {0, 4, 14},
    {2, 0, 8}, {3, 0, 5}, {3, 1, 4}, {4, 1, 2}, {4, 2, 1},
};

void fB(int s)
{
    int d[5][5];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            d[i][j] = 1000000;
    for(int i = 0; i < 5; i++)
        d[i][s] = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            d[i+1][ribs[j].b] = min(d[i+1][ribs[j].b], d[i][ribs[j].a] + ribs[j].cost);
        }
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    fB(0);
    return 0;
}
