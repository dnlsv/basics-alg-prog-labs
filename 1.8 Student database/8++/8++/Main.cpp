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

using  namespace std; //����� �������� ������������ ���

Student *arr;
FILE *fst, *ftxt;
int siz = sizeof(Student); //������������ ����� � ������ ���������� ��� ����, ���������� � ������.

const char WAYDAT[] = "D://C++/File.dat";
const char WAYTXT[] = "D://C++/File.txt";
const char WAYSPISOK[] = "D://C++/Spisok.txt";

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
	setlocale(LC_ALL, "rus"); //������ ������

	Student newst;
	FILE *fspis;
	int kod, point, kol, i, numst, dan, count, g = 0, k = 0; /*k - ��� ������������, ������� �� ���� ���� ������  g - ������ �� ����*/
	double fiz, mat, inf, him, sr, pr;
	long len;
	

	//fopen_s(&ftxt, WAYTXT, "w");
	while (1)
	{
		puts("��������: \n1 - ��������\n2 - ���������\n3 - ��������\n4 - �������������� �������\n0 - �����");
		inputNumber(kod);
		g++;
		if (kod != 1 && g == 1)
			while (kod != 1) {
				puts("������� ���������� ������� ����");
				inputNumber(kod);
			}
		switch (kod)
		{
		case 1: //��������

			fopen_s(&fst, WAYDAT, "wb");
			check(fst);
			fclose(fst);
			puts("Create new file\n");
			break;
		case 2: //���������
			puts("\n��������: \n1 - ����������\n2 - ��������������\n3 - ��������\n0 - ���������");
			inputNumber(point);
			switch (point)
			{
			case 1: //����������
				k++;
				fopen_s(&fst, WAYDAT, "ab");
				check(fst);
				printf_s("\n�������:\n-������� � ��������:\n");
				fflush(stdin);
				gets_s(temp.FIO);
				printf_s("-��� ��������(�� 1873 �� 2018):\n");
				count = 2;
				inputData(temp.year, count);
				printf("-����� ������(6-�� ������� ��������):\n");
				count = 3;
				inputData(temp.numgr, count);
				printf_s("-������ �� ������� : �� ������, ����������, �����������, �����(�� 0 �� 10):\n");
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
			case 2: //��������������
				if (k != 0) {
					begin(numst, kol);

					printf("\n����� ������ �� ������ ��������:\n1 - ������� � ��������\n2 - ��� ��������\n3 - ����� ������\n4 - ������ �� �������\n");					
					while (1)
					{
						inputNumber(dan);
						if (dan < 4 && dan>0)
							break;
						else
							puts("������������ ����! ��������� �������!\n");
					}
					printf_s("\n������� ����� ������:\n");
					switch (dan)
					{
					case 1: //������� � �������� 
						printf_s("\n-������� � ��������:\n");
						fflush(stdin);
						gets_s(newst.FIO);
						strcpy_s(arr[numst - 1].FIO, newst.FIO);
						break;
					case 2: //��� ��������
						printf_s("-��� ��������(�� 1873 �� 2018):\n");
						count = 2;
						inputData(newst.year, count);
						arr[numst - 1].year = newst.year;
						break;
					case 3: //����� ������
						printf("-����� ������(6-�� ������� ��������):\n");
						count = 3;
						inputData(newst.numgr, count);
						arr[numst - 1].numgr = newst.numgr;
						break;
					case 4: //������ �� �������
						printf_s("-������ �� ������� : �� ������, ����������, �����������, �����(�� 0 �� 10):\n");
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
						puts("������������ ����! ��������� �������!\n");
					}
					end(kol);
				}
				else
					puts("������������ ����! ��������� �������!\n");
				break;
			case 3: //��������
				if (k != 0) {
					k--;
					begin(numst, kol);
					for (int i = numst - 1; i < kol - 1; i++)
						arr[i] = arr[i + 1];
					kol--;
					end(kol);
				}
				else
					puts("������������ ����! ��������� �������!\n");		
				break;
			case 0: //���������
				break;
			default:
				puts("������������ ����! ��������� �������!\n");
			}

			break;
		case 3: //��������
			view(temp);
			break;
		case 4: //�������������� �������
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
				printf_s("\n����� ������� ���� - %.1f\n", sr);

				fopen_s(&fspis, WAYSPISOK, "w");
				check(fspis);
				for (int i = 0; i < kol; i++)
				{
					if (arr[i].srball >= sr)
						fprintf(fspis, "%s\n", arr[i].FIO);
				}
				fclose(fspis);
				printf_s("\n������ �������� ���� �� ������� ���������, ������� ���� ������� ���� �������� (D://C++/Spisok.txt)\n\n");
			}
			else
				printf_s("\n� ������ ��� �� ������ ��������\n\n");
			break;
		case 0: //�����
			//fclose(ftxt);
			return;
		default:
			puts("������������ ����! ��������� �������!\n");
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
	printf_s("\n\t������ ���������:\n");
	fprintf(ftxt, "������ ���������:\n");
	while (1) {
		if (fread(&t, siz, 1, fst) == 0) break;
		number++;
		printf_s("�%d\n", number);
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
	len = _filelength(_fileno(fst)); //���������� ����� ����� � ������. //���������� ���������� ����� � ��������� ������
	kol = len / siz;
	fclose(fst);
	printf("������� ����� ��������\n");
	while (1)
	{
		inputNumber(numst);
		if (numst <= kol && numst > 0)
			break;
		else
			puts("������������ ����! ��������� �������!\n");
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
	printf_s("\n\t���������� ������ ���������:\n");
	fopen_s(&ftxt, WAYTXT, "w");//TXT
	check(ftxt);
	for (int i = 0; i < kol; i++) {
		printf_s("�%d\n", i + 1);
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
	printf_s("\n��� �������� - %d\n������ - %d", t.year, t.numgr);
	printf_s("\n������:\n������ - %d ���������� - %d ����������� - %d ����� - %d", t.balls[0], t.balls[1], t.balls[2], t.balls[3]);
	printf_s("\n������� ���� - %.1f", t.srball);
	puts("\n");

	fprintf(ftxt, "%s ", t.FIO);
	fprintf(ftxt, "\n��� �������� - %d\n������ - %d", t.year, t.numgr);
	fprintf(ftxt, "\n������:\n������ - %d ���������� - %d ����������� - %d ����� - %d", t.balls[0], t.balls[1], t.balls[2], t.balls[3]);
	fprintf(ftxt, "\n������� ���� - %.1f", t.srball);
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
			cout << "������������ ����! ��������� �������!" << endl;
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
					cout << "������������ ����! ��������� �������!" << endl;
			}
			if (count == 3) {
				if ((data / 100000) < 10 && (data / 100000) >= 1)
					break;
				else
					cout << "������������ ����! ��������� �������!" << endl;
			}
			if (count == 2)
			{
				if (data >= 1873 && data <= 2018)
					break;
				else
					cout << "������������ ����! ��������� �������!" << endl;
			}
		}
		else
			cout << "������������ ����! ��������� �������!" << endl;
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

