#include "../files/filesupport.h"
#include "../files/displayInformation.h"

#include <stdio.h>
#include <string.h>

void saveToFile(float time, const char* name, int goodPosition, int wrongPosition, int numberOfTries, unsigned int finalResult, unsigned int choosedLevel)
{
	FILE * results;
	int i;
	char levelInfo;

	if ((results = fopen("../data/results.txt", "a")) == NULL) //gdy blad podczas otwarcia pliku, wyswietlany jest komunikat
	{
		printf("\n\n");
		perror("Error");
		printf("Results could not be saved!");
	}
	else //jesli poprawnie otwarto plik w zaleznosc od rezultatu gry sa zapisywane wyniki
	{
		if (finalResult == 1)
		{
			if (choosedLevel == 0)
				fprintf(results, "VICTORY | EASY | name: %10s | time: %5.1f | tries: %2d \n", name, time, numberOfTries);
			else if (choosedLevel == 1)
				fprintf(results, "VICTORY | HARD | name: %10s | time: %5.1f | tries: %2d \n", name, time, numberOfTries);
		}
		else if (finalResult == 0)
		{
			if (choosedLevel == 0)
				fprintf(results, "LOSS    | EASY | name: %10s | time: %5.1f | tries: %2d | correct positions: %d | incorrect positions: %d \n", name, time, numberOfTries, goodPosition, wrongPosition);
			else if (choosedLevel == 1)
				fprintf(results, "LOSS    | HARD | name: %10s | time: %5.1f | tries: %2d | correct positions: %d | incorrect positions: %d \n", name, time, numberOfTries, goodPosition, wrongPosition);
		}     
		fclose(results); //zakmniecie pliku
	}
}

void showResultsFromFile(int switchOfType)
{
	int i;
	const int max_n = 150;
	char text[150], *result;

	FILE * results;
	results = fopen("../data/results.txt", "r");

	int lines = countLinesInFile(); //zliczanie linii w pliku

	if (lines != 0) //jesli liczba linii w pliku nie jest rowna 0
	{
		if (results) //jesli poprwanie otwarto plik
		{
			displayTableHeader(); //wyswietlanie naglowka tabeli

			for (i = 0; i < lines; i++)
			{
				result = fgets(text, max_n, results);   //czytamy ze standardowego wejœcia

				if (result != NULL)
				{
					if (switchOfType == 3) //wyswietlanie wszystkiego
						printf("%s", text);
					else if (switchOfType == 1) //wyswietlanie porazek
					{
						if (text[0] == 'L')
							printf("%s", text);
						else continue;
					}
					else if (switchOfType == 2) //wyswietlanie zwyciestw
					{
						if (text[0] == 'V')
							printf("%s", text);
						else continue;
					}
				}
				else break;
			}

			fclose(results); //zakmkniecie pliku
		}
		else perror("\nError");
	}
	else printf("\nError: cannot open the file!");
}

int countLinesInFile()
{
	FILE * results;
	char c;
	int numberOfLines = 0;

	results = fopen("../data/results.txt", "r");

	if (results == NULL) //jesli nie mozna bylo otworzyc pliku, zwracana jest 0 ilosc linii
		return 0;
	else
	{
		for (c = getc(results); c != EOF; c = getc(results))
		{
			if (c == '\n')
				numberOfLines++; //jesli napotkano na znak nowej linii, inkrementuje sie zmienna przechowujaca liczbe linii
		}
		fclose(results); //zamkniecie pliku
	}
	return numberOfLines; //zwrocenie liczby linii
}