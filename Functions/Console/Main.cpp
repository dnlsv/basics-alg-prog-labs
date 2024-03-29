//---------------------------------------------------------------------------
#include <vcl.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])

{
	setlocale(LC_ALL, "Rus");
	double x, y, z, u, a, b, o, p, r, s, t;
	int kod;
	puts("Input a, b, z");
	scanf("%lf%lf%lf", &a, &b, &z);
	puts("Function U(x):\n  0 - 2*x\n  1 - x*x\n  2 - x/3");
	scanf("%d", &kod);

	if (z > 0)
	{
		x = 1 / (z * (z + 2));
		printf("\n\Usloviye - z>0 ");
		printf("\n\x=%lf", x);
	}
	else
	{
		x = 1 - pow(z, 3);
		printf("\n\Usloviye - z<=0 ");
		printf("\n\x=%lf", x);
	}

	switch (kod) {
	case 0: 	u = 2 * x;  printf("\n\Function - 2*x "); printf("\n\u=%lf", u);   break;
	case 1: 	u = x * x;  printf("\n\Function - x*x "); printf("\n\u=%lf", u);   break;
	case 2: 	u = x / 3;  printf("\n\Function - x/3 "); printf("\n\u=%lf", u);   break;
	}

	o = exp((-3) * x);
	p = 2.5 * a * o;
	r = 4 * b * x * x;
	s = log(fabs(x));
	y = (p - r) / (s + u);

	printf("\n\y= %8.6lf", y);
	puts("\nPress any key ... ");
	getch();
	return 0;
}
