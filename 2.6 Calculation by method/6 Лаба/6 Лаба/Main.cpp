#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

double f(double);
double pr(double);
double Metod(double, double, double, int&);
void checkIn(double &);
void checkSign(double &);

double f(double x)
{
	return pow(x, 3) - 5 * pow(x, 2) + 12;
}

double pr(double x)
{
	return 3 * pow(x, 2) - 10 * x;           //Производная
}

double Metod(double x, double x0, double e, int &iter) {
	iter = 0;
	do
	{
		x0 = x;
		x = x0 - f(x) / pr(x);
		iter++;
	} while (fabs(x0 - x) > e);
	return x;
}

int main()
{
	double a, b, e, h, x, z;
	int count = 0, iter = 0;

	cout << "Input a:" << endl;
	checkIn(a);
	cout << "Input b:" << endl;
	while (1) {
		checkIn(b);
		if (b > a)
			break;
		else
			cout << "Error!" << endl;
	}
	cout << "Input h:" << endl;
	checkSign(h);
	cout << "Input accuracy" << endl;
	checkSign(e);

	for (x = a; x <= b; x += h) {
		if (f(x)*f(x + h) < 0) {
			count++;
			z = Metod(x, x + h, e, iter);
			cout << endl << "F(x) = " << f(z) << endl;
			cout << count << " root = " << z << endl;
			cout << "Iteracii = " << iter << endl;
		}
	}

	if (count == 0) cout << "No roots" << endl;

	system("pause");
	return 0;
}

void checkIn(double &number)
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

void checkSign(double &number) {
	while (1) {
		checkIn(number);
		if (number > 0)
			break;
		else
			cout << "Error!" << endl;
	}
}