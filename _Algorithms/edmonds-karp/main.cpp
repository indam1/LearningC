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

int main()
{
    vector<Edge> edges = {
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

    for(int i = 0; i < 22; i++)
        if(i % 2 == 0)
            edges[i].rev = &edges[i+1];
        else
            edges[i].rev = &edges[i-1];

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
    int flow = 0;
    while(true)
    {
        queue<int> q;
        q.push(s);

        Edge pr[7];
        Edge *pred[7];
        for(int i = 0; i < 7; i++)
        {
            pr[i].s = -10000;
            pred[i] = &pr[i];
        }

        while(!q.empty() && pred[t]->s == -10000)
        {
            int cur = q.front();
            q.pop();
            for(int i = 0; i < graph[cur].size(); i++)
            {
                Edge *e = graph[cur][i];
                if(pred[e->t]->s == -10000 && e->t != s && e->cap > e->flow)
                {
                    cout << e->s << " " << e->t << endl;
                    pred[e->t] = e;
                    q.push(e->t);
                }
            }
        }
        cout << endl;

        if(pred[t]->s == -10000)
            break;
        else
        {
            int df = 10000000;
            for(Edge *e = pred[t]; e->s != -10000; e = pred[e->s])
            {
                cout << e->s << " " << e->t << " " << e->cap - e->flow << endl;
                df = min(df, e->cap - e->flow);
            }

            for(Edge *e = pred[t]; e->s != -10000; e = pred[e->s])
            {
                cout << e->s << " " << e->t << " " << endl;
                e->flow += df;
                (e->rev)->flow -= df;
            }
            cout << df << endl << endl;
            flow += df;
        }
    }
    cout << flow << endl;
    for(int i = 0; i < 22; i++)
        cout << edges[i].s << " " << edges[i].t << " " << edges[i].flow << endl;
    return 0;
}
