#include <iostream>

using namespace std;

// –азработка алгоритма, обнаруживающего в массиве все пары целых чисел, сумма которых равна заданному значению

int main()
{
    const int n = 10;
    int arr[n] = {1, 2, 3, 4, 5, 1, 5, 6, 3, 2};
    int currValue;
    cin >> currValue;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] + arr[j] == currValue)
                cout << "arr[" << i << "]: " << arr[i] << " arr[" << j << "]: " << arr[j] << endl;
        }
    }
    return 0;
}
