#include <iostream>

using namespace std;
int main()
{
setlocale(LC_ALL, "Russian");
const int n = 8;
int ch[n], r[n], c = 0, p = 0;
int a[n] = {17, 48, 85, 30, 31, 6, 47, 18}; // массив
cout << "Исходный массив: ";
for (int i = 0; i < n; i++)
{
    cout << a[i] << ' ';
    ch[i] = 0;
}
cout << endl; //Вывод массива
for (int i = 0; i < n; i++)
{
    for (int g = 0; g < i; g++)
{
c++;
if (a[i] > a[g])//сравнение
{
ch[i]++;//если предыдущий больше следующего
}
else ch[g]++;
}
cout << "Проход " << p << ": ";
for (int i = 0; i < n; i++)
{
cout << ch[i] << " ";
}
cout << endl;
p++;
}
for (int i = 0; i < n; i++)//сортировка по счетчику
{
r[ch[i]] = a[i];
}
cout << "Отсортированный массив:";
for (int i = 0; i < n; i++)
{
cout << r[i] << " ";
}
cout << endl << "Количество сравнений:" << c << endl;
cout << "Количество просмотров:" << p << endl;
system("pause");
}
