#include <iostream>

using namespace std;

int its = 0;

void mergeSort(int *arr, int l, int m, int r)
{
    int it1 = 0;
    int it2 = 0;
    int result[r - l];

    while(l + it1 < m && m + it2 < r)
    {
        its++;
        if(arr[l + it1] < arr[m + it2])
        {
            result[it1 + it2] = arr[l + it1];
            it1++;
        }
        else
        {
            result[it1 + it2] = arr[m + it2];
            it2++;
        }
    }
    while(l + it1 < m)
    {
        its++;
        result[it1 + it2] = arr[l + it1];
        it1++;
    }
    while(m + it2 < r)
    {
        its++;
        result[it1 + it2] = arr[m + it2];
        it2++;
    }
    for(int i = 0; i < it1 + it2; i++, its++)
        arr[l + i] = result[i];
}

int main()
{
    const int n = 10;
    int arr[10] {2, 3, 5, 4, 1, 10, 8, 7, 6, 9};
    cout << "Source array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    for(int i = 1; i < n; i *= 2, its++)
    {
        for(int j = 0; j < n - i; j += 2 * i, its++)
            mergeSort(arr, j, j + i, min(j + 2 * i, n));
    }
    cout << endl << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << "Iterations: " << its << endl;
}
