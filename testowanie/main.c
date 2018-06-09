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

enum menu {welcome, Gra, mainMenu, help, statistics, turnOffGame, playerName, easyOrHard} stateOfProgram;
stateOfProgram = welcome;

int main(int argc, char *argv[])
{
	int draw[NUMBER_OF_POSITIONS];					//wylosowana przez program kombinacja
	int playerProposition[NUMBER_OF_POSITIONS];		//propozycja gracza
	int correctIndex[NUMBER_OF_POSITIONS] = { 0 };  //tablica przechowujaca tymczasowe poprawne indeksy wpisane przez uzytkownika
	char * name; //imie gracza

	int numberOfTries = 0;		//licznik prob
	int goodPosition = 0;		//liczba dobrych cyfr na wlasciwym miejscu
	int wrongPosition;			//liczba dobrych cyfr na zlym miejscu

	int switchOfAftergameAction = 0;
	int switchOfResultsDisplay = 0;
	int switchOfDifficulty = 1;
	int switchOfMenu = 0;

	int propozycja;//zmienna przechowujaca propozycje gracza
	int *propozycjaTab; //przeksztalcona propozycja na tablice
	int propozycjaTabKopia[NUMBER_OF_POSITIONS]; //skopiowana propzycja

	unsigned int finalResult = 0; //zapisywany końcowy
	unsigned int choosedLevel; //wybrany poziom trudnosci

	float timeDifference;
	clock_t startOfTimeMeasuring;
	clock_t endOfTimeMeasuring;

	int * rozmiarTablicy;

	takeParameter(argc, argv); //obsluga parametrow

	system("cls");
	while (1)
	{
		switch (stateOfProgram)
		{
		case welcome:
			showGreeting();

			Sleep(1500);
			stateOfProgram = playerName;
			break;

		case help:
			showHelp();
			returnToMenu();

			stateOfProgram = mainMenu;
			break;

		case statistics:
			system("cls");
			stateOfProgram = mainMenu;

			printf("Choose what action do you want to perform:\n\n1 : show defeats\n2 : show victories\n3 : show everything\n4 : back to menu\n\nYour choose: ");
			switchOfResultsDisplay = returnCheckedCorrectSwitchVariable(switchOfResultsDisplay);

			if (switchOfResultsDisplay == 4)
				break;

			showResultsFromFile(switchOfResultsDisplay);
			returnToMenu();
			break;

		case playerName:
			name = enterName();

			stateOfProgram = mainMenu;
			break;

		case easyOrHard:
			chooseDifficulty();
			switchOfDifficulty = returnCheckedCorrectSwitchVariable(switchOfDifficulty);

			switch (switchOfDifficulty)//randomizeNumber poczatkowej sekwencji, ktora nalezy zgadnac
			{
			case 3:
				stateOfProgram = mainMenu;
				break;

			case 1:
				choosedLevel = 0;
				randomizeNumber(draw, 0);
				stateOfProgram = Gra;
				Sleep(1000);
				break;

			case 2:
				choosedLevel = 1;
				randomizeNumber(draw, 1);
				stateOfProgram = Gra;
				Sleep(1000);
				break;

			default:
				stateOfProgram = easyOrHard;
				break;
			}

			break;

		case turnOffGame:
			endOfProgram(name);
			return 0;

		case mainMenu:
			system("cls");
			printf("Choose: \n\n1 : Play game\n2 : Statistics\n3 : Help\n4 : Quit\n\nYour choose: ");
			switchOfMenu = returnCheckedCorrectSwitchVariable(switchOfMenu);

			switch (switchOfMenu)
			{
			case 1:
				stateOfProgram = easyOrHard;
				break;

			case 2:
				stateOfProgram = statistics;
				break;

			case 3:
				stateOfProgram = help;
				break;

			case 4:
				stateOfProgram = turnOffGame;
				break;

			default:
				break;

			}
			break;

		case Gra:
			newGameComunicate();
			numberOfTries = 0;

			startOfTimeMeasuring = clock(); //poczatek mierzenia czasu

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

			printf("\n\n\n1 : Play again\n2 : Back to menu\n3 : Exit the game\n\nYour choose: ");
			switchOfAftergameAction = returnCheckedCorrectSwitchVariable(switchOfAftergameAction);

			switch (switchOfAftergameAction)
			{
			case 1:
				stateOfProgram = easyOrHard;
				break;

			case 2:
				stateOfProgram = mainMenu;
				printf("Back to menu!\n");
				Sleep(1000);
				break;

			default:
				stateOfProgram = turnOffGame;
				break;
			}
	
		}
	}

	free(name);

	return 0;
}