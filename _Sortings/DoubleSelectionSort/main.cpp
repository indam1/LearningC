#include <iostream>

using namespace std;

int main()
{
    const int n = 10;
    int arr[10] {2, 3, 5, 4, 1, 10, 8, 7, 6, 9};
    cout << "Source array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    int minI = 0, maxI = 0, its = 0;
    for(int j = 0; j < n/2; j++)
    {
        its++;
        int minVal = INT_MAX, maxVal = 0, tmp = 0;
        for(int i = j; i < n - j; i++)
        {
            its++;
            if(minVal > arr[i])
            {
                minVal = arr[i];
                minI = i;
            }
            if(maxVal < arr[i])
            {
                maxVal = arr[i];
                maxI = i;
            }
        }
        tmp = arr[j];
        if(j == maxI)
            maxI = minI;
        arr[j] = minVal;
        arr[minI] = tmp;
        tmp = arr[n - j - 1];
        arr[n - j - 1] = maxVal;
        arr[maxI] = tmp;
    }
    cout << endl << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << "Iterations: " << its << endl;
}
