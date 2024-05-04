#include <iostream>
#include <Matrix.h>

using namespace std;

int main()
{
    Matrix m1;

    m1.printFirst();
    m1.printSecond();
    m1.printThird();

    Matrix m2 = m1;
    m2.printFirst();
    m2.printSecond();
    m2.printThird();

    Matrix m3(m1);
    m3.printFirst();
    m3.printSecond();
    m3.printThird();
}
