#include "displayInformation.h"
#include "../files/rlutil.h"
#include "../files/definitions.h"

#include <Windows.h>

void wyswietlanieWynikowKoncowych(int los[], int lk_dw, int lk_dz, int lk_pr, int propozycjaTabKopia[], float time)
{
	system("cls");
	if (lk_dw == LB_POZ)
	{
		printf("Victory!\n You made it in ");
		setColor(LIGHTGREEN);
		printf("%d", lk_pr);
		setColor(WHITE);
		printf(" tries!\n\n");

		printf("Time spend: ");
		printf("%.1f seconds\n\n", time);
	}
	else
	{
		int i, j;
		printf("Defeat!\n You have made ");
		setColor(LIGHTRED);
		printf("%d", MAX_PROB);
		setColor(WHITE);
		printf(" unsucessful tries!\n\n");

		printf("Correct positions:      ");
		showGreen(lk_dw);

		printf("\nIncorret positions:     ");
		showRed(lk_dz);

		printf("\nNot-matched digits:     ");
		showRed((LB_POZ - lk_dz - lk_dw));
		printf("\n\n");

		printf("Time spend:              ");
		printf("%.1f seconds\n\n", time);

		printf("Right combination:      ");
		for (i = 0; i < LB_POZ; i++)
		{
			showGreen(los[i]);
		}

		printf("\nYour proposition:       ");
		for (j = 0; j < LB_POZ; j++)
		{
			printf("|");
			if (los[j] == propozycjaTabKopia[j])
			{
				setColor(LIGHTGREEN);
				printf(" %d ", propozycjaTabKopia[j]); // wypelnianie tablicy losowymi cyframi od 0 do MAKSIMUM
			}
			else
			{
				setColor(LIGHTRED);
				printf(" %d ", propozycjaTabKopia[j]); // wypelnianie tablicy losowymi cyframi od 0 do MAKSIMUM
			}
			setColor(WHITE);
			printf("|");
		}
		setColor(WHITE);
	}

}

void wyswietlanieWynikowRundy(int lk_dw, int lk_dz, int propozycjaTabKopia[], int indeksOK[])
{
	system("cls");
	printf("Your proposition:         ");

	for (int p = 0; p < LB_POZ; p++)
	{
		if (indeksOK[p] == 1)
		{
			showGreen(propozycjaTabKopia[p]);
		}
		else
		{
			printf("| %d |", propozycjaTabKopia[p]);
		}
	}

	printf("\nCorrect place:            ");
	showGreen(lk_dw);

	printf("\nIncorrect place:          ");
	showRed(lk_dz);

	printf("\n\n");
}

void showRed(int show)
{
	printf("|");
	setColor(LIGHTRED);
	printf(" %d ", show);
	setColor(WHITE);
	printf("|");
}

void showGreen(int show)
{
	printf("|");
	setColor(LIGHTGREEN);
	printf(" %d ", show);
	setColor(WHITE);
	printf("|");
}

void chooseDificulty()
{
	system("cls");

	printf("Choose dificulty:\n\n");
	setColor(LIGHTGREEN);
	printf("0 : Easy (numbers cannot repeat)\n");

	setColor(LIGHTRED);
	printf("1 : Hard (numbers may repeat)\n");

	setColor(WHITE);
	printf("\nYour choose: ");
}
