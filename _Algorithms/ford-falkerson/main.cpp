#include <iostream>

using namespace std;

struct Coord
{
    int x;
    int y;
};

Coord coords[6] = {{0, 0}, {0, 2}, {1, 0}, {1, 3}, {2, 1}, {3, 3}};
int px[4] = {-1, -1, -1, -1};
int py[4] = {-1, -1, -1, -1};
bool vis[4];
bool isPath = true;

bool dfs(int u)
{
    cout << "DFS: " << u << endl;
    if(vis[u])
        return false;
    vis[u] = true;
    for(int i = 0; i < 6; i++)
    {
        if(coords[i].x == u)
        {
            if(py[coords[i].y] == -1)
            {
                py[coords[i].y] = u;
                px[u] = coords[i].y;
                return true;
            }
            else if(dfs(py[coords[i].y]))
            {
                py[coords[i].y] = u;
                px[u] = coords[i].y;
                return true;
            }
        }
    }
    return false;
}

void fordFalk()
{
    while(isPath)
    {
        for(int i = 0; i < 4; i++)
            vis[i] = false;
        isPath = false;

        for(int i = 0; i < 4; i++)
        {
            if(px[i] == -1)
            {
                if(dfs(i))
                    isPath = true;
            }
        }
    }
}

int main()
{
    fordFalk();
    for(int i = 0; i < 4; i++)
        cout << px[i] << " " << py[i] << endl;
    return 0;
}
