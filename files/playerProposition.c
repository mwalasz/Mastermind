#include "../files/playerProposition.h"
#include "../files/definitions.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void analysisOfPlayerProposition(int proposition[], int draw[], int goodPosition[], int wrongPosition[], int correctIndex[])
{
	int copyOfDraw[NUMBER_OF_POSITIONS];
	int i, j, k, l, buffer;

	for (i = 0; i < NUMBER_OF_POSITIONS; i++) //kopiowanie wylosowanej sekwencji przez komputer
		copyOfDraw[i] = draw[i];

	*goodPosition = 0; //zliczanie dobrych cyfr na dobrych miejscach

	for (j = 0; j < NUMBER_OF_POSITIONS; j++)
	{
		if (proposition[j] == copyOfDraw[j]) //jesli skladowa propozycji gracza zgadza sie z losem komputera
		{
			(*goodPosition)++; //inkrementowana jest liczba dobrych pozycji
			copyOfDraw[j] = proposition[j] = 0; //wyzerowanie kazdej z tablic jak zaznaczenie ze to miejsce zostalo sprawdzone
			correctIndex[j] = 1; //zaznaczenie poprawnego indeksu, w celu pozniejszego wyswietlenie go w odpowiednim kolorze
		}
	}

	*wrongPosition = 0; 	//zliczanie dobrych cyfr na zlych miejscach

	for (k = 0; k < NUMBER_OF_POSITIONS; k++)
	{
		buffer = copyOfDraw[k]; //zmienna pomocnicza przechowujaca jeden znak

		for (l = 0; l < NUMBER_OF_POSITIONS; l++)
		{
			if (proposition[l] != 0 && proposition[l] == buffer) //gdy znaleziono cyfre w losie komputera, ktora jest w propozycji gracza
			{//ale znajduje sie ona na zlym miejscu
				(*wrongPosition)++; //inkrementowana jest liczba zlych pozycji
				proposition[l] = copyOfDraw[k] = 0; //wyzerowanie kazdej z tablic jak zaznaczenie ze to miejsce zostalo sprawdzone
			}
		}
	}
}

int getAndCheckIfCorrect(int lengthToCheck)
{
	char stringArray[MAX_ARRAY_SIZE];
	int output = 0;
	int length, i;

	fseek(stdin, 0, SEEK_END); //czyszczenie bufora

	fgets(stringArray, sizeof(stringArray), stdin); //pobranie propozycji do analizy
	length = strlen(stringArray); //odczytanie dlugosci propozycji

	if (length == lengthToCheck + 1) //jesli dlugosc to zadana dlugosc propozycji w programie
	{//+1 miejsce ze wzgledu na znak konczacy tablice znakow "\0"
		for (i = 0; i < length - 1; i++)
		{
			if (!isdigit(stringArray[i]) || stringArray[i] == '0')
					return 0; //jesli napotkano na znak nie bedacy cyfra, lub 0, zwracane jest 0
		}
		output = atoi(stringArray); //jesli w propozycji pojawily sie tylko dozwolone znaki, przeksztalcane jest na int
	}
	else return 0; //niepoprawna dlugosc

	return output;
}

int getProposition()
{	
	int output = 0;

	printf("Type in your proposition: ");
	output = getAndCheckIfCorrect(NUMBER_OF_POSITIONS);

	while (output == 0)
	{
		printf("Wrong input! Type in again: ");
		output = getAndCheckIfCorrect(NUMBER_OF_POSITIONS);
	}

	return output;
}