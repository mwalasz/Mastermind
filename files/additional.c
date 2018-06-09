#include "../files/additional.h"
#include "../files/definitions.h"

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

int * convertNumberToArray(unsigned int number)
{
	unsigned int length = (int)(log10((float)number)) + 1;

	int * array = (int *)malloc(length * sizeof(int)), *curr = array;
	do
	{
		*curr++ = number % 10;
		number /= 10;
	} while (number != 0);

	for (int i = 0; i < 3; i++)
	{
		int * temp = array[i];
		array[i] = array[5 - i - 1];
		array[5 - i - 1] = temp;
	}
	return array;
}

void returnToMenu()
{
	printf("\n\nPress any key.");
	_getch();
}

void showHelp()
{
	system("cls");
	printf("HELP");
	printf("\n\nWhen you run program with '-h' flag, you will first see help and then program will start normally.\n");
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

void takeParameter(int argc, char* argv[])
{
	if (argc == 2)
	{
		if (!strcmp(argv[1],"-h")) //wywolanie pomocy
		{
			showHelp();
			returnToMenu();
		}
		else
		{
			system("cls");
			printf("Incorrect parameters.\nTo launch game normally, press any key.");
			_getch();
		}
	}
}

char * enterName()
{
	system("cls");
	char * playerName = malloc(NAME_LENGTH * sizeof(char));

	printf("Enter your name: ");
	scanf("%s", playerName);

	return playerName;
}

int returnCheckedCorrectSwitchVariable(int variableToCheck)
{
	variableToCheck = getAndCheckIfCorrect(1);
	while (variableToCheck == 0)
	{
		printf("Wrong input! Type in again: ");
		variableToCheck = getAndCheckIfCorrect(1);
	}

	return variableToCheck;
}

void newGameComunicate()
{
	system("cls");
	printf("New game!");
	Sleep(1000);
	system("cls");
}
