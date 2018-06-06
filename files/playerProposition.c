#include "../files/playerProposition.h"
#include "../files/definitions.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void analysisOfPlayerProposition(int proposition[], int draw[], int goodPosition[], int wrongPosition[], int correctIndex[])
{
	int copyOfDraw[NUMBER_OF_POSITIONS];
	int i, j, k, l, buffer;

	//kopiowanie wylosowanej sekwencji przez komputer
	for (i = 0; i < NUMBER_OF_POSITIONS; i++)
		copyOfDraw[i] = draw[i];

	//zliczanie dobrych cyfr na dobrych miejscach
	*goodPosition = 0;

	for (j = 0; j < NUMBER_OF_POSITIONS; j++)
	{
		if (proposition[j] == copyOfDraw[j])
		{
			(*goodPosition)++;
			copyOfDraw[j] = proposition[j] = 0;
			correctIndex[j] = 1;
		}
	}

	//zliczanie dobrych cyfr na zlych miejscach
	*wrongPosition = 0;

	for (k = 0; k < NUMBER_OF_POSITIONS; k++)
	{
		buffer = copyOfDraw[k];

		for (l = 0; l < NUMBER_OF_POSITIONS; l++)
		{
			if (proposition[l] != 0 && proposition[l] == buffer)
			{
				(*wrongPosition)++;
				proposition[l] = copyOfDraw[k] = 0;
			}
		}
	}
}

int getAndCheckIfCorrect()
{
	char stringArray[MAX_ARRAY_SIZE];
	int output = 0;
	int length, i;

	fseek(stdin, 0, SEEK_END); //czyszczenie bufora

	fgets(stringArray, sizeof(stringArray), stdin);
	length = strlen(stringArray);

	if (length == NUMBER_OF_POSITIONS + 1) //+1 miejsce ze wzgledu na znak konczacy tablice znakow "\0"
	{
		for (i = 0; i < length - 1; i++)
		{
			if (!isdigit(stringArray[i]) || stringArray[i] == '0')
				return 0;
		}
		output = atoi(stringArray);
	}
	else return 0; //niepoprawna dlugosc

	return output;
}

int getProposition()
{	
	int output = 0;

	printf("Type in your proposition: ");
	output = getAndCheckIfCorrect();

	while (output == 0)
	{
		printf("Wrong input! Type in again: ");
		output = getAndCheckIfCorrect();
	}

	return output;
}

