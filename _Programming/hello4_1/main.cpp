#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int main() //��������
{
    string text; //��������� �����, ������� ���������
    cin >> text;

    int num = text.length();

    string word(num, '_'); //����������� �����
    string_view str(word);

    int tries = 5;
    bool flag = false;  //�������� ���������� ��� ���������
    bool win = false;

    cout << endl << "welcome to the game" << endl;
    while(tries > 0 && !win)
    {
        flag = false;
        win = true;
        char check;
        cout << endl << "enter character: "; //���� �������
        cin >> check;

        for(int i = 0; i < num; i++)
        {
            if(check == text[i]) //�������� �� ����������� �����
            {
                word[i] = check;
                flag = true;
            }
        }
        if(flag == true) //�������� ����� ����� �����
        {
            cout << "right" << endl;
        }
        else
        {
            tries--;
            cout << "wrong. you have " << tries << " attempts" << endl;
        }
        cout << str << endl << endl;

        for(int i = 0; i < num; i++) //�������� �� ������
        {
            if(str[i] == '_')
                win = false;
        }
    }
    if(tries == 0) //�������� �� ���������� ������� (������/���������)
        cout << "you lost" << endl;
    else
        cout << "you won" << endl;
}
