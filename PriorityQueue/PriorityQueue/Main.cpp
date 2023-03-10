#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <ctime>
#include <conio.h>

using namespace std;

struct Queue {
	char str;
	Queue *next;
	double value;
};

int  Prior(char);
Queue* InS(Queue*, char);
Queue* OutS(Queue*, char*);
double Pop(Queue **);
void Push(Queue **, double);
void checkNumber(double &);
void checkIn(char In[]);

int main()
{
	setlocale(LC_ALL, ".UTF8");
	double kod;
	do {
		Queue *t, *Op = NULL;
		char a, In[81], Out[81];
		int   k = 0, l = 0;
		double number = 0, vl = 0;

		cout << "Input formula: ";
		checkIn(In);

		while (In[k] != '\0') {
			if (In[k] >= 'A'&&In[k] <= 'Z' || In[k] >= 'a'&&In[k] <= 'z')
				Out[l++] = In[k];
			if (In[k] == '(')
				Op = InS(Op, In[k]);
			if (In[k] == ')') {
				while ((Op->str) != '(') {
					Op = OutS(Op, &a);
					if (!Op) a = '\0';
					Out[l++] = a;
				}
				t = Op;
				Op = Op->next;
				delete t;
			}
			if (In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/') {
				while (Op != NULL && Prior(Op->str) >= Prior(In[k])) {
					Op = OutS(Op, &a);
					Out[l++] = a;
				}
				Op = InS(Op, In[k]);
			}
			k++;
		}
		while (Op != NULL) {
			Op = OutS(Op, &a);
			Out[l++] = a;
		}
		Out[l] = '\0';
		cout << "Polish = " << Out << endl;

		for (int i = 0; Out[i] != '\0'; i++)
		{
			if (Out[i] >= 'A'&&Out[i] <= 'Z' || Out[i] >= 'a'&&Out[i] <= 'z')
			{
				cout << "Введите " << Out[i] << ": ";
				checkNumber(number);
				Push(&Op, number);
			}
			else
			{
				vl = Pop(&Op);
				switch (Out[i])
				{
				case '/':Push(&Op, Pop(&Op) / vl);
					break;
				case '*':Push(&Op, Pop(&Op) * vl);
					break;
				case '-':Push(&Op, Pop(&Op) - vl);
					break;
				case '+':Push(&Op, Pop(&Op) + vl);
					break;
				}
			}
		}
		cout << "Ответ: " << Op->value << endl;
		cout << endl << "Для продолжения нажмите 1. Для выхода 0" << endl;
		while (true) {
			checkNumber(kod);
			if (kod == 0 || kod == 1)
				break;
			else
				cout << "Error!" << endl;
		}
		cout << endl;
	} while (kod != 0);
	return 0;
}

int  Prior(char a) {
	switch (a) {
	case '*': 	case '/': 	return 3;
	case '-': 	case '+': 	return 2;
	case '(':   return 1;
	}
	return 0;
}

Queue*  InS(Queue *p, char s)
{
	Queue *t = new Queue;
	t->str = s;
	t->next = p;
	return t;
}

Queue*  OutS(Queue *p, char *s)
{
	Queue *t = p;
	*s = p->str;
	p = p->next;
	delete t;
	return p;
}

void Push(Queue **Op, double n)
{
	Queue *t = new Queue;
	t->next = *Op;
	t->value = n;
	*Op = t;
}

double Pop(Queue **Op)
{
	double number = (*Op)->value;
	Queue *bufer = *Op;
	*Op = (*Op)->next;
	delete bufer;
	return number;
}

void checkNumber(double &number)
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

void checkIn(char In[])
{
	while (true)
	{
		int count = 0, sk = 0, j = 0, k = 0, p = 0;
		cin >> In;
		while (In[k] != '\0') {
			if (In[k] == '(') {
				p = k + 1;
				if (In[p] == ')' || In[p + 1] == ')' || In[p + 2] == ')')
					count = 1;
				sk++;
			}
			if (In[k] == ')')
				sk--;
			if (In[k] == '+' || In[k] == '-' || In[k] == '*' || In[k] == '/') {
				j = k + 1;
				if (In[j] >= 'A'&&In[j] <= 'Z' || In[j] >= 'a'&&In[j] <= 'z' || In[j] == '(')
					cout << "";
				else
					count = 1;
			}
			if (In[k] >= 'A'&&In[k] <= 'Z' || In[k] >= 'a'&&In[k] <= 'z') {
				j = k + 1;
				if (In[j] == '+' || In[j] == '-' || In[j] == '*' || In[j] == '/' || In[j] == ')' || In[j] == '\0')
					cout << "";
				else
					count = 1;
			}
			if (In[k] != '+' && In[k] != '-' && In[k] != '*' && In[k] != '/' && In[k] != '(' && In[k] != ')') {
				if (In[k] >= 'A'&&In[k] <= 'Z' || In[k] >= 'a'&&In[k] <= 'z')
					cout << "";
				else
					count = 1;
			}
			k++;
		}
		if (In[0] == '+' || In[0] == '-' || In[0] == '*' || In[0] == '/' || In[0] == ')')
			count = 1;
		if (sk != 0)
			count = 1;
		if (count == 0)
			break;
		else
			cout << "Error!" << endl;
	}
}