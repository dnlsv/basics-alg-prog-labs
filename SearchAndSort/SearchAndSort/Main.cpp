#include <iostream>
#include <io.h>
#include <string>

struct Staff
{
	char FIO[100];
	int dept;
	char position[100];
	int date;
};

using namespace std;

void create(FILE *);
void add(FILE *, Staff *, int &);
void view(FILE *, Staff *);
void searchLinear(Staff *, int);
void sortSelection(Staff *, int);
void conclution(Staff *, int);
void quickSort(Staff *, int, int);
void binarySearch(Staff *, int);

void checkIn(int &);
void check(FILE *);

int siz = sizeof(Staff);

const char WAYDAT[] = "../Out/Data.dat";

int main(){
	setlocale(LC_ALL, ".UTF8");
	bool flag = false;

	while (1) {

		Staff temp, *arr;
		FILE *fst;
		int count = 0, kod, kol = 1;
		long len;

		fopen_s(&fst, WAYDAT, "rb");
		len = _filelength(_fileno(fst));
		kol = len / siz;
		arr = new Staff[kol];
		for (int i = 0; i < kol; i++)
		fread(&arr[i], siz, 1, fst);
		fclose(fst);
		
		cout << "1 - Создание" << endl << "2 - Добавление" << endl << "3 - Просмотр" << endl << "4 - Линейный поиск" 
			<< endl << "5 - Сортировка методом прямого выбора" << endl << "6 - Сортировка методом QuickSort" 
			<< endl << "7 - Двоичный поиск" << endl << "0 - Выход" << endl;
		while (1) {
			checkIn(kod);
			if (flag == true)
				break;
			else
				if (flag == false && (kod == 1 || kod == 0))
					break;
				else
					cout << "Создайте файл!" << endl;
		}

		switch (kod) {
		case 1:
			fopen_s(&fst, WAYDAT, "wb");
			create(fst);
			flag = true;
			break;
		case 2:
			fopen_s(&fst, WAYDAT, "ab");
			add(fst, &temp, count);
			break;
		case 3:
			fopen_s(&fst, WAYDAT, "rb");
			view(fst, &temp);
			break;
		case 4:
			searchLinear(arr, kol);
			break;
		case 5:
			sortSelection(arr, kol);
			conclution(arr, kol);
			break;
		case 6:
			quickSort(arr, 0, kol - 1);
			conclution(arr, kol);
			break;
		case 7:
			quickSort(arr, 0, kol - 1);
			binarySearch(arr, kol);
			break;
		case 0:
			return 0;
		default:
			cout << "Error!" << endl << endl;
		}
		delete[]arr;
	}
}

void create(FILE *fst) {
	check(fst);
	fclose(fst);
	puts("Create new file\n");
}

void add(FILE *fst, Staff *temp, int &count) {
	count++;
	check(fst);
	cout << endl << "Введите:" << endl << "Фамилию и инициалы" << endl;
	cin >> (*temp).FIO;
	cout << "Номер отдела" << endl;
	checkIn((*temp).dept);
	cout << "Должность" << endl;
	cin >> (*temp).position;
	cout << "Дату начала работы" << endl;
	checkIn((*temp).date);
	fwrite(&(*temp), siz, 1, fst);
	fclose(fst);
	cout << endl << "Сотрудник добавлен!" << endl << endl;
}

void view(FILE *fst, Staff *t)
{
	while (1) {
		if (fread(&(*t), siz, 1, fst) == 0) break;
		printf_s("\n%s ", (*t).FIO);
		printf_s("\nНомер отдела - %d\nДолжность - %s\nДата начала работы - %d\n\n", (*t).dept, (*t).position, (*t).date);
	}
	fclose(fst);
}

void searchLinear(Staff *arr, int kol)
{
	int key;
	bool flag = false;
	cout << endl << "Введите дату начала работы для поиска" << endl;
	cin >> key;
	cout << "\tРезультат" << endl;
	for (int i = 0; i < kol; i++)
		if (arr[i].date == key) {
			flag = true;
			cout << arr[i].FIO << endl;
		}
	cout << endl;
	if (flag == false)
		cout << "Сотрудник не найден!" << endl << endl;
}

void sortSelection(Staff *arr, int kol) {
	int i, j;
	Staff rez;
	for (i = 0; i < kol - 1; i++)
		for (j = i + 1; j < kol; j++)
			if (arr[i].date > arr[j].date) {
				rez = arr[j];
				arr[j] = arr[i];
				arr[i] = rez;
			}
}

void conclution(Staff *arr, int kol) {
	cout << endl;
	for (int i = 0; i < kol; i++)
		cout << arr[i].FIO << endl;
	cout << endl;
}

void quickSort(Staff *a, int begin, int end)
{
	int left, right, x;
	Staff rez;
	left = begin;
	right = end;
	x = a[(left + right) / 2].date;
	do {
		while (a[left].date < x)  left++;
		while (x < a[right].date) right--;
		if (left <= right) {
			rez = a[left];
			a[left] = a[right];
			a[right] = rez;
			left++;
			right--;
		}
	} while (left <= right);
	if (begin < right) quickSort(a, begin, right);
	if (left < end) quickSort(a, left, end);
}

void binarySearch(Staff *a, int  kol)
{
	int i = 0, j = kol - 1, m, key;
	cout << endl << "Введите дату начала работы для поиска" << endl;
	cin >> key;
	while (i < j) {
		m = (i + j) / 2;
		if (key > a[m].date) 
			i = m + 1;
		else 
			j = m;
	}
	cout << "\tРезультат" << endl;
	if (a[i].date == key)
		cout << a[i].FIO << endl << endl;
	else
		cout << endl << "Сотрудник не найден!" << endl << endl;
}

void checkIn(int &number)
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

void check(FILE *f)
{
	if (f == NULL) {
		puts("\nError!");
		return;
	}
}

/*int i, j;
	Staff rez;
	for (i = 0; i < kol - 1; i++)
		for (j = i + 1; j < kol; j++)
			if (arr[i].dept < arr[j].dept) {
				rez = arr[j];
				arr[j] = arr[i];
				arr[i] = rez;
			}

	int k, w;
	Staff *b;
	b = new Staff[kol];

	i = 0;
	j = 0;
	w = 1;
	while (j != kol) {
		k = i;
		cout << "k = " << k << endl;
		while (arr[i].date == arr[w].date) {
			b[j] = arr[i];
			j++;
			i++;
			w++;
		}
		cout << "j = " << j << endl;
		cout << "i = " << i << endl;
		cout << "w = " << w << endl;
		for (int p = k; p < w-1; p++)
			for (int t = k + 1; t < w; t++)
				if (b[p].date > b[t].date) {
					rez = b[t];
					b[t] = b[p];
					b[p] = rez;
				}
		for (int q = k+1; q < w; q++)
			cout << b[q].FIO << endl;
	}

	delete[]b;*/

/*
int i, j;
Staff rez;
for (i = 0; i < kol - 1; i++)
	for (j = i + 1; j < kol; j++)
		if (arr[i].dept < arr[j].dept) {
			rez = arr[j];
			arr[j] = arr[i];
			arr[i] = rez;
		}
*/

/*int i, j, k = 0;
	Staff *b, rez;
	b = new Staff[kol];
	for (i = 0; i < kol - 1; i++) {
		for (j = i + 1; j < kol; j++)
			if (arr[i].dept == arr[j].dept) {
				rez = arr[i];
				b[k] = arr[j];
				k++;
			}
		if (k != 0) break;
	}
	b[k++] = rez;
	for (i = 0; i < kol; i++)
		cout << b[i].FIO << endl;

	delete[]b;*/