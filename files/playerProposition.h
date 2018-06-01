#ifndef PLAYERPROPOSITION_H
#define PLAYERPROPOSITION_H

void analysisOfPlayerProposition(int proposition[], int draw[], int goodPosition[], int wrongPosition[], int correctIndex[]);

int enterProposition();

int getProposition();

//void game(int propozycja, int propozycjaTab[], int propozycjaTabKopia[], int draw[], int goodPosition[], int wrongPosition[], int numberOfTries, int correctIndex[])
//{
//	do
//	{
//		if (numberOfTries == MAX_NUMBER_OF_TRIES - 1)
//			printf("It is your last chance! Try harder!\n\n");
//
//		propozycja = enterProposition();
//		propozycjaTab = convertNumberToArray(propozycja); //przeksztalcenie inta na tablice do funkcji analizujacej
//
//														  /* SKOPIOWANIE PROPOZYCJI GRACZA */
//		for (int s = 0; s < NUMBER_OF_POSITIONS; s++)
//			propozycjaTabKopia[s] = propozycjaTab[s];
//
//		analysisOfPlayerProposition(propozycjaTab, draw, &goodPosition, &wrongPosition, correctIndex); //analysisOfPlayerProposition propozycji gracza
//
//		displayResultsOfRound(goodPosition, wrongPosition, propozycjaTabKopia, correctIndex); //wyswietlanie wynikow rundy
//
//		numberOfTries++; //zwiekszenie liczby prob
//
//		for (int z = 0; z < NUMBER_OF_POSITIONS; z++) //resetowanie indeksow poprawnych miejsc
//			correctIndex[z] = 0;
//	} while (goodPosition < NUMBER_OF_POSITIONS && numberOfTries < MAX_NUMBER_OF_TRIES);
//}


#endif
