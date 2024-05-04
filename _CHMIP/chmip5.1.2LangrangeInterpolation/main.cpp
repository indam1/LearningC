#include <iostream>

using namespace std;

int main()
{
    double point;
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
    double result = 0.0;
    for(int i = 0; i < N; i++)
    {
        double l = 1.0;
        for(int j = 0; j < N; j++)
        {
            if(j != i)
                l *= (point - x[j])/(x[i] - x[j]);
        }
        result += l * y[i];
    }
    cout << endl << "result: " << result;
}
