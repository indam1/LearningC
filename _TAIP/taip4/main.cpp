#include <iostream>
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 8, d = n, j, k = 0, c = 0;

	vector <int> mas = { 17, 48, 85, 30, 31, 6, 47, 18 };

	cout << "Исходный массив" << endl;

	for (int i = 0; i < n; i++)

		cout << mas[i] << ' ';

	cout << endl;

	while (d >= 1) {//проверка шага

		cout << "С шагом " << d << ": ";

		for (int a = 0; a < n; a++)

			cout << mas[a] << ' ';

		cout << endl;

		for (int i = 0; i < n - d; i++) {

			j = i;

			k += 1;//счатчик сравнений

			while ((j >= 0) && (mas[j] > mas[j + d])) {//сравнение двух эл-тов

				c += 1;//счатчик замен

				swap(mas[j], mas[j + d]);//обмен местами между элементами

				j--;//упорядовачине придыдущих эл-тов

			}

		}

		d = d / 2;//изменение шага

	}

	cout << "Упорядоченный массив" << endl;

	for (int i = 0; i < n; i++)

		cout << mas[i] << ' ';

	cout << endl;

	cout << "Количество сравнений " << k << endl;

	cout << "Количество замен " << c << endl;

	return 0;

}
