#include <iostream>

using namespace std;

int main() //перевод из градусов/минут/секунд в радианы
{
    double an, mi, se;
    cout << "Enter angle: ";
    cin >> an;
    cout << "Enter minutes: ";
    cin >> mi;
    cout << "Enter sec: ";
    cin >> se;
    double rad = (an + mi / 60.0 + se / (60.0 * 60.0)) * 3.14 / 180.0;
    cout << rad;
}
