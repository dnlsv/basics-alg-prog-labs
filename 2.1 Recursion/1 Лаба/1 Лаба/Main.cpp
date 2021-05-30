#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int max(int*, int);
int maxMas(int*, int);
void checkNumber(int&, int);
void checkKod(int&, int);

int main() {
	setlocale(LC_ALL, "rus");
	int n, i, kod, count;
	do {
		cout << "������� ���-�� ���������" << endl;
		count = 1;
		checkNumber(n, count);
		int* arr = new int[n];
		cout << "������� ��������" << endl;
		count = 2;
		for (i = 0; i < n; i++)
			checkNumber(arr[i], count);
		cout << endl << "������������ ������� (����������� �������): " << max(arr, n) << endl;
		cout << "������������ ������� (������� �������): " << maxMas(arr, n) << endl;
		checkKod(kod, count);
	} while (kod != 0);
}

int max(int* arr, int n) {
	if (n == 1)
		return *arr;
	return max(max(arr, n / 2), max(arr + n / 2, n - n / 2));
}

int maxMas(int *arr, int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

void checkNumber(int &number, int count)
{
	while (true) {
		cin >> number;
		if ((count == 1) && (number > 0) && (cin.get() == '\n'))
			break;
		if ((count == 2) && (cin.get() == '\n'))
			break;
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "������������ ����" << endl;
		}
	}
}

void checkKod(int &kod, int count)
{
	cout << endl << "��� ����������� ������ ��������� ������� 1" << endl;
	cout << "��� ������ �� ��������� ������� 0" << endl;
	bool flag = true;
	while (flag) {
		checkNumber(kod, count);
		if (kod == 1 || kod == 0)
			flag = false;
		else {
			flag = true;
			cout << "������������ ����" << endl;
		}
	}
}