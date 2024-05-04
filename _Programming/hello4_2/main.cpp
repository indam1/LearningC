#include <iostream>

using namespace std;

int summ(int a[], int v)
{
    int res = 0;
    for(int i = 0; i < v; i++)
        res += a[i];
    return res;
}

void textout(int *a, int v)
{
    for(int i = 0; i < v; i++)
        cout << a[i];
}

int main() //Массив как аргумент
{
    int x[5] = {1, 2, 3, 4, 5};
    cout << &x << " " << &x[0] << endl;
    //for(int i = 0; i < 5; i++)
        cout << &x[0] + 1 << endl<< x<<endl;;
    cout << &x + 1 << " " << &x[4] << endl;
    int a[3] = {1, 2, 3};
    textout(a, 3);
    cout << endl << summ(a, 3);
}
