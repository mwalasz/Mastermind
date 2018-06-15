#include "../files/additional.h"
#include "../files/definitions.h"
#include "../files/playerProposition.h"
#include "../files/displayInformation.h"

#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void takeParameter(int argc, char* argv[])
{
	if (argc == 2)
	{
		if (!strcmp(argv[1],"-h")) //jesli przekazany argument to "-h" wyswietlana jest pomoc
		{
			showHelp();
			returnToMenu();
		}
		else if (!strcmp(argv[1], "-a")) //jesli przekazany argument to "-a" wyswietlana jest informacja o tworcy
		{
			showAuthor();
			returnToMenu();
		}
		else  //jesli bledny argument, program wyswietla komunikat o bledzie
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
	char * playerName = malloc(NAME_LENGTH * sizeof(char)); //zarezerwowanie pamieci na imie gracza

	printf("Enter your name: ");
	scanf("%s", playerName); //pobranie imienia

	return playerName;
}

unsigned int returnCheckedCorrectSwitchVariable(unsigned int variableToCheck)
{
	variableToCheck = getAndCheckIfCorrect(1); //zmienna ktorej nalezy sprawdzic poprawnosc
	while (variableToCheck == 0) //dopoki nie bedzie poprawna, wymagane bedzie ponowne wprowadzenie
	{
		printf("Wrong input! Type in again: ");
		variableToCheck = getAndCheckIfCorrect(1);
	}

	return variableToCheck; //zwrocenie poprawnej zmiennej
}