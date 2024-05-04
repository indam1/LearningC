#include <iostream>

using namespace std;

int main()
{
    double point, left, right, line;
    cout << "enter point: ";
    cin >> point;
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
    int ind;
    for(int i = 1; i < N; i++)
    {
        if(x[i - 1] <= point && point < x[i])
            left = y[i - 1];
        if(x[i - 1] < point && point <= x[i])
        {
            right = y[i];
            ind = i;
        }
    }
    line = ((y[ind] - y[ind - 1])/(x[ind] - x[ind - 1])) * (point - x[ind - 1]) + y[ind - 1];
    cout << endl << "left: " << left << endl << "right: " << right << endl << "linear: " << line;
}
