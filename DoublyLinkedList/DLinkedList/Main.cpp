#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <ctime>

using namespace std;

struct Spis2 {
	int info;
	Spis2  *prev, *next;
};

void Create_Spis2(Spis2 **, Spis2 **, int);
void Add_Spis2(int, Spis2 **, Spis2 **, int);
void View_Spis2(int, Spis2 *);
void Del_All(Spis2  **);
void Delete(Spis2 **, Spis2 **);
double SrAr(Spis2 *);
void checkNumber(int &, int);

int main() {
	setlocale(LC_ALL, ".UTF8");
	int in, kod, kod1, count, si = 0;
	char Str[2][10] = { "Begin ", "End " };
	Spis2  *begin = 0, *end = 0, *t;
	cout << "-------Spis-------" << endl;
	while (true) {
		cout << endl << "1 - Create." << endl << "2 - Add." << endl << "3 - View." << endl << "4 - Del." << endl << "5 - Task."
			<< endl << "0 - EXIT." << endl;
		count = 0;
		checkNumber(kod, count);
		switch (kod) {
		case 1:
			si = 1;
			if (begin != NULL) {
				cout << "Clear Memory!" << endl;
				break;
			}
			cout << "Begin Info = ";
			count = 0;
			checkNumber(in, count);
			Create_Spis2(&begin, &end, in);
			cout << "Creat Begin = " << begin->info << endl;
			break;
		case 2:
			if (si == 1) {
				cout << "Info = ";
				count = 0;
				checkNumber(in, count);
				cout << "Add Begin - 0, Add End - 1 :  ";
				count = 1;
				checkNumber(kod1, count);
				Add_Spis2(kod1, &begin, &end, in);
				if (kod1 == 0)
					t = begin;
				else
					t = end;
				cout << "Add to " << Str[kod1] << "  " << t->info << endl;
			}
			else
				cout << "List Empty!" << endl;
			break;
		case 3:
			if (!begin) {
				cout << "List Empty!" << endl;
				break;
			}
			cout << "View Begin - 0, View End - 1 : ";
			count = 1;
			checkNumber(kod1, count);
			if (kod1 == 0) {
				t = begin;
				cout << "-- Begin --" << endl;
			}
			else {
				t = end;
				cout << "--- End --" << endl;
			}
			View_Spis2(kod1, t);
			break;
		case 4:
			Del_All(&begin);
			si = 0;
			cout << "Memory Free!" << endl;
			break;
		case 5:
			if (!begin)
				cout << "List Empty!" << endl;
			else {
				Delete(&begin, &end);
				cout << "Users Removed!" << endl;
			}
			break;
		case 0:  if (begin != NULL)
			Del_All(&begin);
			return 0;
		default:
			cout << "Error!" << endl;
		}
	}
}

void Create_Spis2(Spis2 **b, Spis2 **e, int in) {
	Spis2 *t = new Spis2;
	t->info = in;
	t->next = t->prev = NULL;
	*b = *e = t;
}

void Add_Spis2(int kod, Spis2 **b, Spis2 **e, int in) {
	Spis2 *t = new Spis2;
	t->info = in;
	if (kod == 0) {
		t->prev = NULL;
		t->next = *b;
		(*b)->prev = t;
		*b = t;
	}
	else {
		t->next = NULL;
		t->prev = *e;
		(*e)->next = t;
		*e = t;
	}
}

void View_Spis2(int kod, Spis2 *t) {
	while (t != NULL) {
		cout << t->info << endl;           
		if (kod == 0) t = t->next;
		else  t = t->prev;
	}
}

void  Del_All(Spis2  **p) {
	Spis2 *t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void Delete(Spis2 **begin, Spis2 **end) {
	Spis2 *t = *begin, *key;
	double Sr;
	int k = 0;
	Sr = SrAr(*begin);
	cout << "Average: " << Sr << endl;
	while (t != 0) {
		if (t->info < Sr) {
			k++;
			if (t == *begin) {
				*begin = (*begin)->next;
				delete t;
				(*begin)->prev = NULL;
				t = *begin;
			}
			else {
				if (t == *end) {
					*end = (*end)->prev;
					delete t;
					(*end) -> next = NULL;  
					t = *end;
				}
				else {
					key = t->next;
					(t->prev)->next = t->next;
					(t->next)->prev = t->prev;
					delete t;
					t = key;
				}
			}
		}
		else
			t = t->next;
	}
	cout << "Less Average: " << k << endl;
}

double SrAr(Spis2 *t) {
	double sum = 0, k = 0, Sr;
	while (t != NULL) {
		sum += t->info;
		k++;
		t = t->next;
	}
	Sr = sum / k;
	return Sr;
}

void checkNumber(int &number, int count)
{
	while (true) {
		cin >> number;
		if ((count == 1) && (number < 0 || number>1)) {
			cout << "Error!" << endl;
			continue;
		}
		if (cin.get() == '\n')
			break;
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error!" << endl;
		}
	}
}



/*Spis2* Delete(Spis2* b) {
	Spis2 *key; //вспомогательный указатель
	Spis2 *t = b;
	double Sr;
	Sr = SrAr(b);
	cout << "Average: " << Sr << endl;
	while (t != 0) {
		if (t->info < Sr) {
			if (t != NULL) { //проверка на корректность
				if (t->prev == NULL) { //удаляем первый элемент
					b = b->next;
					delete(t);
					b->prev = NULL;
					t = b;
				}
				else { //удаляем непервый элемент
					if (t->next == NULL) { 	 //удаляем последний элемент
						t->prev->next = NULL;
						delete(t);
						t = b;
					}
					else { //удаляем непервый и непоследний элемент
						key = t->next;
						t->prev->next = t->next;
						t->next->prev = t->prev;
						delete(t);
						t = key;
					}
				}
			}
		}
		t = t->next;
	}
	return b;
}*/

/*Swap(&begin, &end);
cout << "Users Swap!" << endl;*/

/*
void Swap(Spis2 **b, Spis2 **e)
{
	Spis2 *t = *b, *p = *e, *m = (*b)->next, *n = (*e)->prev;
	p->next = m;
	m->prev = p;
	t->prev = n;
	n->next = t;
	p->prev = NULL;
	t->next = NULL;
	*b = p;
	*e = t;
}
*/

