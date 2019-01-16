// Lab 2(1)
/*
#include "stdafx.h"
#include <iostream>
#include "Combi.h"
int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_ALL, "rus");
char AA[][2]= {"A", "B", "C", "D"};
std::cout<<std::endl<<" - ��������� ��������� ���� ����������� -";
std::cout<<std::endl<<"�������� ���������: ";
std::cout<<"{ "; for (int i = 0; i < sizeof(AA)/2; i++)
std::cout<<AA[i]<<((i< sizeof(AA)/2-1)?", ":" ");
std::cout<<"}";
std::cout<<std::endl<<"��������� ���� ����������� ";
combi::subset s1(sizeof(AA)/2); // �������� ����������
int n = s1.getfirst(); // ������ (������) ������������
while (n >= 0) // ���� ���� ������������
{
std::cout<<std::endl<<"{ ";
for (int i = 0; i < n; i++)
std::cout<<AA[s1.ntx(i)]<<((i< n-1)?", ":" ");
std::cout<<"}"; n = s1.getnext(); // c�������� ������������
};
std::cout<<std::endl<<"�����: " << s1.count()<<std::endl;
system("pause");
return 0;
}
*/




// Lab 2(2)  
/*
#include "stdafx.h"
#include <iostream>
#include "Combi.h"
int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_ALL, "rus");
char  AA[][2] = { "A", "B", "C", "D", "E" };
std::cout << std::endl << " --- ��������� ��������� ---";
std::cout << std::endl << "�������� ���������: ";
std::cout << "{ ";
for (int i = 0; i < sizeof(AA) / 2; i++)
std::cout << AA[i] << ((i< sizeof(AA) / 2 - 1) ? ", " : " ");
std::cout << "}";
std::cout << std::endl << "��������� ��������� ";
combi2::xcombination xc(sizeof(AA) / 2, 3);
std::cout << "�� " << xc.n << " �� " << xc.m;
int  n = xc.getfirst();
while (n >= 0)
{
std::cout << std::endl << xc.nc << ": { ";
for (int i = 0; i < n; i++)
std::cout << AA[xc.ntx(i)] << ((i< n - 1) ? ", " : " ");
std::cout << "}";
n = xc.getnext();
};
std::cout << std::endl << "�����: " << xc.count() << std::endl;
system("pause");
return 0;
}
*/




// Lab 2(3)
/*
#include "stdafx.h"
#include <iostream>
#include "Combi.h"
#include <iomanip>
int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_ALL, "rus");
char  AA[][2] = { "A", "B", "C", "D" };
std::cout << std::endl << " --- ��������� ������������ ---";
std::cout << std::endl << "�������� ���������: ";
std::cout << "{ ";
for (int i = 0; i < sizeof(AA) / 2; i++)
std::cout << AA[i] << ((i< sizeof(AA) / 2 - 1) ? ", " : " ");
std::cout << "}";
std::cout << std::endl << "��������� ������������ ";
combi3::permutation p(sizeof(AA) / 2);
__int64  n = p.getfirst();
while (n >= 0)
{
std::cout << std::endl << std::setw(4) << p.np << ": { ";
for (int i = 0; i < p.n; i++)
std::cout << AA[p.ntx(i)] << ((i< p.n - 1) ? ", " : " ");
std::cout << "}";
n = p.getnext();
};
std::cout << std::endl << "�����: " << p.count() << std::endl;
system("pause");
return 0;
}
*/





// Lab 2(4)
///*
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
void swap(int *a, int i, int j)
{
int s = a[i];
a[i] = a[j];
a[j] = s;
}
bool NextSet(int *a, int n, int m)
{
int j;
do  // ��������� ���� �� ����� ������� ��������� ����������
{
j = n - 1;
while (j != -1 && a[j] >= a[j + 1]) j--;
if (j == -1)
return false; // ������ ���������� ���
int k = n - 1;
while (a[j] >= a[k]) k--;
swap(a, j, k);
int l = j + 1, r = n - 1; // ��������� ���������� ����� ������������������
while (l < r)
swap(a, l++, r--);
} while (j > m - 1);
return true;
}
void Print(int *a, int n)  // ����� ����������
{
static int num = 1; // ����� ����������
cout.width(3); // ������ ���� ������ ������ ����������
cout << num++ << ":  ";
for (int i = 0; i < n; i++)
cout << a[i] << " ";
cout << endl;
}
int main()
{
int n, m, *a;
cout << "N = ";
cin >> n;
cout << "M = ";
cin >> m;
a = new int[n];
for (int i = 0; i < n; i++)
a[i] = i + 1;
Print(a, m);
while (NextSet(a, n, m))
Print(a, m);
cin.get(); cin.get();
return 0;
}
//*/





// Lab 2(5)
/*
#include "stdafx.h"
#include <iostream>
#include "Combi.h"
#include "Knapsack.h"
#include "Auxil.h"  
#include <ctime>

#define N 18
clock_t SS[N];
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	int V = 300,   // ����������� �������              
		v[N],       // ������ �������� ������� ����  
		c[N];       // ��������� �������� ������� ���� 
	short m[N];     // ���������� ��������� ������� ���� {0,1}   
	int maxcc = 0;
	int n = 0;

	auxil::start();
	for (int i = 0; i < N; i++) v[i] = auxil::iget(10, 300);
	for (int i = 0; i < N; i++) c[i] = auxil::iget(5, 50);

	int maxcc1 = knapsack_s(V, N, v, c, m);
	
	std::cout << std::endl << "<<<<< ������ � ������� >>>>>";
	std::cout << std::endl << "- ���������� ��������� : " << N;
	std::cout << std::endl << "- ����������� �������  : " << V;
	std::cout << std::endl << "- ������� ���������    : ";
	for (int i = 0; i < N; i++) std::cout << v[i] << " ";
	std::cout << std::endl << "- ��������� ���������  : ";
	for (int i = 0; i < N; i++) std::cout << v[i] * c[i] << " ";
	std::cout << std::endl << "- ����������� ��������� �������: " << maxcc1;
	std::cout << std::endl << "- ��� �������: ";
	int s = 0; for (int i = 0; i < N; i++) s += m[i] * v[i];
	std::cout << s;
	std::cout << std::endl << "- ������� ��������: ";
	for (int i = 0; i < N; i++) std::cout << " " << m[i];
	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}
*/





// Lab 2(6)
/*
#include "stdafx.h"
#include <iostream>
#include <ctime>
#include "Knapsack.h"
#include "Auxil.h"
#include <locale>
#define N 20

clock_t SS[N];
int _tmain(int argc, _TCHAR* argv[])
{
	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;

	setlocale(LC_ALL, "rus");

	int V = 300,   // ����������� �������              
		v[N],       // ������ �������� ������� ����  
		c[N];       // ��������� �������� ������� ���� 
	short m[N];     // ���������� ��������� ������� ���� {0,1}   
	int maxcc = 0;
	int n = 0;

	auxil::start();
	t1 = clock();
	for (int i = 0; i < N; i++) v[i] = auxil::iget(10, 300);
	for (int i = 0; i < N; i++) c[i] = auxil::iget(5, 50);


	for (int n = 12; n < 21; n++)
	{
		SS[n] = clock();
		maxcc = knapsack_s(V, n, v, c, m); // ���������� �������   
		SS[n] = -(SS[n] - clock());
		t2 = clock();
		std::cout << std::endl << "n = " << n << " " << SS[n];
		std::cout << std::endl << "(���): "<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
		std::cout << std::endl;

	}

	system("pause");
	return 0;
}

*/