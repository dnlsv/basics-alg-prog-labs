#include <iostream>
#include <string.h>
#include <cstdlib>
#include <conio.h>

using namespace std;
const int N = 100;

void view(int&, int, int, int, char*, char*, int&);
void inputKod(int&);
void main()
{
	setlocale(LC_ALL, ".UTF8");
	int kod, len, i, j, a = 0, b = 0, c = 0, count, sount, sch;
	char st[N] = " ", podst[N];;

	do
	{
		cout << "Введите строку" << endl;
		cin >> st;
		len = strlen(st);
		sch = 0;

    	for (i = 0; i < len; i++)
		{
			count = 0;
			sount = 0;
			if (st[i] == 'E' || st[i] == 'e') {
				for (j = i - 1; j >= 0; j--) {
					if (isdigit(st[j])) {        //Функция isdigit проверяет аргумент, передаваемый через параметр сharacter, является ли он десятичной цифрой.
						count = 1;
						a = j;
					}
					else
						break;
				}
				if (st[a - 1] == '.') {
					for (j = a - 2; j >= 0; j--) {
						if (isdigit(st[j])) {
							count = 1;
							c = j;
						}
						else
							break;
					}
				}
				if (st[i + 1] == '+' || st[i + 1] == '-') {
					for (j = i + 2; j <= len; j++) {
						if (isdigit(st[j])) {
							sount = 1;
							b = j;
						}
						else
							break;
					}
				}
			}
			view(a, count, sount, b, podst, st, sch);
			view(c, count, sount, b, podst, st, sch);
		}
		if (sch == 0)
			cout << endl << "Таких чисел нет" << endl;

		inputKod(kod);
	} while (kod != 0);
}

void view(int &h, int count, int sount, int b, char *podst, char *st, int &sch)
{
	if (count == 1 && sount == 1) {
		cout << endl;
		for (int i = h; i <= b; i++) {
			podst[i] = st[i];
			cout << podst[i];
			sch++;
		}
		cout << endl;
	}

}

void inputKod(int &kod)
{
		while (true) {
			cout << endl << "Для продолжения работы программы нажмите 1" << endl;
			cout << "Для выхода из программы нажмите 0" << endl;
			cin >> kod;
			if (kod == 1 || kod == 0) {
				if (cin.get() == '\n')
					break;
				else {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Error!" << endl;
				}
			}
			else 
				cout << "Error!" << endl;
		}
}
