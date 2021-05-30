#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void checkNumber(int&);

void main()
{
	setlocale(LC_ALL, "rus");
	int x, y, **a, n, m, i, j, **s, sum, *pr, kod;
	
	do {
		cout << "������� �������� ����������� ��������� �������:" << endl;
		cout << "�� "; checkNumber(x);
		cout << "�� "; checkNumber(y);
		cout << "[" << x << "," << y << "]" << endl << endl;

		if (y < x) 
			cout << "Error!" << endl;
		else {
			cout << "������� ���������� �����, n = ";
			checkNumber(n);
			cout << "������� ���������� �������, m = ";
			checkNumber(m);
		
			cout << endl;
			if (n <= 0 || m <= 0) 
				cout << "Error!" << endl;
			else {
				a = new int*[n];
				for (i = 0; i < n; i++) {
					a[i] = new int[m];
				}

				s = new int*[n];
				for (i = 0; i < n; i++) {
					s[i] = new int[m];
				}

				cout << " �������� �������:" << endl;
				//cout << endl;
				srand(time(NULL));
				for (i = 0; i < n; i++) {
					for (j = 0; j < m; j++) {
						a[i][j] = rand() % (y - x + 1) + x;
						cout << setw(5) << a[i][j];
					}
					cout << endl;
				}
				cout << endl;

				cout << " ����� ��������� ������ ������:" << endl;
				for (i = 0; i < n; i++) {
					sum = 0;
					for (j = 0; j < m; j++) {
						sum += a[i][j];
					}
					s[i][0] = sum;
					cout << " " << sum << endl;
				}
				cout << endl;

				for (i = 0; i < n - 1; i++) {
					for (j = i + 1; j < n; j++) {
						if (s[i][0] > s[j][0]) {
							pr = a[i];
							a[i] = a[j];
							a[j] = pr;
						}
					}
				}

				cout << " ��������������� �������:" << endl;
				//cout << endl;
				for (i = 0; i < n; i++) {
					for (j = 0; j < m; j++) 
						cout << setw(5) << a[i][j];
					cout << endl;
				}

				for (i = 0; i < n; i++) 
					delete[]s[i];
				delete[]s;

				for (i = 0; i < n; i++) 
					delete[]a[i];
				delete[]a;
				cout << endl;
			}
		}

		bool flag = true;
		while (flag) {
			cout << "��� ����������� ������ ��������� ������� 1" << endl;
			cout << "��� ������ �� ��������� ������� 0" << endl;
			checkNumber(kod);
			if (kod == 1 || kod == 0) 
				flag = false;
			else {
				flag = true;
				cout << "Error!" << endl;
			}
		}	
	} while (kod != 0);
	//system("pause");
}

void checkNumber(int &number)
{
	while (true) {
		cin >> number;
		if (cin.get() == '\n')
			break;
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error!" << endl;
		}
	}
}
