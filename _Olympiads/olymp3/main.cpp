#include <iostream>

using namespace std;

int main()
{
    int w[3];
    int c[3];
    int r[3];
    int d[3];
    cin >> w[0] >> w[1] >> w[2];
    cin >> c[0] >> c[1] >> c[2];
    cin >> r[0] >> r[1] >> r[2];
    for(int i = 0; i < 3; i++)
        d[i] = c[i] * r[i] - w[i];
    if(d[0] <= 0 && d[1] <= 0 && d[2] <= 0)
        cout << "0" << endl;
    else if(d[0] == d[1] && d[1] == d[2])
        cout << "1 2 3" << endl;
    else if(d[0] > d[1] && d[0] > d[2])
        cout << "1" << endl;
    else if(d[1] > d[0] && d[1] > d[2])
        cout << "2" << endl;
    else if(d[2] > d[0] && d[2] > d[1])
        cout << "3" << endl;
}
