#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Высчитать минимальное расстояние между любыми двумя словами в файле

int main()
{
    vector<string> words;
    string first;
    string second;
    cout << "Enter two words: ";
    cin >> first >> second;
    ifstream ifs("kek.txt");
    while(!ifs.eof())
    {
        string buff;
        ifs >> buff;
        words.push_back(buff);
    }
    int firstPos = 0;
    int secondPos = 0;
    for(int i = 0; i < words.size(); i++)
    {
        if(words[i] == first)
            firstPos = i;
        if(words[i] == second)
            secondPos = i;
    }
    cout << firstPos << " " << secondPos << endl;
    cout << abs(firstPos - secondPos) - 1;
}
