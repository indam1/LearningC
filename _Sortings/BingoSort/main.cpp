#include <iostream>
using namespace std;

int main()
{
    const int n = 10;
    int arr[10] {2, 3, 5, 4, 1, 10, 8, 7, 6, 9};
    cout << "Source array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    int maxI = n - 1, maxVal = 0, its = 0, nextVal = arr[maxI];
    for(int i = maxI - 1; i >= 0; i--, its++)
    {
        if(arr[i] > nextVal)
            nextVal = arr[i];
    }
    while(maxI > 0 && arr[maxI] == nextVal)
    {
        its++;
        maxI--;
    }
    while(maxI > 0)
    {
        its++;
        maxVal = nextVal;
        nextVal = arr[maxI];
        for(int i = maxI - 1; i >= 0; i--, its++)
        {
            if(arr[i] == maxVal)
            {
                swap(arr[i], arr[maxI]);
                maxI--;
            }
            else if(arr[i] > nextVal)
                nextVal = arr[i];
        }
        while(maxI > 0 && arr[maxI] == nextVal)
        {
            its++;
            maxI--;
        }
    }
    cout << endl << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << "Iterations: " << its << endl;
}
