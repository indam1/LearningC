#include <iostream>
#include <fstream>
using namespace std;

int main() //есть 2 файла. один заполнен числами от 1 до 1000, второй заполнен счастливыми числами от 1 до 1000. записать все несовпадающие числа в третий файл
{
    int a[1000], b[357], c[634];
    int counter = 0;
    ofstream F1, F2, F3;
    F1.open("f1.txt");
    F2.open("f2.txt");
    F3.open("f3.txt");

    for (int i = 0; i < 1000; i++)
    {
        F1 << i + 1 << " ";
        a[i] = i + 1;
        if ((i + 1) % 4 == 0 || (i + 1) % 7 == 0)
        {
            b[counter] = i + 1;
            F2 << i + 1 << " ";
            counter++;
        }
    }

    counter = 0;

    for(int i = 0; i < 1000; i++)
    {
        bool check = true;
        for(int j = 0; j < 347; j++)
        {
            if(a[i] == b[j])
            {
                check = false;
                break;
            }
        }
        if(check)
        {
            c[counter] = a[i];
            counter++;
        }
    }

    for(auto &element : c)
        F3 << element << " ";

    F1.close();
    F2.close();
    F3.close();
}
