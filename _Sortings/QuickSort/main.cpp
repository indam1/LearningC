#include <iostream>
using namespace std;
int its = 0;
void quickSort(int *arr, int l, int r)
{
    its++;
    int l_bord = l, r_bord = r, piv = arr[l];
    while (l < r)
    {
        its++;
        while(arr[r] >= piv && l < r)
        {
            its++; r--;
        }
        if(l != r)
        {
            arr[l] = arr[r]; l++;
        }
        while(arr[l] <= piv && l < r)
        {
            its++; l++;
        }
        if(l != r)
        {
            arr[r] = arr[l]; r--;
        }
    }
    arr[l] = piv; piv = l; l = l_bord; r = r_bord;
    if(l < piv)
        quickSort(arr, l, piv - 1);
    if(r > piv)
        quickSort(arr, piv + 1, r);
}

int main()
{
    const int n = 10;
    int arr[10] {2, 3, 5, 4, 1, 10, 8, 7, 6, 9};
    cout << "Source array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    quickSort(arr, 0, n - 1);
    cout << endl << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl << "Iterations: " << its << endl;
}
