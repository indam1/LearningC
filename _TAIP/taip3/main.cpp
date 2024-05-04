#include <iostream>

using namespace std;

int main()
{
    int a[8] = {17, 48, 85, 30, 31, 6, 47, 18}; // массив
    int x;
    for(int i = 1; i < 8; i++)
    {
        int x = a[i];
        int j = i;
        while(j > 0 && a[j-1] > x)
        {
            a[j] = a[j-1];
            j = j-1;
        }
        a[j] = x;
        for(int k = 0; k < 8; k++)
            cout << a[k] << " ";
        cout << endl;
    }
    for(int i = 0; i < 8; i++)
        cout << a[i] << ' ';
    cout << endl;
}
