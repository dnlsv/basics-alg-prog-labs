#include <iostream>
#include <string.h>
#include <cstdlib>
#include <conio.h>

using namespace std;
const int N = 100;

void main()
{
	setlocale(LC_ALL, ".UTF8");
	int kod;

	do {
		int len, i, j;
		int a, b, c;
		int non;
		int kol = 0;
		char st[N] = " ";
		cout << "Введите строку" << endl;
		cin >> st;
		len = strlen(st);
		int count = 0;
		char podst[N];

		for (i = 1; i <= len; i++) {

			if (st[i] == '.') {
				non = 1;
				a = 0;
				for (j = i - 1; j >= 0; j--) {
					if (isdigit(st[j])) {
						a = j;
					}
					else {
						if (st[a - 1] == '-') {
							a = j;
						}
						if (a == 0) {
							non = 0;
						}
						break;
					}
				}
				b = 0;
				for (j = i + 1; j <= len; j++) {
					if (isdigit(st[j])) {
						b = j;
					}
					else {
						if (b == 0) {
							non = 0;
						}
						break;
					}
				}
				c = 0;
				if (st[b + 1] == 'E' || st[b + 1] == 'e') {
					if ((st[b + 2] == '-') || (st[b + 2] == '+')) {
						for (j = b + 3; j <= len; j++) {
							if (isdigit(st[j])) {
								c = j;
							}
							else {
								if (c == 0) {
									non = 0;
								}
								break;
							}
						}
					}
					else {
						non = 0;
					}
				}
				else {
					non = 0;
				}
			}
			else {
				non = 0;
			}

			if (non == 1) {
				cout << endl;
				//cout << "Выделенная подстрока " << count << endl;
				for (i = a; i <= c; i++) {
					podst[i] = st[i];
					cout << podst[i];
					count++;
				}
				cout << endl;
			}

		}

		//Когда точки нет

		for (i = 1; i <= len; i++) {

			if (st[i] == 'E' || st[i] == 'e') {
				non = 1;
				a = 0;
				for (j = i - 1; j >= 0; j--) {
					if (isdigit(st[j])) {
						a = j;
					}
					else {
						if (st[a - 1] == '-') {
							a = j;
						}
						if (a == 0) {
							non = 0;
						}
						break;
					}
				}


				if ((st[i + 1] == '-') || (st[i + 1] == '+')) {
					b = 0;
					for (j = i + 2; j <= len; j++) {
						if (isdigit(st[j])) {
							b = j;
						}
						else {
							if (b == 0) {
								non = 0;
							}
							break;
						}
					}
				}
				else {
					non = 0;
				}
			}
			else {
				non = 0;
			}

			if (non == 1) {
				cout << endl;
				//cout << "Выделенная подстрока " << count << endl;
				for (i = a; i <= b; i++) {
					podst[i] = st[i];
					cout << podst[i];
					count++;
				}
				cout << endl;
			}

		}


		if (count == 0) {
			cout << "Таких чисел нет" << endl;
		}


		bool flag = true;
		while (flag) {
			while (true) {
				cout << endl;
				cout << "Для продолжения работы программы нажмите 1" << endl;
				cout << "Для выхода из программы нажмите 0" << endl;
				cin >> kod;
				if (cin.get() == '\n') {
					break;
				}
				else {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Error!" << endl;
				}

			}
			if (kod == 1 || kod == 0) {
				flag = false;
			}
			else {
				flag = true;
				cout << "Error!" << endl;
			}
		}

	} while (kod != 0);

}