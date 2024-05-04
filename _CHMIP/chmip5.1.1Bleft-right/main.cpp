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
    cout << endl << "Left Piecewise Constant Interpolation:" << endl;
    for (int i = 0; i < N - 1; i++)
        cout << "f = " << y[i] << endl;
    cout << endl << "Left Piecewise Constant Interpolation:" << endl;
    for (int i = 1; i < N; i++)
        cout << "f = " << y[i] << endl;
}
