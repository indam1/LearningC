#include <iostream>

using namespace std;

int main()
{
    const int n = 10;
    int arr[10] {2, 3, 5, 4, 1, 10, 8, 7, 6, 9};
    cout << "Source array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    int currI = 0, its = 0;
    while(currI < n)
    {
        its++;
        if(currI == 0 || arr[currI - 1] < arr[currI])
            currI++;
        else
        {
            swap(arr[currI - 1], arr[currI]);
            currI--;
        }
    }
    cout << endl << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << "Iterations: " << its << endl;
}
