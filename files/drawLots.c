#include "drawLots.h"
#include "../files/definitions.h"

#include <stdio.h>

void randomizeNumber(int draw[], unsigned int switchOfFunction) //randomizeNumber kombinacji
{
	srand(time(NULL));

	if (switchOfFunction == 1) //tryb trudny - liczby sie powtarzaja
	{
		randomRepeatable(draw);
	}
	else if (switchOfFunction == 0) //tryb prosty - liczby sie nie powtarzaja
	{
		randomNonRepeatable(draw);
	}
}

void randomRepeatable(int draw[])
{
	int i;
	for (i = 0; i < NUMBER_OF_POSITIONS; i++)
	{
		draw[i] = 1 + rand() % 9; // wypelnianie tablicy losowymi cyframi od 1 do 9
		printf("%d ", draw[i]); //WYPISYWANIE DO USUNIECIA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
}

void randomNonRepeatable(int draw[])
{
	int temp, get, i, c;
	c = i = 0;

	while (c < NUMBER_OF_POSITIONS)
	{
		get = 1 + rand() % 9;

		for (i = 0; i <= c; i++)
		{
			if (draw[i] == get)
			{
				temp = 0;
				break;
			}
			else if (draw[i] != get)
				temp = 1;
		}
		if (temp == 1)
		{
			draw[c] = get;
			printf("%d ", draw[c]); //WYPISYWANIE DO USUNIECIA!!!!!!!!!!!!!!!!!!!!!!!!!!!
			c++;
		}
	}
}
