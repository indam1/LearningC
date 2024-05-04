#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

char a[10][25];

void out()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 25; j++)
            cout << a[i][j];
        cout << endl;
    }
}

int main()
{
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 25; j++)
            a[i][j] = '*';

    char buff = '0';
    int cX = 0;
    int cY = 0;

    while(buff != 27)
    {
        buff = getch();
        a[cY][cX] = '*';
        if(buff == 'w')
            cY--;
        else if(buff == 's')
            cY++;
        else if(buff == 'a')
            cX--;
        else if(buff == 'd')
            cX++;
        a[cY][cX] = '+';

        system("cls");
        out();
        Sleep(10);
    }

    system("pause");

    return 0;
}
