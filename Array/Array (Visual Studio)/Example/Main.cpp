#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
void main()
{
	int a[10], n, i, kol = 0;
	//int x, y;
	//randomize();				// Изменение начального адреса для random()
	printf("Input N (<=10) ");
	cin >> n;
	//cin >> x >> y;
	//scanf("%d", &n);
	puts("\n Massiv A");
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		a[i] = rand() % (21 - (-10) + 1) + (-10);
		//a[i] = rand() % (x - y + 1) + y;
		//a[i] = random(21) - 10; 		// Заполнение массива А случайными числами
		printf("%4d", a[i]);
	}
	//Удаление отрицательных элементов из массива А
	for (i = 0; i < n; i++)
		if (a[i] >= 0)  a[kol++] = a[i];
	puts("\n Rezult massiv A");
	for (i = 0; i < kol; i++) printf("%4d", a[i]);
	puts("\n Press any key ... ");
	//getch();
	system("pause");
}