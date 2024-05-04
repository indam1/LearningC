#include <iostream>

using namespace std;

int main()
{
    cout << "range = [12; 24]" << endl;
    const int N = 7;
    double x[N] {12, 17, 20, 22, 23, 23.7, 24};
    double y[N] {2, 3, 4, 5, 6, 7, 8};
    cout << "x = ";
    for (int i = 0; i < N; i++)
        cout << x[i] << " ";
    cout << endl << "y = ";
    for (int i = 0; i < N; i++)
        cout << y[i] << " ";
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
