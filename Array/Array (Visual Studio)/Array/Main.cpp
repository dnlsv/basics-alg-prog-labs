#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void checkNumber(int&);

void main()
{
	setlocale(LC_ALL, ".UTF8");
	int a[10], n, i;
	int x, y;
	int i5 = 0;
	int sum;
	int kod = 0;

	do {

		cout << "Введите количество элемментов массива n (n<=10) " << endl;
		checkNumber(n);

		if (n < 1 || n>10)
			cout << "Некорректный ввод" << endl;
		else {
			cout << "1 - Random. 0 - Keyboard" << endl;
			int v;
			cin >> v;
			if (v == 0) {
				cout << "Введите массив с клавиатуры" << endl;
				for (i = 0; i < n; i++) {
					cin >> a[i];
					//cout << a[i] << " ";
				}
				cout << "Massiv A" << endl;
				for (i = 0; i < n; i++) {
					cout << a[i] << " ";
				}
			}
			else {
				cout << "Укажите промежуток допустимых значений массива" << endl;
				cout << "От" << endl;
				checkNumber(x);
				cout << "До" << endl;
				checkNumber(y);
				cout << endl;

				cout << "Massiv A" << endl;
				srand(time(NULL));
				for (i = 0; i < n; i++) {
					a[i] = rand() % (y - x + 1) + x;
					cout << a[i] << " ";
				}
			}

			for (i = n - 1; i >= 0; --i) {
				if (a[i] < 0) {
					i5 = i;
					break;
				}
			}

			for (sum = 0, i = i5 + 1; i < n; ++i) {
				if (i5 == 0)
					sum = 0;
				else
					sum += a[i];
			}
			cout << endl << "Сумма элементов массива после последнего отрицательного = " << sum << endl << endl;
		}
		cout << "Для продолжения работы программы нажмите 1" << endl;
		cout << "Для выхода из программы нажмите 0" << endl;
		bool flag = true;
		while (flag) {
			checkNumber(kod);
			if (kod == 1 || kod == 0)
				flag = false;
			else {
				flag = true;
				cout << "Некорректный ввод" << endl;
			}
		}
	} while (kod != 0);
	//system("pause");
}

void checkNumber(int& number)
{
	while (true) {
		cin >> number;
		if (cin.get() == '\n')
			break;
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Некорректный ввод" << endl;
		}
	}
}