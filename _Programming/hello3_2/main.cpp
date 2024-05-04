#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

int main() //часы, работающие до нажатия любой клавиши
{
    time_t lt;
    while(true) {
        if(kbhit()) {
            if(getch())
                break;
        }
        system("cls");
        lt = time(NULL);
        cout << ctime(&lt);
        Sleep(100);
    }
    return 0;
}
