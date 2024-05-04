#include <iostream>

using namespace std;

int main()
{
    int ingr[3];
    int comp[6];

    for(int i = 0; i < 3; i++)
        cin >> ingr[i];
    for(int i = 0; i < 6; i++)
        cin >> comp[i];

    int s1 = comp[0] / ingr[0];
    int s2 = comp[1] / ingr[1];
    int s3 = comp[2] / ingr[2];
    int res = max(max(s1, s2), s3);
    int maximum = res;
    int minimum = res;

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            for(int k = 0; k < 6; k++)
            {
                if(k != j && j != i && i != k)
                {
                    s1 = comp[k] / ingr[0];
                    s2 = comp[j] / ingr[1];
                    s3 = comp[i] / ingr[2];
                    res = min(min(s1, s2), s3);
                    if(res > maximum)
                        maximum = res;
                    if(res < minimum)
                        minimum = res;
                }
            }
        }
    }
    cout minimum << " " << maximum << endl;
}
