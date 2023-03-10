#include <iostream>
#include <string>

using namespace std;

struct  Tree {
	int   info;
	string str;
	Tree* left, * right;
};

Tree* Create(Tree*);
Tree* List(int, string);
void Add_List(Tree*, int, string, int&);
void View(Tree*, int);
Tree* Del(Tree*, int);
void Del_All(Tree**);
Tree* P_Key(Tree*);
void Make_Blns(Tree**, int, int, int*, string*);
void Balans(Tree*, int);
void Rec(Tree*, int*, int&);
void Res(Tree*, string*, int&);
void P_Rec(Tree*, Tree**, int, int&);
void preOrder(Tree*, int);
void postOrder(Tree*, int);
void inOrder(Tree*, int);
void Task(Tree*, int&);
void checkNumber(int&);
void Check(Tree*, int, int&);

int main() {
	setlocale(LC_ALL, ".UTF8");
	Tree* root = 0, * p_key;
	int in, kod, key, k = 0, point, count, flag;
	string st;
	cout << "\tTree";

	while (1) {
		cout << endl << "1 - Создание" << endl << "2 - Добавление" << endl << "3 - Просмотр" << endl
			<< "4 - Поиск" << endl << "5 - Удаление" << endl << "6 - Балансировка" << endl
			<< "7 - Сортировка" << endl << "8 - Освободить память" << endl << "9 - Индивидуальное задание" << endl
			<< "0 - Выход" << endl;
		while (1) {
			checkNumber(kod);
			if (k != 0)
				break;
			if (kod == 1 && k == 0)
				break;
			else {
				if (kod == 0)
					break;
				if (kod != 1)
					cout << endl << "Error!" << endl << "Сначала необходимо создать дерево" << endl;
			}
		}
		cout << endl;
		switch (kod) {
		case 1:
			k++;
			root = Create(root);
			break;
		case 2:
			cout << "Input info" << endl;
			cout << "Key: ";
			checkNumber(in);
			cout << "Text: ";
			cin >> st;
			Add_List(root, in, st, k);
			break;
		case 3:
			if (root != 0) {
				cout << "\tTree" << endl;
				View(root, 0);
			}
			else
				cout << "Tree free" << endl;
			break;
		case 4:
			p_key = P_Key(root);
			cout << endl << "\tResult" << endl;
			View(p_key, 0);
			break;
		case 5:
			k--;
			while (1) {
				flag = 0;
				cout << " Input Del Info : ";
				checkNumber(key);
				Check(root, key, flag);
				if (flag == 1)
					break;
				else
					cout << endl << "Error!" << endl << "Такого ключа нет" << endl << endl;;
			}
			root = Del(root, key);
			break;
		case 6:
			Balans(root, k);
			break;
		case 7:
			cout << "1 - Прямой обход" << endl << "2 - Обратный обход" << endl
				<< "3 - Обход в порядке возрастания ключа" << endl;
			while (1) {
				checkNumber(point);
				if (point == 1 || point == 2 || point == 3)
					break;
				else
					cout << endl << "Error!" << endl;
			}
			switch (point) {
			case 1:
				cout << endl << "\tПрямой обход" << endl;
				preOrder(root, 0);
				break;
			case 2:
				cout << endl << "\tОбратный обход" << endl;
				postOrder(root, 0);
				break;
			case 3:
				cout << endl << "\tОбход в порядке возрастания ключа" << endl;
				inOrder(root, 0);
				break;
			default:
				cout << "Error!" << endl;
			}
			break;
		case 8:
			k = 0;
			Del_All(&root);
			root = NULL;
			cout << "Memory Free" << endl;
			break;
		case 9:
			count = 0;
			Task(root, count);
			cout << "Число узлов в дереве, у которых есть две дочери - " << count << endl;
			break;
		case 0:
			return 0;
		default:
			cout << "Error!" << endl;
		}
	}
	system("pause");
}

Tree* List(int i, string s)
{
	Tree* t = new Tree;
	t->info = i; // 
	t->str = s;
	t->left = t->right = NULL;
	return t;
}

Tree* Create(Tree* root) {
	int i;
	string s;
	if (!root) { // Если дерево не создано
		cout << " Input Root" << endl;
		cout << "Key: ";
		checkNumber(i);
		cout << "Text: ";
		cin >> s;
		root = List(i, s); //Создаем адрес корня root, который первоначально – лист				
	}
	else
		cout << "Error!" << endl << "Дерево уже создано. Сначала необходимо освободить память" << endl;
	return root;
}

