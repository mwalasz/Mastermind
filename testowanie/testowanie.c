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

enum menu {Powitanie, PobranieDanychGracza, Gra, Wybor, Pomoc, Statystyki, Koniec, Imie, WyborPoziomuTrudnosci} stan;
stan = Powitanie;
//int stanWyboru;

//void game(int propozycja, int propozycjaTab[], int propozycjaTabKopia[], int los[], int lk_dw[], int lk_dz[], int lk_pr, int indeksOK[])
//{
//	do
//	{
//		if (lk_pr == MAX_PROB - 1)
//			printf("It is your last chance! Try harder!\n\n");
//
//		propozycja = enterProposition();
//		propozycjaTab = convertNumberToArray(propozycja); //przeksztalcenie inta na tablice do funkcji analizujacej
//
//														  /* SKOPIOWANIE PROPOZYCJI GRACZA */
//		for (int s = 0; s < LB_POZ; s++)
//			propozycjaTabKopia[s] = propozycjaTab[s];
//
//		analysisOfPlayerProposition(propozycjaTab, los, &lk_dw, &lk_dz, indeksOK); //analysisOfPlayerProposition propozycji gracza
//
//		wyswietlanieWynikowRundy(lk_dw, lk_dz, propozycjaTabKopia, indeksOK); //wyswietlanie wynikow rundy
//
//		lk_pr++; //zwiekszenie liczby prob
//
//		for (int z = 0; z < LB_POZ; z++) //resetowanie indeksow poprawnych miejsc
//			indeksOK[z] = 0;
//	} while (lk_dw < LB_POZ && lk_pr < MAX_PROB);
//}

int main()
{	
	int los[LB_POZ];	//wylosowana przez program kombinacja
	int prop[LB_POZ];   //propozycja gracza
	int indeksOK[LB_POZ] = { 0 }; //tablica przechowujaca tymczasowe poprawne indeksy wpisane przez uzytkownika

	int lk_pr = 0;			//licznik prob
	int lk_dw = 0;			//liczba dobrych cyfr na wlasciwym miejscu
	int lk_dz;			//liczba dobrych cyfr na zlym miejscu
	
	int propozycja; //zmienna przechowujaca propozycje gracza
	int *propozycjaTab; //przeksztalcona propozycja na tablice
	int propozycjaTabKopia[LB_POZ]; //skopiowana propzycja

	unsigned int finalResult = 0; //zapisywany końcowy
	unsigned int choosedLevel; //wybrany poziom
	
	float timeDifference;
	clock_t startOfTimeMeasuring;
	clock_t endOfTimeMeasuring;

	int stanWyboru;

	system("cls");
	while (1)
	{
		switch (stan)
		{
		case Powitanie:
			printf("MASTERMIND!\n\n\n\n\nby Mateusz Walasz");
			Sleep(1000);
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
			printf("Statistics\n\n\nHere will appear statistics.");
			
			returnToMenu();
			stan = Wybor;
			break;

		case Imie:
			system("cls");

			char name[NAME_LENGTH];
			printf("Your name: ");
			scanf("%s", &name);
			stan = Wybor;
			break;

		case PobranieDanychGracza:
			printf("Your name: ");
			stan = Wybor;
			break;

		case WyborPoziomuTrudnosci:
			chooseDificulty();

			int choice;
			scanf("%d", &choice);

				switch (choice)//randomizeNumber poczatkowej sekwencji, ktora nalezy zgadnac
				{
				case 0:
					choosedLevel = 0;
					randomizeNumber(los, 0);
					break;

				case 1:
					choosedLevel = 1;
					randomizeNumber(los, 1);
					break;
				}

			Sleep(1000);
			stan = Gra;
			break;

		case Koniec:
			system("cls");
			printf("Thanks for the game! Goodbye %s!", name);
			return 0;

		case Wybor:
			system("cls");
			printf("Choose: \n\n0 : Help\n1 : Play game\n2 : Statistics\n3 : Quit\n\nYour choose: ");
			scanf("%d", &stanWyboru);

				switch (stanWyboru)
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

			lk_pr = 0;

			startOfTimeMeasuring = clock(); //poczatek mierzenia czasu
			//game(propozycja, propozycjaTab, propozycjaTabKopia, los, lk_dw, lk_dz, lk_pr,indeksOK);
			do
			{
				if (lk_pr == MAX_PROB - 1)
					printf("It is your last chance! Try harder!\n\n");

				propozycja = enterProposition();
				propozycjaTab = convertNumberToArray(propozycja); //przeksztalcenie inta na tablice do funkcji analizujacej

				/* SKOPIOWANIE PROPOZYCJI GRACZA */
				for (int s = 0; s < LB_POZ; s++)
					propozycjaTabKopia[s] = propozycjaTab[s];

				analysisOfPlayerProposition(propozycjaTab, los, &lk_dw, &lk_dz, indeksOK); //analysisOfPlayerProposition propozycji gracza

				wyswietlanieWynikowRundy(lk_dw, lk_dz, propozycjaTabKopia, indeksOK); //wyswietlanie wynikow rundy

				lk_pr++; //zwiekszenie liczby prob

				for (int z = 0; z < LB_POZ; z++) //resetowanie indeksow poprawnych miejsc
					indeksOK[z] = 0;
			} while (lk_dw < LB_POZ && lk_pr < MAX_PROB);

			endOfTimeMeasuring = clock();

			timeDifference = (float)(endOfTimeMeasuring - startOfTimeMeasuring) / CLOCKS_PER_SEC;
			
			if (lk_dw == LB_POZ)
				finalResult = 1;
			else finalResult = 0;

			wyswietlanieWynikowKoncowych(los, lk_dw, lk_dz, lk_pr, propozycjaTabKopia, timeDifference);

			saveToFile(timeDifference, name, lk_dw, lk_dz, lk_pr, finalResult, choosedLevel); //ZAPIS DO PLIKU

			Sleep(1500);

			printf("\n\n0 : Back to menu\n1 : Play again\n2 : Exit the game\n\nYour choose: ");
			scanf("%d", &stanWyboru);

			if (stanWyboru == 0)
			{
				stan = Wybor;
				printf("Back to menu!\n");
				Sleep(1000);
			}
			else if (stanWyboru == 1)
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