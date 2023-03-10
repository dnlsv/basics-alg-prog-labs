#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <ctime>

using namespace std;

struct Stack {
	double info;
	Stack * next;
};

Stack* InStack(Stack*, double);
void View(Stack*);
void Del_All(Stack **);
double SrAr(Stack  *);
//Stack* Del(Stack *, int);
Stack* OutStack(Stack*, double*);
Stack* AddSr(Stack*, int, double);
void checkNumber(int &);

void main() {
	setlocale(LC_ALL, ".UTF8");
	int i, in, n, kod;
	Stack *begin = NULL;
	while (true) {
		cout << endl << "1 - Create." << endl << "2 - Add." << endl << "3 - View." << endl << "4 - Del." << endl << "5 - Task."
			<< endl << "0 - EXIT." << endl;
		checkNumber(kod);
		switch (kod) {
		case 1:
		case 2:
			if (kod == 1 && begin != NULL) {
				cout << "Clear Memory!" << endl;
				break;
			}
			cout << "Input kol = ";
			checkNumber(n);
			srand(time(NULL));
			for (i = 1; i <= n; i++) {
				in = rand() % (20 - 1 + 1) + 1;
				begin = InStack(begin, in);
			}
			if (kod == 1) cout << "Create " << n << endl;
			else cout << "Add " << n << endl;
			break;
		case 3:
			if (!begin) {
				cout << "Stack Pyst!" << endl;
				break;
			}
			cout << "--- Stack ---" << endl;
			View(begin);
			break;
		case 4:
			Del_All(&begin);
			cout << "Memory Free!" << endl;
			break;
		case 5:
			if (!begin)
				cout << "Stack Pyst!" << endl;
			else {
				double Sr = SrAr(begin);
				cout << "Average - " << Sr << endl;
				begin = AddSr(begin, n, Sr);
				//begin = Del(begin, in);
				cout << "Data Add!" << endl;
			}
			break;
		case 0:
			if (begin != NULL)
				Del_All(&begin);
			return;
		default:
			cout << "Error!" << endl;
		}
	}
}

Stack* InStack(Stack  *p, double  in) {
	Stack *t = new Stack;
	t->info = in;
	t->next = p;
	return   t;
}

void View(Stack *p) {
	Stack *t = p;
	if (p == NULL) {
		cout << "Stack Pyst!" << endl;
		return;
	}
	while (t != NULL) {
		cout << t->info << endl;
		t = t->next;
	}
}

Stack* OutStack(Stack *p, double *out) {
	Stack *t = p;
	*out = p->info;
	p = p->next;
	delete t;
	return p;
}

//begin = OutStack ( begin, &out ); 

void  Del_All(Stack  **p) {
	Stack *t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

Stack* AddSr(Stack *b, int n, double Sr)
{
	double  inf, k = 0;
	Stack  *new_b = NULL;
	while (b != NULL) {
		k++;
		b = OutStack(b, &inf);
		new_b = InStack(new_b, inf);
		if (k == (n / 2))
			new_b = InStack(new_b, Sr);
	}
	return  new_b;

}

double SrAr(Stack *t) {
	double sum = 0, k = 0, Sr;
	while (t != NULL) {
		sum += t->info;
		k++;
		t = t->next;
	}
	Sr = sum / k;
	return Sr;
}

void checkNumber(int &number)
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

/*Stack* Del(Stack *b, int in)
{
	double Sr;
	Sr = SrAr(b);
	cout << "Average - " << Sr << endl;
	Stack *t;
	b = InStack(b, in);
	Stack *p = b;
	t = p->next;
	while (t != NULL) {
		if (t->info < Sr) {
			p->next = t->next;
			delete t;
			t = p->next;
		}
		else {
			p = t;
			t = t->next;
		}
	}
	t = b;
	b = b->next;
	delete t;
	return b;
}*/