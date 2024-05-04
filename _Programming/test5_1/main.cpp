#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

enum Errors
{
    LESS_THAN_1000
};

// Ќайти самое встречающеес€ слово, воспользоватьс€ enum дл€ контрол€ точек выхода из программы с определенными ошибками.

using namespace std;
int main()
{
    ifstream ifs("kek.txt");

    vector<string> res;
    vector<int> counter;
    int errCount = 0;

    for(int i = 0; i < 1000; i++)
    {
        string buff;
        ifs >> buff;
        auto it = find(res.begin(), res.end(), buff);
        if(it != res.end())
        {
            counter[it - res.begin()]++;
            errCount++;
        }
        else
        {
            res.push_back(buff);
            counter.push_back(1);
        }
    }
    ifs.close();

    for(int i = 0; i < (int)res.size(); i++)
        cout << res[i] << " " << counter[i] << endl;

    Errors err;
    if(errCount < 1000)
    {
        err = LESS_THAN_1000;
        cout << endl << "We have words less than 1000" << endl;
    }
}
