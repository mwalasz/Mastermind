#include "../files/playerProposition.h"
#include "../files/definitions.h"

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
	int wejscie;
	unsigned int poprawnosc = 0;

	printf("Type in your proposition: ");
	scanf("%d", &wejscie);

	while (poprawnosc == 0) //sprawdzenie poprawnosci propozycji gracza
	{
		if (wejscie > 100000 || wejscie <= 11110)
		{
			printf("Wrong input! Try again: ");
			scanf("%d", &wejscie);
			poprawnosc = 0; //blad
		}
		else poprawnosc = 1; //poprawne wejsci
	}
	return wejscie;
}
