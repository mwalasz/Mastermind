#include "../files/additional.h"

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
	printf("\n\nPress any to return to menu.");
	_getch();
}

void showGreeting()
{
	printf(" _____________________________________________________\n");
	printf("/           _    ___  ___  __  __         .      ___  \\ \n");
	printf("|  |\\  /|  /_\\  /___   |  |__  |_\\ |\\  /| | |\\ | |  \\ | \n");
	printf("|  | \\/ | |   | ___/   |  |__  | \\ | \\/ | | | \\| |__/ | \n");
	printf("\\_____________________________________________________/ \n");
}


void endOfProgram(const char* name)
{
	system("cls");
	printf("Thanks for the game! Goodbye %s!", name);
}
