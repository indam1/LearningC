#include <iostream>

using namespace std;

int main() //���������
{
    double **ptr = 0;
    double *a = new double(2);
    ptr = &a;
    cout << **ptr << endl;
    delete a;

}
