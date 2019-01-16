#include "stdafx.h"
#include "Knapsack.h"
#define NINF 0x80000000 
int calcv(combi::subset s, const int v[])  
{
	int rc = 0;
	for (int i = 0; i < s.sn; i++) rc += v[s.ntx(i)];
	return rc;
};
int calcc(combi::subset s, const int v[], const int c[])
{
	int rc = 0;
	for (int i = 0; i < s.sn; i++) rc += (v[s.ntx(i)] * c[s.ntx(i)]);
	return rc;
};
void setm(combi::subset s, short m[]) 
{
	for (int i = 0; i < s.n; i++) m[i] = 0;
	for (int i = 0; i < s.sn; i++) m[s.ntx(i)] = 1;
};
int   knapsack_s(
	int V,    
	short n,   
	const int v[],  
	const int c[],
	short  m[]   
)
{
	combi::subset s(n);
	int maxc = NINF, cc = 0;
	short  ns = s.getfirst();
	while (ns >= 0)
	{
		if (calcv(s, v) <= V)
			if ((cc = calcc(s, v, c)) > maxc)
			{
				maxc = cc;
				setm(s, m);
			}
		ns = s.getnext();
	};
	return maxc;
};