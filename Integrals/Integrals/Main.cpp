#include <iostream>
#include <math.h>

using namespace std;

double FSR(double, double, int);
double FTR(double, double, int);
double Metod(double, double, double);
double fun(double);
void checkIn(double&);

int main() {
	setlocale(LC_ALL, ".UTF8");
	double a, b, eps, Int;
	cout << "Введите a" << endl;
	checkIn(a);
	cout << "Введите b" << endl;
	while (1) {
		checkIn(b);
		if (b > a)
			break;
		else
			cout << "Error!" << endl;
	}
	cout << "Введите exp" << endl;
	while (1) {
		checkIn(eps);
		if (eps > 0)
			break;
		else
			cout << "Error!" << endl;
	}

	Int = Metod(a, b, eps);

	cout << "Значение интеграла = " << Int << endl;
	system("pause");
	return 0;
}

double FSR(double a, double b, int n) {
	double h, S, x;
	int i;
	h = (b - a) / n;
	S = 0;
	for (i = 0; i < n - 1; i++)
	{
		x = a + i * h;
		S = S + fun(x);
	}
	S = h * S;
	return S;
}

double FTR(double a, double b, int n)
{
	double h = (b - a) / n;
	double sum = (fun(b) - fun(a)) / 2.0;

	double x = a + h;
	for (int i = 1; i < n - 1; i++)
	{
		sum = sum + fun(x);
		x = x + h;
	}
	return h * sum;
}

double Metod(double a, double b, double eps) {
	double rez, ftr, fsr;
	int m = 2;
	do {
		ftr = FTR(a, b, m);
		fsr = FSR(a, b, m);
		rez = (ftr + 2 * fsr) / 3;
		if (fabs(fsr - ftr) >= eps)
			m = 2 * m;
	} while (fabs(fsr - ftr) >= eps);
	return rez;
}

//------------------------------ Подынтегральная функция f(x) ------------------------------
double fun(double x) {
	return pow(x, 3) - 5 * x * x;
}

void checkIn(double& number)
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

/*cin >> kod;
	switch (kod) {
	case 0:
		cout << "Расчет по разбиению на n = " << n << endl;
		Int1 = Metod(a, b, n, eps);
		break;
	case 1:
		n1 = 2;
		cout << "Расчет по точности eps" << endl;
		Int1 = Metod(a, b, n1, eps);
		do {
			n1 *= 2;
			Int2 = Metod(a, b, n1, eps);
			pogr = fabs(Int2 - Int1);
			Int1 = Int2;
		} while (pogr > eps);
		cout << "При n = " << n1 << endl;
		break;
	}*/

	/*double Simps(double f(double x), double a, double b, int n) {
		double s = 0, h, x;
		h = (b - a) / n;
		x = a;
		for (int i = 1; i <= n; i++) {
			s += f(x) + 4 * f(x + h / 2) + f(x + h);
			x += h;
		}
		return s * h / 6;
	}*/