#include "displayInformation.h"
#include "../files/rlutil.h"
#include "../files/definitions.h"

#include <Windows.h>

void displayFinalResults(int draw[], int goodPosition, int wrongPosition, int numberOfTries, int copyOfPropositionArray[], float time)
{
	system("cls");
	if (goodPosition == NUMBER_OF_POSITIONS)
	{
		printf("Victory!\n You made it in ");
		setColor(LIGHTGREEN);
		printf("%d", numberOfTries);
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
		printf("%d", MAX_NUMBER_OF_TRIES);
		setColor(WHITE);
		printf(" unsucessful tries!\n\n");

		printf("Correct positions:      ");
		showGreen(goodPosition);

		printf("\nIncorrect positions:    ");
		showRed(wrongPosition);

		printf("\nNot-matched digits:     ");
		showRed((NUMBER_OF_POSITIONS - wrongPosition - goodPosition));
		printf("\n\n");

		printf("Time spend:              ");
		printf("%.1f seconds\n\n", time);

		printf("Right combination:      ");
		for (i = 0; i < NUMBER_OF_POSITIONS; i++)
		{
			showGreen(draw[i]);
		}

		printf("\nYour proposition:       ");
		for (j = 0; j < NUMBER_OF_POSITIONS; j++)
		{
			printf("|");
			if (draw[j] == copyOfPropositionArray[j])
			{
				setColor(LIGHTGREEN);
				printf(" %d ", copyOfPropositionArray[j]); // wypelnianie tablicy losowymi cyframi od 0 do MAKSIMUM
			}
			else
			{
				setColor(LIGHTRED);
				printf(" %d ", copyOfPropositionArray[j]); // wypelnianie tablicy losowymi cyframi od 0 do MAKSIMUM
			}
			setColor(WHITE);
			printf("|");
		}
		setColor(WHITE);
	}

}

void displayResultsOfRound(int goodPosition, int wrongPosition, int copyOfPropositionArray[], int correctIndex[])
{
	int p;
	system("cls");
	printf("Your proposition:         ");

	for (p = 0; p < NUMBER_OF_POSITIONS; p++)
	{
		if (correctIndex[p] == 1)
		{
			showGreen(copyOfPropositionArray[p]);
		}
		else
		{
			printf("| %d |", copyOfPropositionArray[p]);
		}
	}

	printf("\nCorrect place:            ");
	showGreen(goodPosition);

	printf("\nIncorrect place:          ");
	showRed(wrongPosition);

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

void chooseDifficulty()
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

void displayWarning(int numberOfTries)
{
	if (numberOfTries == MAX_NUMBER_OF_TRIES - 1)
		printf("It is your last chance, try harder!\n\n");
}

void displayTableHeader()
{
	printf("|=======|======|==================|============|===========|======================|========================|\n");
	printf("| RESULT|  LVL |       NAME       |    TIME    |   TRIES   |        CORRECT       |        INCORRECT       |\n");
	printf("|=======|======|==================|============|===========|======================|========================|\n");
}