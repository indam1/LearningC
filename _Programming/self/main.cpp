#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int inf = 100000000; // ������������� (��� ���������)
    int N; // ���������� ���������
    int windowX, windowY; // ������ � ������ ����
    cout << "Num of monitors: ";
    cin >> N;
    cout << "Resolution of window: ";
    cin >> windowX >> windowY;

    vector <int> monX; // ������ ���������
    vector <int> monY; // ������ ���������

    for(int i = 0; i < N; i++)
    {
        int x, y;
        cout << "Enter size of " << i + 1 << " monitor: ";
        cin >> x >> y;
        monX.push_back(x);
        monY.push_back(y);
    }

    int offset; // �������� ����
    cout << "Enter window offset: ";
    cin >> offset;

    bool flag = false;
    for(int i = 0; i < monX.size(); i++) // �������� �� ��, ��� ���� ���������� � �����-������ �� ��������� �� ���������
        if(offset < monX[i])
            flag = true;

    if(!flag) // � ������, ���� ���� �� ����������
    {
        cout << "Resolution of monitors is not enough";
        return 0;
    }

    vector <int> windowShrink; // ������ ��� ������ ���� � ��������� �� ������������ ���������� ��������
    for(int i = 0; i < monX.size(); i++) // ���������� ������
    {
        if(offset > monX[i])
        {
            windowShrink.push_back(inf);
            continue;
        }
        if(windowX - (monX[i] - offset) < 0)
            windowShrink.push_back(0);
        else
            windowShrink.push_back(windowX - (monX[i] - offset));
    }

    int minimum = windowShrink[0];
    int index = 0;
    for(int i = 1; i < windowShrink.size(); i++) // ���� ����������� ������ �� ���������
        if(minimum > windowShrink[i])
        {
            minimum = windowShrink[i];
            index = i;
        }

    cout << "Window opened on the " << (index+1) << " monitor\nCompression on " << windowShrink[index] << " pixels" << endl; // ����� �������� � ������
}
