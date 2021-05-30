#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstdio>
#include <io.h>

using namespace std;

struct Student
{
	char surname[21];
	char name[21];
	char patr[21];
	int age;
	int numgr;
	int him;
	int fiz;
	int mat;
	int inf;
	double srball;
	int number;
};

int sizes = sizeof(Student);

const char WAY[] = "D://C++/File.dat";
const char SWAY[] = "D://C++/File.txt";
const char SSWAY[] = "D://C++/Spisok.txt";

bool isNumberNumeric();
void inputNumber(int&);
void inputDann(Student&, int);

void Out(Student, FILE*);

void main()
{
	setlocale(LC_ALL, "rus");

	Student temp, *arr;
	FILE *fst, *ftxt;
	int kod;
	int point;
	int number = 0;
	Student newst, n1;
	int kol;
	long len;
	int i = 0;
	int numst;
	int kk;
	double pr, sr = 0;
	FILE *fsp;
	double q, w, e, r;
	int prom = -1;
	int m = 0;
	bool flag = true;
	int h;

	//fopen_s(&ftxt, SWAY, "w");
	while (1)
	{
		cout << "Выберите:" << endl << "1 - Создание" << endl << "2 - Коррекция" << endl
			<< "3 - Просмотр" << endl << "4 - Индивидуальное задание" << endl << "0 - Выход" << endl;
		//cin >> kod; 
		inputNumber(prom);
		kod = prom;
		cout << endl;
		switch (kod)
		{
		case 1:
			fopen_s(&fst, WAY, "wb");
			if (fst == NULL) {
				cout << "Error!" << endl;
				return;
			}
			fclose(fst);
			cout << "Create new file" << endl << endl;
			break;
		case 2:
			cout << "Выберите:" << endl;
			cout << "1 - Добавление" << endl << "2 - Редактирование" << endl
				<< "3 - Удаление" << endl << "0 - Вернуться" << endl;
			//cin >> point; 
			inputNumber(prom);
			point = prom;
			cout << endl;
			switch (point)
			{
			case 1:
				fopen_s(&fst, WAY, "ab");

				cout << "Введите:" << endl;
				cout << "-Фамилию и инициалы:" << endl; m = 1;
				//cin >> temp.surname >> temp.name >> temp.patr;
				inputDann(temp, m);
				cout << "-Год рождения(от 1873 до 2018):" << endl; m = 2;
				//cin >> temp.age;
				inputDann(temp, m);
				cout << "-Номер группы(6-ти значное значение):" << endl; m = 3;
				//cin >> temp.numgr;
				inputDann(temp, m);
				cout << "-Оценки за семестр : по физике, математике, информатике, химии(от 0 до 10):" << endl; m = 4;
				//cin >> temp.fiz >> temp.mat >> temp.inf >> temp.him;
				inputDann(temp, m);
				q = temp.fiz; w = temp.mat; e = temp.inf; r = temp.him;
				temp.srball = (q + w + e + r) / 4;
				i++;
				temp.number = i;
				cout << endl;

				fwrite(&temp, sizes, 1, fst);
				fclose(fst);
				break;
			case 2:
				/*fopen_s(&fst, WAY, "rb");
				fread(&temp, sizes, 1, fst);
				fclose(fst);*/

				cout << "Введите номер студента:" << endl;
				//cin >> numst; 
				inputNumber(prom);
				numst = prom;
				flag = true;
				//while (flag) {
					//if (numst > kol || numst < 1) {
					//	cout << endl << "Неверное значение! Повторите попытку!" << endl;
						inputNumber(prom);
					//}
					//else
						//flag = false;
				//}
				cout << endl;

				cout << "Введите:" << endl;
				cout << "-Фамилию и инициалы:" << endl; m = 1;
				cin >> newst.surname >> newst.name >> newst.patr;
				cout << "-Год рождения(от 1873 до 2018):" << endl; m = 2;
				cin >> newst.age;
				cout << "-Номер группы(6-ти значное значение):" << endl; m = 3;
				cin >> newst.numgr;
				cout << "-Оценки за семестр : по физике, математике, информатике, химии(от 0 до 10):" << endl; m = 4;
				cin >> newst.fiz >> newst.mat >> newst.inf >> newst.him;
				q = newst.fiz; w = newst.mat; e = newst.inf; r = newst.him;
				newst.srball = (q + w + e + r) / 4;

				fopen_s(&fst, WAY, "rb");
				len = _filelength(_fileno(fst));
				kol = len / sizes;
				arr = new Student[kol];
				fread(arr, sizes, kol, fst);
				fclose(fst);

				arr[numst - 1] = newst;
				fopen_s(&ftxt, SWAY, "w");

				cout << "Итоговый список студентов:" << endl;
				for (i = 0; i < kol; i++)
					Out(arr[i], ftxt);
				fclose(fst);

				fopen_s(&fst, WAY, "wb");
				for (i = 0; i < kol; i++)
					fwrite(&arr[i], sizes, 1, fst);
				fclose(fst);

				delete[]arr;
				break;
			case 3:
				/*fopen_s(&fst, WAY, "rb");
				fread(&temp, sizes, 1, fst);
				fclose(fst);*/

				fopen_s(&fst, WAY, "rb");
				len = _filelength(_fileno(fst));
				kol = len / sizes;
				arr = new Student[kol];
				fread(arr, sizes, kol, fst);
				fclose(fst);

				cout << "Введите номер студента:" << endl;
				//cin >> numst; 
				inputNumber(prom);
				numst = prom;
				flag = true;
				while (flag) {
					if (numst > kol || numst < 1) {
						cout << endl << "Неверное значение! Повторите попытку!" << endl;
						inputNumber(prom);
					}
					else
						flag = false;
				}
				cout << endl;
		
				arr[numst - 1] = temp;
				
				for (int i = 0; i < kol; i++)
				{
					for (int j = i; j < kol - 1; j++)
						arr[j] = arr[j + 1];
					kol--;
					i--;
				}

				fopen_s(&ftxt, SWAY, "w");
				cout << "Итоговый список студентов:" << endl;
				for (i = 0; i < kol; i++)
					Out(arr[i], ftxt);
				fclose(fst);

				fopen_s(&fst, WAY, "wb");
				for (i = 0; i < kol; i++)
					fwrite(&arr[i], sizes, 1, fst);
				fclose(fst);

				delete[]arr;
				break;
			case 0:
				break;
			default:
				cout << "Неверное значение! Повторите попытку!" << endl << endl;
			}
			break;
		case 3:
			if ((fopen_s(&fst, WAY, "rb")) != NULL) {
				cout << "Error!" << endl;
				break;
			}
			fopen_s(&ftxt, SWAY, "w");
			cout << "Список студентов:" << endl;
			fprintf(ftxt, "Список студентов:");
			while (2) {
				if (fread(&temp, sizes, 1, fst) == 0) break;
				Out(temp, ftxt);
			}
			fclose(fst);
			fclose(ftxt);
			break;
		case 4:
			fopen_s(&fsp, SSWAY, "w");

			fopen_s(&fst, WAY, "rb");
			len = _filelength(_fileno(fst));
			kol = len / sizes;
			arr = new Student[kol];
			fread(arr, sizes, kol, fst);
			fclose(fst);

			sr = 0;
			for (int i = 0; i < kol; i++) {
				pr = arr[i].srball / kol;
				sr = sr + pr;
			}
			cout << "Общий средний бал всех студентов - " << sr << endl << endl;
			for (int i = 0; i < kol; i++)
			{
				if (arr[i].srball > sr)
					fprintf(fsp, "%s %s %s", arr[i].surname, arr[i].name, arr[i].patr);
			}
			cout << "Создан текстовый файл со списком студентов, средний балл которых выше среднего" << endl
				<< "Если он пустой, то таких нет" << endl << endl;
			fclose(fsp);
			break;
		case 0:
			//fclose(ftxt);
			return;
		default:
			cout << "Неверное значение! Повторите попытку!" << endl << endl;
		}
	}
	system("pause");
}

