#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    array<int, 10> v1 = {1, -2, 3, -4, 5, -6, -7, 8, 9, 10}; //Массив

    for(int i = 0; i < 10; i+=2)    //Выводит элементы массива с четным индексом
        cout << v1[i] << " ";
    cout << endl << endl;

    for(int i = 0; i < 9; i++) //Вывести первую пару соседних элементов с одинаковым знаком
    {
        if(v1[i] * v1[i+1] > 0)
        {
            cout << v1[i] << " " << v1[i+1] << endl << endl;
            break;
        }
    }

    sort(v1.begin(), v1.begin() + 5); //Отсортировать с 1 по 5 элемент по возрастанию, с 6 по 10 по убыванию
    sort(v1.begin() + 5, v1.end(), greater<int>());

    for(auto &elem : v1)
        cout << elem << " ";
    cout << endl << endl;

    double summ = 0; //Вывести среднее арифметическое отрицательных элементов
    int counter = 0;
    for(int i = 0; i < 10; i++)
    {
        if(v1[i] < 0)
        {
            summ += v1[i];
            counter++;
        }
    }

    cout << summ/counter << endl;

    vector<vector<int> > arr(4, vector<int> (4)); //Отсортировать в двумерном массиве 4х4 главную диагональ по возрастанию, побочную по убыванию

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            cin >> arr[i][j];

    vector<int> mainBuff(4);
    vector<int> secBuff(4);
    for(int i = 0; i < 4; i++)
    {
        mainBuff[i] = arr[i][i];
        secBuff[i] = arr[i][secBuff.size() - i - 1];
    }

    sort(mainBuff.begin(), mainBuff.end());
    sort(secBuff.rbegin(), secBuff.rend());

    for(int i = 0; i < 4; i++)
    {
        arr[i][i] = mainBuff[i];
        arr[i][secBuff.size() - i - 1] = secBuff[i];
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }


    return 0;
}
