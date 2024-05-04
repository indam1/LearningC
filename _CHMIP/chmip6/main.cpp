#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

double inFunction(double x)
{
    return 4 * pow(x, 3) - 1 + x;
}

double rectangleMid(double a, double b, int n)
{
    double result = 0;
    double h = (b - a) / n;
    for(int i = 0; i < n; i++)
        result += inFunction(a + h * (i + 0.5));

    result *= h;
    return result;
}

double rectangleLeft(double a, double b, int n)
{
    double result = 0;
    double h = (b - a)/ n;
    for(int i = 0; i < n; i++)
        result += inFunction(a + h * i);

    result *= h;
    return result;
}

double rectangleRight(double a, double b, int n)
{
    double result = 0;
    double h = (b - a)/ n;
    for(int i = 1; i < n + 1; i++)
        result += inFunction(a + h * i);

    result *= h;
    return result;
}

double trapeze(double a, double b, int n)
{
    double result = (inFunction(a) + inFunction(b))/2;
    double h = (b - a) / n;
    for(int i = 1; i < n; i++)
        result += inFunction(a + h * i);

    result *= h;
    return result;
}

double parabola(double a, double b, int n)
{
    if(n % 2 != 0)
    {
        cout << "You had to enter an even number!" << endl;
        return -1;
    }
    double h = (b - a) / n;
    double sumEven = 0;
    double sumOdd = 0;
    for(int i = 1; i < n; i++)
    {
        if(i % 2 == 0)
            sumEven += inFunction(a + h * i);
        else
            sumOdd += inFunction(a + h * i);
    }

    double result = (4 * sumOdd + 2 * sumEven + inFunction(a) + inFunction(b)) * h / 3;
    return result;
}

int main()
{
    cout << "LeftRectanglesMethod: approximation(400999 iterations) = " << rectangleLeft(0, 10, 400999);
    cout << "; exact value(401000 iterations) = " << rectangleLeft(0, 10, 401000) << endl;
    cout << "RightRectanglesMethod: approximation(401000 iterations) = " << rectangleRight(0, 10, 401000);
    cout << "; exact value(401001 iterations) = " << rectangleRight(0, 10, 401001) << endl;
    cout << "MidRectanglesMethod: approximation(316 iterations) = " << rectangleMid(0, 10, 316);
    cout << "; exact value(371 iterations) = " << rectangleMid(0, 10, 317) << endl;
    cout << "TrapezoidMethod: approximation(447 iterations) = " << trapeze(0, 10, 447);
    cout << "; exact value(448 iterations) =  " << trapeze(0, 10, 448) << endl;
    cout << "SimpsonMethod: exact value(2 iterations) = " << parabola(0, 10, 2) << endl;
}
