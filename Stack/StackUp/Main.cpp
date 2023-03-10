#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <ctime>

using namespace std;

struct Stack {
	int info;
	Stack * next;
};

Stack* InStack(Stack*, int);
void View(Stack*);
void Del_All(Stack **);
double SrAr(Stack  *);
Stack* Del(Stack *, int, int&);
void Sort_p(Stack **);
void Sort_info(Stack *);
void checkNumber(int &);

int main() {
	setlocale(LC_ALL, ".UTF8");
	int i, in, n, kod, count;
	Stack *begin = 0;
	cout << "-------Stack-------" << endl;
	while (true) {
		cout << endl << "1 - Create." << endl << "2 - Add." << endl << "3 - View." << endl << "4 - Del." << endl << "5 - Task." 
			<< endl << "6 - Sort Address." << endl << "7 - Sort Info." << endl << "0 - EXIT." << endl;
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
				in = rand() % (20 + 20 + 1) - 20; // (-20;20)
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
				count = 0;
				begin = Del(begin, in, count);
				cout << "Less Average: " << count << endl;
				if (count != 0)
					cout << "Users Removed!" << endl;
			}
			break;
		case 6:
			if (!begin)
				cout << "Stack Pyst!" << endl;
			else {
				Sort_p(&begin);
				cout << "Stack Sorted!" << endl;
			}
			break;
		case 7:
			if (!begin)
				cout << "Stack Pyst!" << endl;
			else {
				Sort_info(begin);
				cout << "Stack Sorted!" << endl;
			}
			break;
		case 0:
			if (begin != NULL)
				Del_All(&begin);
			return 0;
		default:
			cout << "Error!" << endl;
		}
	}
}

Stack* InStack(Stack  *p, int  in) {
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

void  Del_All(Stack  **p) {
	Stack *t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

Stack* Del(Stack *b, int in, int &count)
{
	double Sr;
	Sr = SrAr(b);
	cout << "Average: " << Sr << endl;
	Stack *t;
	b = InStack(b, in);	    
	Stack *p = b;
	t = p->next;	           
	while (t != NULL) {
		if (t->info < Sr) {
			count++;
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

void Sort_p(Stack **p) {
	Stack *t = NULL, *t1, *r;
	if ((*p)->next->next == NULL) return;
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
			if (t1->next->info > t1->next->next->info) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*p)->next->next != t);
}

void Sort_info(Stack *p) {
	Stack *t = NULL, *t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (p->next != t);
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