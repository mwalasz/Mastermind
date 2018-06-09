#include "../files/displayInformation.h"
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

void showDifficultyMenuText()
{
	system("cls");

	printf("GAME\n\nChoose dificulty:\n\n");
	setColor(LIGHTGREEN);
	printf("1 : Easy (numbers cannot repeat)\n");

	setColor(LIGHTRED);
	printf("2 : Hard (numbers may repeat)\n");

	setColor(WHITE);
	printf("3 : Back to main menu\n\n");
	printf("Your choose: ");
}

void displayWarning(int numberOfTries)
{
	if (numberOfTries == MAX_NUMBER_OF_TRIES - 1)
		printf("It is your last chance, try harder!\n\n");
}

void displayTableHeader()
{
	printf("========|======|==================|=============|===========|======================|========================\n");
	printf("  RESULT|  LVL |       NAME       |     TIME    |   TRIES   |        CORRECT       |        INCORRECT       \n");
	printf("========|======|==================|=============|===========|======================|========================\n");
}

void showGreeting()
{
	system("cls");

	printf(" _____________________________________________________\n");
	printf("/           _    ___  ___  __  __         .      ___  \\ \n");
	printf("|  |\\  /|  /_\\  /___   |  |__  |_\\ |\\  /| | |\\ | |  \\ | \n");
	printf("|  | \\/ | |   | ___/   |  |__  | \\ | \\/ | | | \\| |__/ | \n");
	printf("\\_____________________________________________________/ \n");

	Sleep(1500);
}

void endOfProgram(const char* name)
{
	system("cls");
	printf("Thanks for the game! Goodbye %s!", name);
}

void showStatisticsMenuText()
{
	system("cls");
	printf("STATISTICS\n\nChoose what action do you want to perform:\n\n1 : show defeats\n2 : show victories\n3 : show everything\n4 : back to menu");
	printf("\n\nYour choose: ");
}

void showMainMenuText()
{
	system("cls");
	printf("Choose: \n\n1 : Play game\n2 : Statistics\n3 : Help\n4 : Quit\n\nYour choose: ");
}

void showMenuAfterGameText()
{
	Sleep(1500);
	printf("\n\n1 : Play again\n2 : Back to menu\n3 : Exit the game\n\nYour choose: ");
}

void newGameComunicate()
{
	system("cls");
	printf("New game!");
	Sleep(1000);
	system("cls");
}

void showHelp()
{
	system("cls");
	printf("HELP");
	printf("\n\nWhen you run program with '-h' flag, you will first see help and then program will start normally.\n");
	printf("When you run program with '-a' flag, you will first see author of the program and then program will start normally.\n");
	printf("\nIn main menu you can perform 4 actions: play a game, display all-time results, show help or turn off the program.\n");
	printf("\nGAME - click '1'\n");
	printf("You have 2 possible options: easy level (digits cannot repeat) or hard level (digits can repeat).\n");
	printf("To choose EASY level - press '1' and ENTER.\n");
	printf("To choose HARD level - press '2' and ENTER.\n");
	printf("\nSTATISTICS - click '2'\n");
	printf("You have 3 possible options: show only losses, show only victories or show everything.\n");
	printf("To choose DEFEATS level - press '1' and ENTER.\n");
	printf("To choose VICTORIES level - press '2' and ENTER.\n");
	printf("To choose EVERYTHING level - press '3' and ENTER.\n");
	printf("\nHELP - click '3'\n");
	printf("On the screen will appear comunicate, how to use program.\n");
	printf("\nQUIT - click '4'\n");
	printf("The program will shut down.");
	printf("\n\nIn every possible menu, always the last option is return to main menu.");
}

void showAuthor()
{
	system("cls");
	printf("Author of the program:\n\nMateusz Walasz,\nSilesian University of Technology,\nfaculty: Computer Science.");
}