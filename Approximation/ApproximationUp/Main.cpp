#include <math.h>
#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

double Mn_New(double*, double, int, double*);
double* coeffs(double*, double*, int);
double fun(double);
void checkInt(int&);
void checkDouble(double&);

int main() {
	setlocale(LC_ALL, ".UTF8");
	double x, h, h1, a, b, * mas_x, * mas_y_t, * mas_y, * d;
	int i, n, m;

	cout << "Введите a" << endl;
	checkDouble(a);
	cout << "Введите b" << endl;
	while (1) {
		checkDouble(b);
		if (b > a)
			break;
		else
			cout << "Error!" << endl;
	}
	cout << "Введите m" << endl;
	checkInt(m);
	cout << "Введите n" << endl;
	checkInt(n);

	h = (b - a) / (m - 1);
	h1 = (b - a) / (n - 1);

	mas_x = new double[m];
	mas_y_t = new double[n];
	mas_y = new double[m];
	d = new double[m];

	for (x = a, i = 0; i < m; i++) {
		mas_x[i] = x;
		x += h;
	}

	cout << endl << "Исходные значения" << endl;
	for (i = 0; i < m; i++) {
		mas_y[i] = fun(mas_x[i]);
		cout << "x = " << mas_x[i] << "   f(x) = " << mas_y[i] << endl;
	}

	d = coeffs(mas_x, mas_y, m);
	cout << endl << "---- Многочлен Ньютона ---" << endl;
	cout << "Получили " << n << " значений" << endl;
	for (x = a, i = 0; i < n; i++, x += h1) {
		mas_y_t[i] = Mn_New(mas_x, x, m, d);
		cout << "x = " << x << "   f(x) = " << mas_y_t[i] << endl;
	}

	delete[]mas_x;
	delete[]mas_y_t;
	delete[]mas_y;
	delete[]d;

	system("pause");
}

//------------------------------ Исходная функция f(x) -----------------------------------------
double fun(double x) {
	return pow(x, 3) - 5 * pow(x, 2);
}

//----------------------------- Многочлен Ньютона -------------------------------------------
double Mn_New(double* x, double xt, int kol, double* k) {
	double S = k[0], p = 1;
	for (int i = 1; i < kol; i++)
	{
		p = p * (xt - x[i - 1]);
		S += k[i] * p;
	}
	return S;
}

double* coeffs(double* x, double* y, int kol)
{
	double* k = new double[kol];
	k[0] = y[0];
	for (int j = 1; j < kol; j++) {
		for (int i = 0; i < kol - j; i++)
		{
			y[i] = (y[i] - y[i + 1]) / (x[i] - x[i + j]);
			k[j] = y[0];
		}
	}
	return k;
}

void checkInt(int& number)
{
	while (true) {
		cin >> number;
		if (number > 0 && cin.get() == '\n')
			break;
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error!" << endl;
		}
	}
}

void checkDouble(double& number) {
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
