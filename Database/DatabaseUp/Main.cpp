#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdio>
#include <io.h>

struct Student
{
	char FIO[100];
	int year;
	int numgr;
	int balls[4];
	double srball;
}temp;

using  namespace std; //Явное указание пространства имён

Student *arr;
FILE *fst, *ftxt;
int siz = sizeof(Student); //возвращающий длину в байтах переменной или типа, помещенных в скобки.

const char WAYDAT[] = "../Out/Data.dat";
const char WAYTXT[] = "../Out/Students.txt";
const char WAYLIST[] = "../Out/List.txt";

void Out(Student, FILE*);
void view(Student);
void begin(int&, int&);
void end(int);

void inputNumber(int&);
bool isNumberNumeric();
void inputData(int&, int);
void check(FILE*);

void main()
{
	setlocale(LC_ALL, ".UTF8"); //задает локаль

	Student newst;
	FILE *fspis;
	int kod, point, kol, i, numst, dan, count, g = 0, k = 0; /*k - Для отслеживания, создана ли хоть одна запись  g - создан ли файл*/
	double fiz, mat, inf, him, sr, pr;
	long len;
	

	//fopen_s(&ftxt, WAYTXT, "w");
	while (1)
	{
		puts("Выберите: \n1 - Создание\n2 - Коррекция\n3 - Просмотр\n4 - Индивидуальное задание\n0 - Выход");
		inputNumber(kod);
		g++;
		if (kod != 1 && g == 1)
			while (kod != 1) {
				puts("Сначала необходимо создать файл");
				inputNumber(kod);
			}
		switch (kod)
		{
		case 1: //Создание

			fopen_s(&fst, WAYDAT, "wb");
			check(fst);
			fclose(fst);
			puts("Create new file\n");
			break;
		case 2: //Коррекция
			puts("\nВыберите: \n1 - Добавление\n2 - Редактирование\n3 - Удаление\n0 - Вернуться");
			inputNumber(point);
			switch (point)
			{
			case 1: //Добавление
				k++;
				fopen_s(&fst, WAYDAT, "ab");
				check(fst);
				printf_s("\nВведите:\n-Фамилию и инициалы:\n");
				fflush(stdin);
				gets_s(temp.FIO);
				printf_s("-Год рождения(от 1873 до 2018):\n");
				count = 2;
				inputData(temp.year, count);
				printf("-Номер группы(6-ти значное значение):\n");
				count = 3;
				inputData(temp.numgr, count);
				printf_s("-Оценки за семестр : по физике, математике, информатике, химии(от 0 до 10):\n");
				count = 4;
				inputData(temp.balls[0], count); inputData(temp.balls[1], count); inputData(temp.balls[2], count); inputData(temp.balls[3], count);
				printf_s("\n");
				fiz = temp.balls[0];
				mat = temp.balls[1];
				inf = temp.balls[2];
				him = temp.balls[3];
				temp.srball = (fiz + mat + inf + him) / 4;
				fwrite(&temp, siz, 1, fst);
				fclose(fst);
				break;
			case 2: //Редактирование
				if (k != 0) {
					begin(numst, kol);

					printf("\nКакие данные Вы хотите изменить:\n1 - Фамилию и инициалы\n2 - Год рождения\n3 - Номер группы\n4 - Оценки за семестр\n");					
					while (1)
					{
						inputNumber(dan);
						if (dan < 4 && dan>0)
							break;
						else
							puts("Некорректный ввод! Повторите попытку!\n");
					}
					printf_s("\nВведите новые данные:\n");
					switch (dan)
					{
					case 1: //Фамилию и инициалы 
						printf_s("\n-Фамилию и инициалы:\n");
						fflush(stdin);
						gets_s(newst.FIO);
						strcpy_s(arr[numst - 1].FIO, newst.FIO);
						break;
					case 2: //Год рождения
						printf_s("-Год рождения(от 1873 до 2018):\n");
						count = 2;
						inputData(newst.year, count);
						arr[numst - 1].year = newst.year;
						break;
					case 3: //Номер группы
						printf("-Номер группы(6-ти значное значение):\n");
						count = 3;
						inputData(newst.numgr, count);
						arr[numst - 1].numgr = newst.numgr;
						break;
					case 4: //Оценки за семестр
						printf_s("-Оценки за семестр : по физике, математике, информатике, химии(от 0 до 10):\n");
						count = 4;
						inputData(newst.balls[0], count); inputData(newst.balls[1], count); inputData(newst.balls[2], count); inputData(newst.balls[3], count);
						arr[numst - 1].balls[0] = newst.balls[0];
						arr[numst - 1].balls[1] = newst.balls[1];
						arr[numst - 1].balls[2] = newst.balls[2];
						arr[numst - 1].balls[3] = newst.balls[3];
						fiz = newst.balls[0]; mat = newst.balls[1]; inf = newst.balls[2]; him = newst.balls[3];
						newst.srball = (fiz + mat + inf + him) / 4;
						arr[numst - 1].srball = newst.srball;
						break;
					default:
						puts("Некорректный ввод! Повторите попытку!\n");
					}
					end(kol);
				}
				else
					puts("Некорректный ввод! Повторите попытку!\n");
				break;
			case 3: //Удаление
				if (k != 0) {
					k--;
					begin(numst, kol);
					for (int i = numst - 1; i < kol - 1; i++)
						arr[i] = arr[i + 1];
					kol--;
					end(kol);
				}
				else
					puts("Некорректный ввод! Повторите попытку!\n");		
				break;
			case 0: //Вернуться
				break;
			default:
				puts("Некорректный ввод! Повторите попытку!\n");
			}

			break;
		case 3: //Просмотр
			view(temp);
			break;
		case 4: //Индивидуальное задание
			if ((fopen_s(&fst, WAYDAT, "rb")) != NULL) {
				puts("\nError!");
				return;
			}
			len = _filelength(_fileno(fst));
			kol = len / siz;
			fclose(fst);
			if (kol != 0) {
				if ((fopen_s(&fst, WAYDAT, "rb")) != NULL) {
					puts("\nError!");
					return;
				}
				arr = new Student[kol];
				for (i = 0; i < kol; i++) 
					fread(arr, siz, 1, fst);
				fclose(fst);

				sr = 0;
				for (int i = 0; i < kol; i++) {
					pr = arr[i].srball / kol;
					sr = sr + pr;
				}
				printf_s("\nОбщий средний балл - %.1f\n", sr);

				fopen_s(&fspis, WAYLIST, "w");
				check(fspis);
				for (int i = 0; i < kol; i++)
				{
					if (arr[i].srball >= sr)
						fprintf(fspis, "%s\n", arr[i].FIO);
				}
				fclose(fspis);
				printf_s("\nСоздан екстовый файл со списком студентов, средний балл которых выше среднего (%s)\n\n", WAYLIST);
			}
			else
				printf_s("\nВ списке нет ни одного студента\n\n");
			break;
		case 0: //Выход
			//fclose(ftxt);
			return;
		default:
			puts("Некорректный ввод! Повторите попытку!\n");
		}
	}
}