void Add_List(Tree* root, int key, string st, int& k)
{
	Tree* prev = 0, * t;
	bool find = true; // int find = 1;
	t = root;
	while (t && find) {
		prev = t;
		if (key == t->info) {
			find = false; // find = 0;
			cout << "Такой уже есть !" << endl;
		}
		else
			if (key < t->info)
				t = t->left;
			else
				t = t->right;
	}
	if (find) {
		k++;
		t = List(key, st);
		if (key < prev->info)
			prev->left = t;
		else
			prev->right = t;
	}
}

void View(Tree* t, int level)
{
	if (t) {
		View(t->right, level + 1); // Вывод узлов правого поддерева
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << t->info << "" << t->str << endl;
		View(t->left, level + 1); // Вывод узлов левого поддерева
	}
}

Tree* P_Key(Tree* root) {
	Tree* p = root, * t = NULL;
	int key, flag;
	while (1) {
		flag = 0;
		cout << "Input Key" << endl;
		checkNumber(key);
		P_Rec(p, &t, key, flag);
		if (flag == 1)
			break;
		else
			cout << endl << "Error!" << endl << "Такого ключа нет" << endl << endl;;
	}
	return t;
}

void P_Rec(Tree* p, Tree** t, int key, int& flag)
{
	if (p) {
		P_Rec(p->right, t, key, flag);
		if (p->info == key) {
			*t = p;
			flag = 1;
		}
		P_Rec(p->left, t, key, flag);
	}
}

Tree* Del(Tree* root, int key) {
	Tree* Del, * Prev_Del, * R, * Prev_R;
	/*
	Del, Prev_Del – удаляемый элемент и его предыдущий (родитель); R, Prev_R – элемент, на который заменяется удаленный, и его родитель; */
	Del = root;
	Prev_Del = NULL;
	// Поиск удаляемого элемента и его родителя
	while (Del != NULL && Del->info != key) {
		Prev_Del = Del;
		if (Del->info > key) Del = Del->left;
		else Del = Del->right;
	}
	if (Del == NULL) { // Элемент не найден
		cout << "\n NO Key!" << endl;
		return root;
	}
	// --------- Поиск элемента R для замены ---------
	if (Del->right == NULL) R = Del->left;
	else
		if (Del->left == NULL) R = Del->right;
		else {
			// Ищем самый правый узел в левом поддереве
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
			/* Нашли элемент для замены R и его родителя
			Prev_R */
			if (Prev_R == Del)
				R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == root)
		root = R; // Удаляя корень, заменяем его на R
	else
		/* Поддерево R присоединяем к родителю удаляемого узла */
		if (Del->info < Prev_Del->info)
			Prev_Del->left = R;	// На левую ветвь
		else
			Prev_Del->right = R; // На правую
	cout << " Delete " << Del->info << endl;
	delete Del;
	return root;
}

void Balans(Tree* t, int k)
{
	//Tree *t = root;
	int j, l = 0, d = 0, tmp;
	string tmr;
	int* a = new int[k];
	string* s = new string[k];
	Rec(t, a, l);
	for (int i = 0; i < l - 1; i++)
		for (j = i + 1; j < l; j++)
			if (a[j] < a[i]) {
				tmp = a[j];
				a[j] = a[i];
				a[i] = tmp;
			}
	Res(t, s, d);
	for (int i = 0; i < d - 1; i++) {
		tmr = s[d - 1];
		s[d - 1] = s[i];
		s[i] = tmr;
		d--;
	}
	Make_Blns(&t, 0, k, a, s);
	delete[] a;
	delete[] s;
	cout << "\tResult" << endl;
	View(t, 0);
}

void Rec(Tree* t, int* a, int& l) {
	if (t) {
		Rec(t->right, a, l);
		a[l++] = t->info;
		Rec(t->left, a, l);
	}
}

void Res(Tree* t, string* s, int& d) {
	if (t) {
		Res(t->right, s, d);
		s[d++] = t->str;
		Res(t->left, s, d);
	}
}

void Make_Blns(Tree** p, int n, int k, int* a, string* s)

{
	if (n == k) {
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new Tree;
		(*p)->info = a[m];
		(*p)->str = s[m];
		Make_Blns(&(*p)->left, n, m, a, s);
		Make_Blns(&(*p)->right, m + 1, k, a, s);
	}
}

