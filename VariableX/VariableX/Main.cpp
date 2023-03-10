#include <iostream>

using namespace std;

void inputNum(int &num);
void inputData(double &a, double &b, double &h, int &n);
bool isNumberNumeric();

void main()
{
	setlocale(LC_ALL, ".UTF8");
	double a, b, x, h, r, sum, y, p;
	int n, k;
	int kod = 0;
	do {
		inputData(a, b, h, n);	

		for (x = a; x <= b + h / 2; x += h) {
			r = sum = 1;
			for (k = 1; k <= n; ++k) {
				r = r * 2 * x / k;
				sum += r;
			}
			y = exp(2 * x);
			p = fabs(sum - y);
			printf("\n x= %8.5lf   sum= %8.5lf   y= %8.5lf  p= %8.5lf\n ", x, sum, y, p);
		}
		inputNum(kod);	

      } while (kod != 0);				
	//system("pause");
}

//Защита

void inputData(double &a, double &b, double &h, int &n)
{
    while (true)
	{
		cout << "Введите a, b, h, n:" << endl;
		cin >> a >> b >> h >> n;
		if (isNumberNumeric() && b >= a && h >= 0)
			break;
		else
			cout << "Некорректный ввод!" << endl;
	}
}

void inputNum(int &num)
{
	while (true)
	{
		cout << endl << "Для продолжения работы программы нажмите 1" << endl;
		cout << "Для выхода из программы нажмите 0" << endl;
		cin >> num;
		if (isNumberNumeric() && (num == 1 || num == 0))
			break;
		else
			cout << "Некорректный ввод!" << endl;
	}
}

bool isNumberNumeric()
{
	if (cin.get() == '\n') return true;
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
}
