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
	printf("Help\n\n\nHere will appear some tips.");
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
