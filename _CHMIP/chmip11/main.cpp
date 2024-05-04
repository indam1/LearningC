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
    double min = 0;
    const double eps = 0.01;
    cout << "Enter the borders: ";
    cin >> a >> b;
    min = func(a);
    for(int i = 0; a <= b; i++, a+=eps) {
        if (min > func(a + eps))
            min = func(a + eps);
        cout << "Iteration #" << i + 1 << ": " << min << endl;
    }
    return 0;
}
