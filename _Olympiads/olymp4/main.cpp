#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    char a[N*M];

    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < M; j++)
            a[i * M + j] = s[j];
    }

    int K;
    cin >> K;
    char b[K*M];

    int counter = 0;
    for(int i = 0; i < K; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++)
        {
            b[counter] = s[j];
            counter++;
        }
    }

    for(int i = 0; i < counter; i++) // char b[K*M]; K * M = 10
    {
        for(int j = 0; j < N * M; j++) // char a[N*M]; N * M = 15
        {
            if(a[j] == b[i])
            {
                a[j] = '0';
                b[i] = '1';
            }
        }
    }

    for(int i = 0; i < N * M; i++)
        cout << a[i] << " ";


    int cou = 0;
    char c[N * M - counter];
    for(int i = 0; i < N * M; i++)
    {
        if(a[i] != '0')
        {
            c[cou] = a[i];
            cou++;
        }
    }

    cout << endl << cou << endl;

    for(int i = 0; i < cou; i++)
    {
        for(int j = 0; j < cou - i - 1; j++)
        {
            if(int(c[j]) > int(c[j+1]))
                swap(c[j], c[j+1]);
        }
    }


    for(int i = 0; i < cou; i++)
        cout << c[i];
}
