#include "drawLots.h"
#include "../files/definitions.h"

#include <stdio.h>

void randomizeNumber(int los[], unsigned int przelacznik) //randomizeNumber kombinacji
{
	srand(time(NULL));

	if (przelacznik == 1) //tryb trudny - liczby sie powtarzaja
	{
		randomRepeatable(los);
	}
	else if (przelacznik == 0) //tryb prosty - liczby sie nie powtarzaja
	{
		randomNonRepeatable(los);
	}
}

void randomRepeatable(int los[])
{
	int i;
	for (i = 0; i < LB_POZ; i++)
	{
		los[i] = 1 + rand() % 9; // wypelnianie tablicy losowymi cyframi od 1 do 9
		printf("%d ", los[i]); //WYPISYWANIE DO USUNIECIA!!!!!
	}
}

void randomNonRepeatable(int los[])
{
	int chk, get, i, c;
	c = i = 0;

	while (c < LB_POZ)
	{
		get = 1 + rand() % 9;

		for (i = 0; i <= c; i++)
		{
			if (los[i] == get)
			{
				chk = 0;
				break;
			}
			else if (los[i] != get)
			{
				chk = 1;
			}
		}
		if (chk == 1)
		{
			los[c] = get;
			printf("%d ", los[c]); //WYPISYWANIE DO USUNIECIA!!!!!
			c++;
		}
	}
}
