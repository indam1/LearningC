#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int main() //Виселица
{
    string text; //вписываем слово, которое угадываем
    cin >> text;

    int num = text.length();

    string word(num, '_'); //угадываемое слово
    string_view str(word);

    int tries = 5;
    bool flag = false;  //условные переменные для алгоритма
    bool win = false;

    cout << endl << "welcome to the game" << endl;
    while(tries > 0 && !win)
    {
        flag = false;
        win = true;
        char check;
        cout << endl << "enter character: "; //ввод символа
        cin >> check;

        for(int i = 0; i < num; i++)
        {
            if(check == text[i]) //проверка на угадываемую букву
            {
                word[i] = check;
                flag = true;
            }
        }
        if(flag == true) //варианты после ввода буквы
        {
            cout << "right" << endl;
        }
        else
        {
            tries--;
            cout << "wrong. you have " << tries << " attempts" << endl;
        }
        cout << str << endl << endl;

        for(int i = 0; i < num; i++) //проверка на победу
        {
            if(str[i] == '_')
                win = false;
        }
    }
    if(tries == 0) //проверка на количество попыток (победа/поражение)
        cout << "you lost" << endl;
    else
        cout << "you won" << endl;
}
