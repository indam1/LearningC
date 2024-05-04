#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
    array<int, 14> a = {14, 2, 19, -86, 238, 89, 75, 63, 98005, 2, 61, 3, -94, 55}; // массив
    sort(a.begin(), a.end());
    for(int i = 0; i < 14; i++)
        cout << a[i] << " ";
    cout << endl;
    int k = 19;
    int index;
    bool b;
    int l = 0;
    int r = 13;
    while(true)
    {
        int midd = (l + r) / 2;
        if(k < a[midd])
            r = midd - 1;
        else if(k > a[midd])
            l = midd + 1;
        else
        {
            index = midd;
            b = true;
            break;
        }

        if(l > r)
            break;
    }
    if(b)
        cout << index;
    return 0;
}
