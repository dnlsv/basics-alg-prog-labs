//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
	double x, y, z, a, b, c, d, e, p, q, r, w, t, f, g, rez;
	puts("\n\tx,y,z = ");
	scanf("%lf%lf%lf", &x, &y, &z);
	a = fabs(x);
	b = pow(a, 1. / 3);
	c = pow(y, b);
	d = fabs(x - y);
	e = pow(sin(z), 2);
	p = sqrt(x + y);
	q = 1 + e / p;
	r = exp(d);
	w = x / 2;
	t = d * q / (r + w);
	g = pow(cos(y), 3);
	f = g * t;
	rez = c + f;
	printf("\n x = %7.3lf\n y = %7.3lf\n z = %7.3lf\nRezult = %lf\n", x, y, z, rez);
	puts("Press any key ... ");
	getch();
	return 0;
}