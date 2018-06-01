#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

#include "../files/filesupport.h"
#include "../files/displayInformation.h"
#include "../files/definitions.h"
#include "../files/drawLots.h"
#include "../files/playerProposition.h"
#include "../files/additional.h"

enum menu {Powitanie, Gra, Wybor, Pomoc, Statystyki, Koniec, Imie, WyborPoziomuTrudnosci} stan;
stan = Powitanie;

int main()
{	
	int draw[NUMBER_OF_POSITIONS];					//wylosowana przez program kombinacja
	int playerProposition[NUMBER_OF_POSITIONS];		//propozycja gracza
	int correctIndex[NUMBER_OF_POSITIONS] = { 0 };  //tablica przechowujaca tymczasowe poprawne indeksy wpisane przez uzytkownika
	char name[NAME_LENGTH];

	int numberOfTries = 0;		//licznik prob
	int goodPosition = 0;		//liczba dobrych cyfr na wlasciwym miejscu
	int wrongPosition;			//liczba dobrych cyfr na zlym miejscu

	int switchOfAftergameAction;
	int switchOfResultsDisplay = 0;
	int switchOfDifficulty;
	int switchOfMenu;

	int propozycja;//zmienna przechowujaca propozycje gracza
	int *propozycjaTab; //przeksztalcona propozycja na tablice
	int propozycjaTabKopia[NUMBER_OF_POSITIONS]; //skopiowana propzycja

	unsigned int finalResult = 0; //zapisywany końcowy
	unsigned int choosedLevel; //wybrany poziom trudnosci
	
	float timeDifference;
	clock_t startOfTimeMeasuring;
	clock_t endOfTimeMeasuring;

	system("cls");
	while (1)
	{
		switch (stan)
		{
		case Powitanie:

			showMenu();
			
			Sleep(1500);
			stan = Imie;
			break;

		case Pomoc:
			system("cls");
			printf("Help\n\n\nHere will appear some tips.");

			returnToMenu();

			stan = Wybor;
			break;

		case Statystyki:
			system("cls");
		
			printf("Choose what you want to display:\n0: show all\n1: defeats\n2: victories\n\nYour choose: ");
			scanf("%d", &switchOfResultsDisplay);

			showResultsFromFile(switchOfResultsDisplay);

			returnToMenu();

			stan = Wybor;
			break;

		case Imie:
			system("cls");

			printf("Your name: ");
			scanf("%s", &name);

			stan = Wybor;
			break;

		case WyborPoziomuTrudnosci:
			chooseDifficulty();

			scanf("%d", &switchOfDifficulty);

				switch (switchOfDifficulty)//randomizeNumber poczatkowej sekwencji, ktora nalezy zgadnac
				{
				case 0:
					choosedLevel = 0;
					randomizeNumber(draw, 0);
					break;

				case 1:
					choosedLevel = 1;
					randomizeNumber(draw, 1);
					break;
				}

			Sleep(1000);
			stan = Gra;
			break;

		case Koniec:
			endOfProgram(name);
			return 0;

		case Wybor:
			system("cls");
			printf("Choose: \n\n0 : Help\n1 : Play game\n2 : Statistics\n3 : Quit\n\nYour choose: ");
			scanf("%d", &switchOfMenu);

				switch (switchOfMenu)
				{
				case 0:
					stan = Pomoc;
					break;

				case 1:
					stan = WyborPoziomuTrudnosci;
					break;

				case 2:
					stan = Statystyki;
					break;

				case 3:
					stan = Koniec;
					break;
				}
			break;

		case Gra:
			system("cls");
			printf("New game!");
			Sleep(1000);
			system("cls");

			numberOfTries = 0;

			startOfTimeMeasuring = clock(); //poczatek mierzenia czasu
			//game(propozycja, propozycjaTab, propozycjaTabKopia, draw, goodPosition, wrongPosition, numberOfTries,correctIndex);
			do
			{
				displayWarning(numberOfTries);

				propozycja = getProposition();
				propozycjaTab = convertNumberToArray(propozycja); //przeksztalcenie inta na tablice do funkcji analizujacej

				/* SKOPIOWANIE PROPOZYCJI GRACZA */
				for (int s = 0; s < NUMBER_OF_POSITIONS; s++)
					propozycjaTabKopia[s] = propozycjaTab[s];

				analysisOfPlayerProposition(propozycjaTab, draw, &goodPosition, &wrongPosition, correctIndex); //analysisOfPlayerProposition propozycji gracza

				displayResultsOfRound(goodPosition, wrongPosition, propozycjaTabKopia, correctIndex); //wyswietlanie wynikow rundy

				numberOfTries++; //zwiekszenie liczby prob

				for (int z = 0; z < NUMBER_OF_POSITIONS; z++) //resetowanie indeksow poprawnych miejsc
					correctIndex[z] = 0;
			} while (goodPosition < NUMBER_OF_POSITIONS && numberOfTries < MAX_NUMBER_OF_TRIES);

			endOfTimeMeasuring = clock();

			timeDifference = (float)(endOfTimeMeasuring - startOfTimeMeasuring) / CLOCKS_PER_SEC;
			
			if (goodPosition == NUMBER_OF_POSITIONS)
				finalResult = 1;
			else finalResult = 0;

			displayFinalResults(draw, goodPosition, wrongPosition, numberOfTries, propozycjaTabKopia, timeDifference);

			saveToFile(timeDifference, name, goodPosition, wrongPosition, numberOfTries, finalResult, choosedLevel); //ZAPIS DO PLIKU

			Sleep(1500);

			printf("\n\n0 : Back to menu\n1 : Play again\n2 : Exit the game\n\nYour choose: ");
			scanf("%d", &switchOfAftergameAction);

			if (switchOfAftergameAction == 0)
			{
				stan = Wybor;
				printf("Back to menu!\n");
				Sleep(1000);
			}
			else if (switchOfAftergameAction == 1)
			{
				stan = WyborPoziomuTrudnosci;
			}
			else
			{
				stan = Koniec;
			}
			break;
		}
	} 
	return 0;
}