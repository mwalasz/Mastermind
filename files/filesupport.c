#include "fileSupport.h"

#include <stdio.h>
#include <string.h>

void saveToFile(float time, const char* name, int goodPosition, int wrongPosition, int numberOfTries, unsigned int finalResult, unsigned int choosedLevel)
{
	FILE *results;
	int i;
	char levelInfo;

	if ((results = fopen("../data/results.txt", "a")) == NULL)
	{
		printf("\n\n");
		perror("Error");
		printf("Results could not be saved!");
	}
	else
	{
		if (finalResult == 1)
		{
			if (choosedLevel == 0)
				fprintf(results, "VICTORY | EASY | name: %10s | time: %4.1f | tries: %2d |\n", name, time, numberOfTries);
			else if (choosedLevel == 1)
				fprintf(results, "VICTORY | HARD | name: %10s | time: %4.1f | tries: %2d |\n", name, time, numberOfTries);
		}
		else if (finalResult == 0)
		{
			if (choosedLevel == 0)
				fprintf(results, "LOSS    | EASY | name: %10s | time: %4.1f | tries: %2d | correct positions: %d | incorrect positions: %d |\n", name, time, numberOfTries, goodPosition, wrongPosition);
			else if (choosedLevel == 1)
				fprintf(results, "LOSS    | HARD | name: %10s | time: %4.1f | tries: %2d | correct positions: %d | incorrect positions: %d |\n", name, time, numberOfTries, goodPosition, wrongPosition);
		}     
		fclose(results);
	}
}

void showResultsFromFile(int switchOfType)
{
	int i;
	const int max_n = 150;
	char text[150], *result;

	FILE * results;
	results = fopen("../data/results.txt", "r");

	/*zliczanie liczby linii w pliku */
	int lines = countLinesInFile();

	if (results)
	{
		displayTableHeader();

		for (i = 0; i < lines; i++)
		{
			result = fgets(text, max_n, results);   // czytamy ze standardowego wejœcia

			if (result != NULL)
			{
				if (switchOfType == 0)
					printf("%s", text);
				else if (switchOfType == 1)/* wyswietlanie porazek */
				{
					if (text[0] == 'L')
						printf("%s", text);
					else continue;
				}
				else if (switchOfType == 2)/* wyswietlanie zwyciestw */
				{
					if (text[0] == 'V')
						printf("%s", text);
					else continue;
				}
			}
			else break;
		}
		fclose(results);
	}
	else perror("\nError");
}