void Del_All(Tree** t) {
	if (*t) {
		Del_All(&(*t)->left);
		Del_All(&(*t)->right);
		delete* t;
	}
}

void preOrder(Tree* t, int level)
{
	if (t) {
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << t->info << "" << t->str << endl;
		preOrder(t->right, level + 1);
		preOrder(t->left, level + 1);
	}
}

void postOrder(Tree* t, int level)
{
	if (t) {
		postOrder(t->right, level + 1);
		postOrder(t->left, level + 1);
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << t->info << "" << t->str << endl;
	}
}

void inOrder(Tree* t, int level)
{
	if (t) {
		inOrder(t->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << t->info << "" << t->str << endl;
		inOrder(t->left, level + 1);
	}
}

void Task(Tree* t, int& count) {
	if (t) {
		Task(t->right, count);
		if (t->right && t->left)
			count++;
		Task(t->left, count);
	}
}

void checkNumber(int& number)
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

void Check(Tree* t, int p, int& flag)
{
	if (t) {
		Check(t->right, p, flag);
		if (p == t->info)
			flag = 1;
		Check(t->left, p, flag);
	}
}




/*p = root;
	while (p->left != NULL) {
		if (p->info == key)
			return p;
		p = p->left; // p = p -> right;
	}
	p = root;
	while (p->right != NULL) {
		if (p->info == key)
			return p;
		p = p->right; // p = p -> right;
	}
	return 0;*/

	/*a[l++] = t->info;
		if (t->left)  B(t->left, a, l);
		if (t->right) B(t->right, a, l);*/

		/*
		Tree *p = root;
			int key;
			cin >> key;
			if (p->info < key){
				while (p->left != NULL) {
					if (p->info == key)
						break;
					p = p->left;
				}
			}
			else {
				while (p->right != NULL) {
					if (p->info == key)
						break;
					p = p->right;
				}
			}
			return p;
		*/


		/*//---------- Добавление элементов -----------
		int find;
		Tree *Prev = 0, *t; // Prev – родитель текущего элемента
		while (1) { //  while (true)
			cout << "Input Info:" << endl;
			cout << "Key - ";
			cin >> i;
			cout << "Text - ";
			cin >> s;
			if (i < 0) break; // Признак выхода – отрицательное число
			t = root; // Текущий указатель установили на корень
			find = 0; // Признак поиска
			while (t && !find) {
				Prev = t;
				if (i == t->info)
					find = 1;
				// Ключи должны быть уникальны
				else
					if (i < t->info) t = t->left;
					else   t = t->right;
			}
			// Если нашли место с адресом Prev
			if (!find) { //  if (find == 0)
				t = List(i, s); // Создаем новый узел, являющийся листом
				if (i < Prev->info) // и присоединяем его, либо
					Prev->left = t; // на левую ветвь,
				else    Prev->right = t; // либо на правую ветвь
			}
			break;
		}	 		// Конец цикла while ( 1 )
		*/

		/*
		struct  Tree {
			int   info;
			Tree  *left, *right;
		};

		Tree* List(int inf) {
			Tree *t = new Tree;		// Захват памяти
			t->info = inf;			// Формирование информационной части
			t->left = t->right = NULL;	// Формирование адресных частей
			return t;				// Возврат созданного указателя
		}

		//1. Первоначально(root = NULL) создаем корень(первый лист дерева) :
			//root = List(StrToInt(Edit1->Text));
		//2. Иначе(root != NULL) добавляем информацию(key) в нужное место :

		void Add_List(Tree *root, int key) {
			Tree *prev, *t;			// prev – указатель предка нового ли-ста
			bool find = true;
			t = root;
			while (t && find) {
				prev = t;
				if (key == t->info) {
					find = false;	 	// Ключ должен быть уникален
					cout << "Dublucate Key!" << endl;
				}
				else
					if (key < t->info) t = t->left;
					else   t = t->right;
			}
			if (find) {					// Нашли нужное место
				t = List(key);			// Создаем новый лист
				if (key < prev->info) prev->left = t;
				else    prev->right = t;
			}
		}

		//Функция просмотра элементов дерева
		void View_Tree(Tree *p, int level) {
			string str;
			if (p) {
				View_Tree(p->right, level + 1);		// Правое поддерево
				for (int i = 0; i < level; i++)
					str = str + "    ";
				//Form1->Memo1->Lines->Add(str + IntToStr(p->info));
				View_Tree(p->left, level + 1); 			// Левое поддерево
			}
		}
		*/

