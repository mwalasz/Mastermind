#include "fileSupport.h"

#include <stdio.h>
#include <string.h>

void saveToFile(float time, const char* name, int lk_dw, int lk_dz, int lk_pr, unsigned int finalResult, unsigned int choosedLevel)
{
	FILE *fp;
	int i;

	char levelInfo;

	if ((fp = fopen("data.txt", "a")) == NULL)
	{
		printf("\n\n");
		perror("ERROR");
		printf("\nResults could not be saved!");
	}
	else
	{
		if (finalResult == 1)
		{
			if (choosedLevel == 0)
				fprintf(fp, "VICTORY | EASY | name: %10s | time: %4.1f | tries: %2d |\n", name, time, lk_pr);
			else if (choosedLevel == 1)
				fprintf(fp, "VICTORY | HARD | name: %10s | time: %4.1f | tries: %2d |\n", name, time, lk_pr);
		}
		else if (finalResult == 0)
		{
			if (choosedLevel == 0)
				fprintf(fp, "LOSS    | EASY | name: %10s | time: %4.1f | tries: %2d | correct positions: %d | incorrect positions: %d |\n", name, time, lk_pr, lk_dw, lk_dz);
			else if (choosedLevel == 1)
				fprintf(fp, "LOSS    | HARD | name: %10s | time: %4.1f | tries: %2d | correct positions: %d | incorrect positions: %d |\n", name, time, lk_pr, lk_dw, lk_dz);
		}     
	}
	fclose(fp);
}

void showResultsFromFile(int switchOfType)
{
	int i;
	const int max_n = 150;
	char text[150], *result;

	FILE * results;
	results = fopen("data.txt", "r");

	/*zliczanie liczby linii w pliku */
	int lines = countLinesInFile();

	if (results)
	{
		printf("|=======|======|==================|============|===========|======================|========================|\n");
		printf("| RESULT| LVL  |       NAME       |    TIME    |   TRIES   |        CORRECT       |        INCORRECT       |\n");
		printf("|=======|======|==================|============|===========|======================|========================|\n");

		for (i = 0; i < lines; i++)
		{
			result = fgets(text, max_n, results);   // czytamy ze standardowego wejœcia

			if (result != NULL)
			{
				if (switchOfType == 0)
				{
					printf("%s", text);
				}
				else if (switchOfType == 1)
				{
					/* wyswietlanie porazek */
					if (text[0] == 'L')
					{
						printf("%s", text);
					}
					else continue;
				}
				else if (switchOfType == 2)
				{
					/* wyswietlanie zwyciestw */
					if (text[0] == 'V')
					{
						printf("%s", text);
					}
					else continue;
				}
			}
			else
			{
				//printf("Error: file is empty.");
				break;
			}
		}
	}
	else printf("Error: cannot open the file!");

	fclose(results);
}