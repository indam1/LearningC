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
    double x1;
    double x2;
    const double k = 0.618;
    const double eps = 0.000005;
    cout << "Enter the borders: ";
    cin >> a >> b;
    for (int i = 0; abs(b - a) >= eps; i++) {
        x1 = b - (b - a) * k;
        x2 = a + (b - a) * k;
        if (func(x1) >= func(x2))
            a = x1;
        else
            b = x2;
        cout << "Iteration #" << i + 1 << ": " << func(x1) << " " << func(x2) << endl;
    }
    cout << "Ymin = " << func((a + b)/2) << endl;
    return 0;
}
