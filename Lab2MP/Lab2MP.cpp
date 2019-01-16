// Lab 2(1)
/*
#include "stdafx.h"
#include <iostream>
#include "Combi.h"
int _tmain(int argc, _TCHAR* argv[])
{
setlocale(LC_ALL, "rus");
char AA[][2]= {"A", "B", "C", "D"};
std::cout<<std::endl<<" - Генератор множества всех подмножеств -";
std::cout<<std::endl<<"Исходное множество: ";
std::cout<<"{ "; for (int i = 0; i < sizeof(AA)/2; i++)
std::cout<<AA[i]<<((i< sizeof(AA)/2-1)?", ":" ");
std::cout<<"}";
std::cout<<std::endl<<"Генерация всех подмножеств ";
combi::subset s1(sizeof(AA)/2); // создание генератора
int n = s1.getfirst(); // первое (пустое) подмножество
while (n >= 0) // пока есть подмножества
{
std::cout<<std::endl<<"{ ";
for (int i = 0; i < n; i++)
std::cout<<AA[s1.ntx(i)]<<((i< n-1)?", ":" ");
std::cout<<"}"; n = s1.getnext(); // cледующее подмножество
};
std::cout<<std::endl<<"всего: " << s1.count()<<std::endl;
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
std::cout << std::endl << " --- Генератор сочетаний ---";
std::cout << std::endl << "Исходное множество: ";
std::cout << "{ ";
for (int i = 0; i < sizeof(AA) / 2; i++)
std::cout << AA[i] << ((i< sizeof(AA) / 2 - 1) ? ", " : " ");
std::cout << "}";
std::cout << std::endl << "Генерация сочетаний ";
combi2::xcombination xc(sizeof(AA) / 2, 3);
std::cout << "из " << xc.n << " по " << xc.m;
int  n = xc.getfirst();
while (n >= 0)
{
std::cout << std::endl << xc.nc << ": { ";
for (int i = 0; i < n; i++)
std::cout << AA[xc.ntx(i)] << ((i< n - 1) ? ", " : " ");
std::cout << "}";
n = xc.getnext();
};
std::cout << std::endl << "всего: " << xc.count() << std::endl;
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
std::cout << std::endl << " --- Генератор перестановок ---";
std::cout << std::endl << "Исходное множество: ";
std::cout << "{ ";
for (int i = 0; i < sizeof(AA) / 2; i++)
std::cout << AA[i] << ((i< sizeof(AA) / 2 - 1) ? ", " : " ");
std::cout << "}";
std::cout << std::endl << "Генерация перестановок ";
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
std::cout << std::endl << "всего: " << p.count() << std::endl;
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
do  // повторяем пока не будет найдено следующее размещение
{
j = n - 1;
while (j != -1 && a[j] >= a[j + 1]) j--;
if (j == -1)
return false; // больше размещений нет
int k = n - 1;
while (a[j] >= a[k]) k--;
swap(a, j, k);
int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
while (l < r)
swap(a, l++, r--);
} while (j > m - 1);
return true;
}
void Print(int *a, int n)  // вывод размещения
{
static int num = 1; // номер размещения
cout.width(3); // ширина поля вывода номера размещения
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

	int V = 300,   // вместимость рюкзака              
		v[N],       // размер предмета каждого типа  
		c[N];       // стоимость предмета каждого типа 
	short m[N];     // количество предметов каждого типа {0,1}   
	int maxcc = 0;
	int n = 0;

	auxil::start();
	for (int i = 0; i < N; i++) v[i] = auxil::iget(10, 300);
	for (int i = 0; i < N; i++) c[i] = auxil::iget(5, 50);

	int maxcc1 = knapsack_s(V, N, v, c, m);
	
	std::cout << std::endl << "<<<<< Задача о рюкзаке >>>>>";
	std::cout << std::endl << "- количество предметов : " << N;
	std::cout << std::endl << "- вместимость рюкзака  : " << V;
	std::cout << std::endl << "- размеры предметов    : ";
	for (int i = 0; i < N; i++) std::cout << v[i] << " ";
	std::cout << std::endl << "- стоимости предметов  : ";
	for (int i = 0; i < N; i++) std::cout << v[i] * c[i] << " ";
	std::cout << std::endl << "- оптимальная стоимость рюкзака: " << maxcc1;
	std::cout << std::endl << "- вес рюкзака: ";
	int s = 0; for (int i = 0; i < N; i++) s += m[i] * v[i];
	std::cout << s;
	std::cout << std::endl << "- выбраны предметы: ";
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

	int V = 300,   // вместимость рюкзака              
		v[N],       // размер предмета каждого типа  
		c[N];       // стоимость предмета каждого типа 
	short m[N];     // количество предметов каждого типа {0,1}   
	int maxcc = 0;
	int n = 0;

	auxil::start();
	t1 = clock();
	for (int i = 0; i < N; i++) v[i] = auxil::iget(10, 300);
	for (int i = 0; i < N; i++) c[i] = auxil::iget(5, 50);


	for (int n = 12; n < 21; n++)
	{
		SS[n] = clock();
		maxcc = knapsack_s(V, n, v, c, m); // измеряемая функция   
		SS[n] = -(SS[n] - clock());
		t2 = clock();
		std::cout << std::endl << "n = " << n << " " << SS[n];
		std::cout << std::endl << "(сек): "<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
		std::cout << std::endl;

	}

	system("pause");
	return 0;
}

*/