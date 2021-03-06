#include "../files/drawLots.h"
#include "../files/definitions.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

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
		// printf("%d ", draw[i]); mozliwosc wyswietlania wygenerowanej kombinacji w celu sprawdzenia poprawnosci dzialania programu
	}
}

void randomNonRepeatable(int draw[])
{
	int temp, get, i, c;
	c = i = 0;

	while (c < NUMBER_OF_POSITIONS)
	{
		get = 1 + rand() % 9; //losowanie cyfr z zakresu 1-9

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
			c++;
			//printf("%d ", draw[c]); mozliwosc wyswietlania wygenerowanej kombinacji w celu sprawdzenia poprawnosci dzialania programu
		}
	}
}
