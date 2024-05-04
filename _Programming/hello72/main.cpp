#include <iostream>
#include <Square.h>

using namespace std;

int main()
{
    Square abc;
    cout << abc.getSide() << endl << "Enter 2 radii: ";
    double r1, r2;
    cin >> r1 >> r2;
    abc.checkRadii(r1, r2);

}
