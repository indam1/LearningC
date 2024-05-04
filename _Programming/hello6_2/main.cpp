#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

// Напишите метод, тасующий карточную колоду. Колода должна быть идеально перемешана.
// Перестановки карт должны быть равновероятными. Вы можете использовать идеальный генератор случайных чисел.

using namespace std;

int main()
{
    srand(time(0));

    vector<int> cards;

    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 9; j++)
            cards.push_back(i * 10 + j);

    for(int i = 0; i < 36; i++)
        cout << cards[i] << " ";
    cout << endl;

    for (int i = 0; i < cards.size(); i++)
    {
        int index = rand() % 36;
        swap(cards[i], cards[index]);
    }

    for(int i = 0; i < 36; i++)
        cout << cards[i] << " ";
}
