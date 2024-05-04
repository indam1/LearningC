#include <iostream>
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 8, d = n, j, k = 0, c = 0;

	vector <int> mas = { 17, 48, 85, 30, 31, 6, 47, 18 };

	cout << "�������� ������" << endl;

	for (int i = 0; i < n; i++)

		cout << mas[i] << ' ';

	cout << endl;

	while (d >= 1) {//�������� ����

		cout << "� ����� " << d << ": ";

		for (int a = 0; a < n; a++)

			cout << mas[a] << ' ';

		cout << endl;

		for (int i = 0; i < n - d; i++) {

			j = i;

			k += 1;//������� ���������

			while ((j >= 0) && (mas[j] > mas[j + d])) {//��������� ���� ��-���

				c += 1;//������� �����

				swap(mas[j], mas[j + d]);//����� ������� ����� ����������

				j--;//������������� ���������� ��-���

			}

		}

		d = d / 2;//��������� ����

	}

	cout << "������������� ������" << endl;

	for (int i = 0; i < n; i++)

		cout << mas[i] << ' ';

	cout << endl;

	cout << "���������� ��������� " << k << endl;

	cout << "���������� ����� " << c << endl;

	return 0;

}
