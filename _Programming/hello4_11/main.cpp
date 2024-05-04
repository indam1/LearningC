#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() //Виселица
{
    char buff;
    int num;
    vector<char> text;
    cout << "enter word: ";
    while(cin >> buff)
        text.push_back(buff);
//    int num = strlen(text);
    char word[num];
    for(int i = 0; i < num; i++)
        word[i] = '_';

    int tries = 5;
    bool flag = false;
    bool win = false;

    cout << endl << "welcome to the game" << endl;
    while(tries > 0 && !win)
    {
        flag = false;
        win = true;
        char check;
        cout << endl << "enter character: ";
        cin >> check;

        for(int i = 0; i < num; i++)
        {
            if(check == text[i])
            {
                word[i] = check;
                flag = true;
            }
        }
        if(flag == true)
        {
            cout << "right" << endl;
        }
        else
        {
            tries--;
            cout << "wrong. you have " << tries << " attempts" << endl;
        }
        cout << word << endl << endl;

        for(int i = 0; i < num; i++)
        {
            if(word[i] == '_')
                win = false;
        }
    }
    if(tries == 0)
        cout << "you lost" << endl;
    else
        cout << "you won" << endl;
}
