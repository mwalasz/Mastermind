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

enum menu {welcome, game, mainMenu, help, statistics, turnOffGame, playerName, easyOrHard} stateOfProgram;
stateOfProgram = welcome;

int main(int argc, char *argv[])
{
	int draw[NUMBER_OF_POSITIONS]; //wylosowana przez program kombinacja
	int playerProposition[NUMBER_OF_POSITIONS];	//propsition gracza
	int correctIndex[NUMBER_OF_POSITIONS] = { 0 }; //tablica przechowujaca tymczasowe poprawne indeksy wpisane przez uzytkownika
	char * name; //imie gracza

	int numberOfTries = 0; //licznik prob
	int goodPosition = 0; //liczba dobrych cyfr na wlasciwym miejscu
	int wrongPosition; //liczba dobrych cyfr na zlym miejscu

	int switchOfAftergameAction = 0;
	int switchOfResultsDisplay = 0;
	int switchOfDifficulty = 1;
	int switchOfMenu = 0;

	int propsition; //zmienna przechowujaca propozycje gracza
	int * propositionArray; //przeksztalcona propsition na tablice
	int copyOfPropositionArray[NUMBER_OF_POSITIONS]; //skopiowana propzycja

	unsigned int finalResult = 0; //zapisywany końcowy
	unsigned int choosedLevel; //wybrany poziom trudnosci

	float timeDifference; //zmienna przechowujaca dlugosc gry
	clock_t startOfTimeMeasuring; //poczatek pomiaru czasu
	clock_t endOfTimeMeasuring; //koniec pomiaru czasu

	takeParameter(argc, argv); //obsluga parametrow programu linii polecen

	while (1)
	{
		switch (stateOfProgram)
		{
		case welcome:
			showGreeting(); //wyswietlanie loga

			stateOfProgram = playerName;
			break;

		case help:
			showHelp(); //wyswietlanie pomocy
			returnToMenu(); //powrot do menu

			stateOfProgram = mainMenu;
			break;

		case statistics:
			stateOfProgram = mainMenu;

			showStatisticsMenuText(); //wyswietlanie tekstu, zawierajacego mozliwe akcje do wybrania
			switchOfResultsDisplay = returnCheckedCorrectSwitchVariable(switchOfResultsDisplay); //pobranie decyzji gracza

			if (switchOfResultsDisplay == 4) //jesli wybrano 4 - wyjscie do menu glownego
				break;

			showResultsFromFile(switchOfResultsDisplay); //wyswietlanie rezultatow gry
			returnToMenu(); //powrot do menu
			break;

		case playerName: //pobranie imienia gracza
			name = enterName(); //pobranie imienia gracza

			stateOfProgram = mainMenu;
			break;

		case easyOrHard: //wybranie poziomu trudnosci
			showDifficultyMenuText(); //wyswietlanie tekstu, zawierajacego mozliwe akcje do wybrania
			switchOfDifficulty = returnCheckedCorrectSwitchVariable(switchOfDifficulty); //pobranie decyzji gracza

			switch (switchOfDifficulty)
			{
			case 1:
				choosedLevel = 0;
				randomizeNumber(draw, 0); //losowanie kombinacji dla poziomu latwego
				stateOfProgram = game;
				Sleep(1000);
				break;

			case 2:
				choosedLevel = 1;
				randomizeNumber(draw, 1); //losowanie kombinacji dla poziomu trudnego
				stateOfProgram = game;
				Sleep(1000);
				break;

			case 3:
				stateOfProgram = mainMenu;
				break;

			default:
				stateOfProgram = easyOrHard;
				break;
			}

			break;

		case turnOffGame: //wylaczenie programu
			endOfProgram(name); //wyswietlanie komunikatu o zakonczeniu programu
			return 0;

		case mainMenu: //glowne menu
			showMainMenuText(); //wyswietlanie tekstu, zawierajacego mozliwe akcje do wybrania
			switchOfMenu = returnCheckedCorrectSwitchVariable(switchOfMenu); //pobranie decyzji gracza

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

		case game: //przeprowadzanie gry
			newGameComunicate(); //wyswietlanie komunikatu o nowej grze
			numberOfTries = 0;

			startOfTimeMeasuring = clock(); //poczatek mierzenia czasu

			do
			{
				displayWarning(numberOfTries);

				propsition = getProposition();
				propositionArray = convertNumberToArray(propsition); //przeksztalcenie inta na tablice do funkcji analizujacej

				/* SKOPIOWANIE PROPOZYCJI GRACZA */
				for (int s = 0; s < NUMBER_OF_POSITIONS; s++)
					copyOfPropositionArray[s] = propositionArray[s];

				analysisOfPlayerProposition(propositionArray, draw, &goodPosition, &wrongPosition, correctIndex); //analysisOfPlayerProposition propozycji gracza

				displayResultsOfRound(goodPosition, wrongPosition, copyOfPropositionArray, correctIndex); //wyswietlanie wynikow rundy

				numberOfTries++; //zwiekszenie liczby prob

				for (int z = 0; z < NUMBER_OF_POSITIONS; z++) //resetowanie indeksow poprawnych miejsc
					correctIndex[z] = 0;
			} while (goodPosition < NUMBER_OF_POSITIONS && numberOfTries < MAX_NUMBER_OF_TRIES);

			endOfTimeMeasuring = clock();

			timeDifference = (float)(endOfTimeMeasuring - startOfTimeMeasuring) / CLOCKS_PER_SEC;

			if (goodPosition == NUMBER_OF_POSITIONS)
				finalResult = 1;
			else finalResult = 0;

			displayFinalResults(draw, goodPosition, wrongPosition, numberOfTries, copyOfPropositionArray, timeDifference);

			saveToFile(timeDifference, name, goodPosition, wrongPosition, numberOfTries, finalResult, choosedLevel); //zapis do pliku

			showMenuAfterGameText(); //wyswietlanie tekstu, zawierajacego mozliwe akcje do wybrania
			switchOfAftergameAction = returnCheckedCorrectSwitchVariable(switchOfAftergameAction); //pobranie decyzji gracza

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

	free(name); //zwolnienie pamieci zarezerwowanej do przechowywania imienia gracza

	return 0;
}