#include <iostream>

using namespace std;

int main()
{
    int a[14] = {14, 2, 19, -86, 238, 89, 75, 63, 98005, 2, 61, 3, -94, 55}; // массив
    int k1 = 19;
    int k2 = 44;
    int index1;
    int index2;
    bool b[2];
    for(int i = 0; i < 14; i++)
    {
        if(a[i] == k1)
        {
            index1 = i;
            b[0] = true;
        }
        if(a[i] == k2)
        {
            index2 = i;
            b[1] = true;
        }
    }

    if(b[0])
        cout << index1 << endl;
    else
        cout << "there is not first key" << endl;

    if(b[1])
        cout << index2 << endl;
    else
        cout << "there is not second key" << endl;
    return 0;
}