void Out(Student t, FILE *ftxt)
{
	cout << "N " << t.number << endl;
	cout << t.surname << " " << t.name << " " << t.patr << endl
		<< "Год рождения - " << t.age << endl << "Номер грурппы - " << t.numgr << endl
		<< "Оценки:" << endl << "Физика - " << t.fiz << " Математика - " << t.mat
		<< " Информатика - " << t.inf << " Химия - " << t.him << endl
		<< "Средний балл - " << t.srball << endl << endl;
	fprintf(ftxt, "\n№%d", t.number);
	fprintf(ftxt, "\n%s %s %s", t.surname, t.name, t.patr);
	fprintf(ftxt, "\nГод рождения - %d\nГруппа - %d", t.age, t.numgr);
	fprintf(ftxt, "\nОценки:\nФизика - %d Математика - %d Информатика - %d Химия - %d", t.fiz, t.mat, t.inf, t.him);
	fprintf(ftxt, "\nСредний балл - %f", t.srball);
}


void inputNumber(int &prom)
{
	while (true)
	{
		cin >> prom;
		if (isNumberNumeric())
			break;
		else
			cout << endl << "Неверное значение! Повторите попытку!" << endl;
	}
}


void inputDann(Student &temp, int m)
{
	double q;
	while (true)
	{
		if (m == 1)
			cin >> temp.surname >> temp.name >> temp.patr;
		if (m == 2)
			cin >> temp.age;
		if (m == 3)
			cin >> temp.numgr;
		if (m == 4)
			cin >> temp.fiz >> temp.mat >> temp.inf >> temp.him;
		if (isNumberNumeric())
		{

			if (m == 4) {
				if (temp.fiz >= 0 && temp.fiz <= 10 && temp.mat >= 0 && temp.mat <= 10 && temp.inf >= 0 && temp.inf <= 10 && temp.him >= 0 && temp.him <= 10)
					break;
				else
					cout << endl << "Неверное значение! Повторите попытку!" << endl;
			}
			if (m == 2)
			{
				if (temp.age >= 1873 && temp.age <= 2018)
					break;
				else
					cout << endl << "Неверное значение! Повторите попытку!" << endl;
			}
			if (m == 3) {
				q = temp.numgr;
				if ((q / 100000) < 10 && (q / 100000) >= 1)
					break;
				else
					cout << endl << "Неверное значение! Повторите попытку!" << endl;
			}
			if (m == 1)
				break;
		}
		else
		{
			cout << endl << "Неверное значение! Повторите попытку!" << endl;
		}

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

/*cout << "Редактировать:" << endl << "1 - Фамилию и инициалы" << endl << "2 - Год рождения" << endl
					<< "3 - Номер группы" << endl << "4 - Оценки" << endl;
				//cin >> kk;
				inputNumber(prom);
				kk = prom;
				cout << "Введите:" << endl;
				switch (kk)
				{
				case 1:
					cout << "-Фамилию и инициалы:" << endl;
					cin >> newst.surname >> newst.name >> newst.patr;
					newst.age = temp.age; newst.numgr = temp.numgr;
					newst.fiz = temp.fiz; newst.mat = temp.mat; newst.inf = temp.inf; newst.him = temp.him;
					q = newst.fiz; w = newst.mat; e = newst.inf; r = newst.him;
					newst.srball = (q + w + e + r) / 4;
					newst.number = temp.number;
					break;
				case 2:
					cout << "-Год рождения(от 1873 до 2018):" << endl;
					cin >> newst.age;
					strcpy_s(newst.surname, temp.surname); strcpy_s(newst.name, temp.name); strcpy_s(newst.patr, temp.patr);
					newst.numgr = temp.numgr;
					newst.fiz = temp.fiz; newst.mat = temp.mat; newst.inf = temp.inf; newst.him = temp.him;
					q = newst.fiz; w = newst.mat; e = newst.inf; r = newst.him;
					newst.srball = (q + w + e + r) / 4;
					newst.number = temp.number;
					break;
				case 3:
					cout << "-Номер группы(6-ти значное значение):" << endl;
					cin >> newst.numgr;
					strcpy_s(newst.surname, temp.surname); strcpy_s(newst.name, temp.name); strcpy_s(newst.patr, temp.patr);
					newst.age = temp.age;
					newst.fiz = temp.fiz; newst.mat = temp.mat; newst.inf = temp.inf; newst.him = temp.him;
					q = newst.fiz; w = newst.mat; e = newst.inf; r = newst.him;
					newst.srball = (q + w + e + r) / 4;
					newst.number = temp.number;
					break;
				case 4:
					cout << "-Оценки за семестр : по физике, математике, информатике, химии(от 0 до 10):" << endl;
					cin >> newst.fiz >> newst.mat >> newst.inf >> newst.him;
					strcpy_s(newst.surname, temp.surname); strcpy_s(newst.name, temp.name); strcpy_s(newst.patr, temp.patr);
					newst.age = temp.age; newst.numgr = temp.numgr;
					q = newst.fiz; w = newst.mat; e = newst.inf; r = newst.him;
					newst.srball = (q + w + e + r) / 4;
					newst.number = temp.number;
					break;
				default:
					cout << "Неверное значение! Повторите попытку!" << endl << endl;
				}
				cout << endl;
				*/