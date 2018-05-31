#include "../files/playerProposition.h"
#include "../files/definitions.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void analysisOfPlayerProposition(int prop[], int los[], int lk_dw[], int lk_dz[], int indeksOK[])
{////////////////////////////////////////////////////////////               /////
	int losbis[LB_POZ];

	//kopiowanie wylosowanej sekwencji przez komputer
	int i;
	for (i = 0; i < LB_POZ; i++)
		losbis[i] = los[i];

	//zliczanie dobrych cyfr na dobrych miejscach
	*lk_dw = 0;

	int j;
	for (j = 0; j < LB_POZ; j++)
	{
		if (prop[j] == losbis[j])
		{
			(*lk_dw)++;
			losbis[j] = prop[j] = 0;
			indeksOK[j] = 1; //dodane przeze mnie do dzialajacej!!!!!!!!!!!!!!
		}
	}

	//zliczanie dobrych cyfr na zlych miejscach
	int k, l;
	*lk_dz = 0;

	for (k = 0; k < LB_POZ; k++)
	{
		int bufor;
		bufor = losbis[k];

		for (l = 0; l < LB_POZ; l++)
		{
			if (prop[l] != 0 && prop[l] == bufor)
			{
				(*lk_dz)++;
				prop[l] = losbis[k] = 0;
			}
		}
	}
}

int enterProposition()
{
	char stringArray[MAX_ARRAY_SIZE];
	int output, length, i;

	fgets(stringArray, sizeof(stringArray), stdin);
	length = strlen(stringArray);

	if (length == LB_POZ + 1) //+1 miejsce ze wzgledu na znak konczacy tablice znakow "\0"
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
	int output=1;
	printf("Type in your proposition: ");
	output = enterProposition();
	
	if (output == 0)
	{
		while (output == 0)
		{
			printf("Wrong input! Type in again: ");
			output = enterProposition();
		} 
	}

	return output;
}

