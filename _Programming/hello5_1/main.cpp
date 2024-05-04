#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    cin >> num;

    vector <int> counter;
    vector <string> words;
    vector <string> res;
    ifstream ifs("kek.txt");

    for(int i = 0; i < num; i++)
    {
        string buff;
        ifs >> buff;
        words.push_back(buff);
    }
    ifs.close();

    res.push_back(words[0]);
    counter.push_back(1);

    for(int i = 1; i < num; i++)
    {
        bool flag = true;
        for(int j = 0; j < (int)res.size(); j++)
        {
            if(words[i] == res[j])
            {
                counter[j]++;
                flag = false;
                break;
            }
        }
        if(flag)
        {
            res.push_back(words[i]);
            counter.push_back(1);
        }
    }

    for(int i = 0; i < (int)res.size(); i++)
        cout << res[i] << " " << counter[i] << endl;
}
