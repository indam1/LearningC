#include <iostream>
#include <vector>

// ƒана матрица размером N*N, содержаща€ положительные и отрицательные числа. Ќапишите код поиска субматрицы с максимально возможной суммой.

using namespace std;

int main()
{
    vector<int> a;
    int n;
    cin >> n;
    int arrayDim[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            arrayDim[i][j] = i * j;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << arrayDim[i][j] << " ";
        cout << endl;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                for(int l = 0; l < n; l++)
                {
                    if(i <= k && j <= l)
                    {
                        int summ = 0;
                        for(int lu = i; lu <= k; lu++)
                        {
                            for(int rd = j; rd <= l; rd++)
                                summ += arrayDim[lu][rd];
                        }
                        a.push_back(summ);
                    }
                }
            }
        }
    }

    int max = a[0];
    for(int i = 1; i < a.size(); i++)
        if(max < a[i])
            max = a[i];

    cout << endl << max << endl;
}
