#include <iostream>
using namespace std;

typedef double(*TFun)(double, int);
double calculateFunction(double, int);
double calculateModyl(double, int);
double calculateSum(double, int);

void inputData(double&, double&, double&, int&);
void inputNum(int&);
bool isNumberNumeric();

void Out_Rez(double a, double b, double h, int n);

int main()
{
	setlocale(LC_ALL, ".UTF8");
	int kod;
	double a, b, h;
	int n;

	do {
		inputData(a, b, h, n);

		Out_Rez(a, b, h, n);
		cout << endl;

		inputNum(kod);
	} while (kod != 0);
	return 0;
}

double calculateFunction(double x, int n)
{
	return exp(2 * x);
}

double calculateSum(double x, int n)
{
	double r, sum;
	r = sum = 1;
	for (int k = 1; k <= n; ++k) {
		r = r * 2 * x / k;
		sum += r;
	}
	return sum;
}

double calculateModyl(double x, int n)
{
	double sum = calculateSum(x, n);
	double y = calculateFunction(x, n);
	return fabs(sum - y);
}

void Out_Rez(double a, double b, double h, int n)
{
	for (double x = a; x <= b + h / 2; x += h)
		printf("\n x= %8.5lf   sum= %8.5lf   y= %8.5lf  p= %8.5lf\n ", x, calculateFunction(x, n), calculateSum(x, n), calculateModyl(x, n));
}

//ЗАЩИТА

void inputData(double& a, double& b, double& h, int& n)
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

void inputNum(int& num)
{
	while (true)
	{
		cout << "Для продолжения работы программы нажмите 1" << endl;
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