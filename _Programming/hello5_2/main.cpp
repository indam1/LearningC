#include <iostream>
#include <vector>

using namespace std;

// Даны отрезки с координатами левого и правого конца, определить сколько содержится в отрезке других отрезков

int main()
{
    int m = 4;
    int counter[m] = {};
    vector<vector<int>> coord(2, vector<int>(m));
    for(int j = 0; j < m; j++)
        for(int i = 0; i < 2; i++)
            cin >> coord[i][j];

    /*for(int i = 0; i < 2; i++)
        for(int j = 0; j < m; j++)
            cout << coord[i][j] << endl;*/

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == j)
                continue;
            //cout << coord[0][i] << " " << coord[0][j] << " " << coord[1][i] << " " << coord[1][j] << " " << i << " " << j << endl;
            if(coord[0][i] < coord[0][j] && coord[1][i] > coord[1][j])
                counter[i]++;
        }
    }

    for(int i = 0; i < m; i++)
        cout << counter[i] << endl;
}
