#include <iostream>

using namespace std;

struct edge
{
    int s;
    int t;
    double cap;
    double flow;
    double price;
};;

edge edges[8] = {
{0, 1, 2, 0, 2}, {0, 3, 2, 0, 1},
{0, 4, 1, 0, 2}, {1, 2, 1, 0, 1},
{1, 3, 1, 0, 1}, {2, 5, 4, 0, 2},
{3, 5, 3, 0, 2}, {4, 2, 2, 0, 2}
};

int s = 0;
int t = 5;

int main()
{
    while
    return 0;
}
