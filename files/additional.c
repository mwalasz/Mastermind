#include "../files/additional.h"

#include <stdio.h>
#include <stdlib.h>

int * convertNumberToArray(unsigned int number)
{
	unsigned int length = (int)(log10((float)number)) + 1;

	int * arr = (int *)malloc(length * sizeof(int)), *curr = arr;
	do
	{
		*curr++ = number % 10;
		number /= 10;
	} while (number != 0);

	for (int i = 0; i < 3; i++)
	{
		int * pom = arr[i];
		arr[i] = arr[5 - i - 1];
		arr[5 - i - 1] = pom;
	}
	return arr;
}

void returnToMenu()
{
	printf("\n\nPress any to return to menu.");
	_getch();
}

void showMenu()
{
	printf(" _____________________________________________________\n");
	printf("/           _    ___  ___  __  __         .      ___  \\ \n");
	printf("|  |\\  /|  /_\\  /___   |  |__  |_\\ |\\  /| | |\\ | |  \\ | \n");
	printf("|  | \\/ | |   | ___/   |  |__  | \\ | \\/ | | | \\| |__/ | \n");
	printf("\\_____________________________________________________/ \n");
}