#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    return 0.5 * pow(x, 3) - 1;
}

int main()
{
    double a;
    double b;
    double x;
    const double eps = 0.000001;
    cout << "Enter the borders: ";
    cin >> a >> b;
    for(int i = 0; (b - a)/2 >= eps; i++) {
        x = (a + b)/2;
        if (func(x - eps) < func(x + eps))
            b = x - eps;
        else
            a = x - eps;
        cout << "Iteration #" << i + 1 << ": " << func(x) << endl;
    }
    cout << "Ymin = " << func((a + b)/2) << endl;
    return 0;
}
