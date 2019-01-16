// Knapsack.h      
#pragma once 
#include "Combi.h"

int   knapsack_s (
	int V,         // вместимость рюкзака 
	short n,       // количество типов предметов 
	const int v[], // размер предмета каждого типа  
	const int c[], // стоимость предмета каждого типа     
	short m[]      // количество предметов каждого типа  
);