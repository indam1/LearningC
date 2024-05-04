#include <iostream>

using namespace std;

const int RUN = 32;
int its = 0;

void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++, its++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            its++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void mergeSort(int arr[], int l, int m, int r)
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

void timSort(int arr[], int n)
{
    for (int i = 0; i < n; i += RUN, its++)
        insertionSort(arr, i, min((i + 31), (n - 1)));

    for (int size = RUN; size < n; size *= 2, its++)
    {
        for (int left = 0; left < n; left += 2 * size, its++)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n-1));

            mergeSort(arr, left, mid, right);
        }
    }
}

int main()
{
    const int n = 10;
    int arr[10] {2, 3, 5, 4, 1, 10, 8, 7, 6, 9};
    cout << "Source array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    timSort(arr, n);

    cout << endl << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << "Iterations: " << its << endl;
}
