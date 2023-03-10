#include <vcl.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int a[10],n, i, kol=0;
    randomize();                                // Изменение начального адреса для random()
    printf("Input N (<=10) ");
    scanf("%d", &n);
    puts("\n Massiv A");
    for(i=0; i<n;i++) {
           a[i] = random(21)-10;                // Заполнение массива А случайными числами
           printf("%4d", a[i]);
    }
    for (i = 0; i < n; i++)                     //Удаление отрицательных элементов из массива А
            if(a[i]>=0)  a[kol++] = a[i];
    puts("\n Rezult massiv A");
    for(i=0; i<kol;i++) printf("%4d", a[i]);
    puts("\n Press any key ... ");
    getch();
}
 
