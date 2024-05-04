#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "func = 1/cos(4x); range = [1; 4], step = 0.4" << endl;
    const int N = 11;
    double x[N] {1.0, 1.3, 1.6, 1.9, 2.2, 2.5, 2.8, 3.1, 3.4, 3.7, 4.0};
    double y[N];
    cout << "x = ";
    for (int i = 0; i < N; i++)
        cout << x[i] << " ";
    cout << endl << "y = ";
    for (int i = 0; i < N; i++)
    {
        y[i] = 1 / cos(4 * x[i]);
        cout << y[i] << " ";
    }
    cout << endl << "System of equations for given points:" << endl;
    for (int i = 1; i < N; i++)
    {
        double k = (y[i] - y[i - 1]) / (x[i] - x[i - 1]);
        double l = y[i] - (k * x[i]);
        cout << x[i - 1] << " - " << x[i] << ": ";
        if (k >= 0)
            cout << "y(x) = " << l << " + " << k << "x" << endl;
        else
            cout << "y(x) = " << l << " - " << -k << "x" << endl;
    }
}