void view(Student t)
{
	int number = 0;
	if ((fopen_s(&fst, WAYDAT, "rb")) != NULL) {
		puts("\nError!");
		return;
	}
	fopen_s(&ftxt, WAYTXT, "w");//TXT
	check(ftxt);
	printf_s("\n\tСписок студентов:\n");
	fprintf(ftxt, "Список студентов:\n");
	while (1) {
		if (fread(&t, siz, 1, fst) == 0) break;
		number++;
		printf_s("№%d\n", number);
		Out(t, ftxt);
	}
	fclose(ftxt);//TXT
	fclose(fst);
}

void begin(int &numst, int &kol)
{
	long len;
	view(temp);	
	fopen_s(&fst, WAYDAT, "rb");
	check(fst);
	len = _filelength(_fileno(fst)); //Возвращает длину файла в байтах. //Возвращает дескриптор файла у казанного потока
	kol = len / siz;
	fclose(fst);
	printf("Введите номер студента\n");
	while (1)
	{
		inputNumber(numst);
		if (numst <= kol && numst > 0)
			break;
		else
			puts("Некорректный ввод! Повторите попытку!\n");
	}

	fopen_s(&fst, WAYDAT, "rb");
	check(fst);
	len = _filelength(_fileno(fst));
	kol = len / siz;
	arr = new Student[kol];
	for (int i = 0; i < kol; i++) {
		fread(arr, siz, 1, fst);
	}
	fclose(fst);
}

void end(int kol)
{
	printf_s("\n\tИзмененный список студентов:\n");
	fopen_s(&ftxt, WAYTXT, "w");//TXT
	check(ftxt);
	for (int i = 0; i < kol; i++) {
		printf_s("№%d\n", i + 1);
		Out(arr[i], ftxt);
	}
	fopen_s(&fst, WAYDAT, "wb");
	check(fst);
	for (int i = 0; i < kol; i++)
		fwrite(&arr[i], siz, 1, fst);
	fclose(fst);
	fclose(ftxt);//TXT
	delete[]arr;
}

void Out(Student t, FILE *ftxt)
{
	printf_s("%s ", t.FIO);
	printf_s("\nГод рождения - %d\nГруппа - %d", t.year, t.numgr);
	printf_s("\nОценки:\nФизика - %d Математика - %d Информатика - %d Химия - %d", t.balls[0], t.balls[1], t.balls[2], t.balls[3]);
	printf_s("\nСредний балл - %.1f", t.srball);
	puts("\n");

	fprintf(ftxt, "%s ", t.FIO);
	fprintf(ftxt, "\nГод рождения - %d\nГруппа - %d", t.year, t.numgr);
	fprintf(ftxt, "\nОценки:\nФизика - %d Математика - %d Информатика - %d Химия - %d", t.balls[0], t.balls[1], t.balls[2], t.balls[3]);
	fprintf(ftxt, "\nСредний балл - %.1f", t.srball);
	fprintf(ftxt, "\n\n");
}

void inputNumber(int &num)
{
	while (true)
	{
		cin >> num;
		if (isNumberNumeric())
			break;
		else
			cout << "Некорректный ввод! Повторите попытку!" << endl;
	}
}

void inputData(int &data, int count)
{
	while (true)
	{
		cin >> data;
		if (isNumberNumeric())
		{

			if (count == 4) {
				if (data >= 0 && data <= 10)
					break;
				else
					cout << "Некорректный ввод! Повторите попытку!" << endl;
			}
			if (count == 3) {
				if ((data / 100000) < 10 && (data / 100000) >= 1)
					break;
				else
					cout << "Некорректный ввод! Повторите попытку!" << endl;
			}
			if (count == 2)
			{
				if (data >= 1873 && data <= 2018)
					break;
				else
					cout << "Некорректный ввод! Повторите попытку!" << endl;
			}
		}
		else
			cout << "Некорректный ввод! Повторите попытку!" << endl;
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

void check(FILE *f)
{
	if (f == NULL) {
		puts("\nError!");
		return;
	}
}

