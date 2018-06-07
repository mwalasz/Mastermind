#ifndef PLAYERPROPOSITION_H
#define PLAYERPROPOSITION_H

/* funkcje odpowiadajace za operacje na propozycji podanej przez gracza */

/* --- ---- ---- ---- */

/* funkcja analizujaca poprawnosc calej wpisanej kombinacji przez gracza (ile cyfr jest na dobrym miejscu, ile na zlym, ile jest blednych)*/
void analysisOfPlayerProposition(int proposition[], int draw[], int goodPosition[], int wrongPosition[], int correctIndex[]);

/* funkcja analizujaca poprawnosc wpisanej kombinacji liczowej przez gracza (czy ciag nie zawiera 0 - w grze dozwolone sa cyfry z zakresu <1,9>, czy ciag nie zawiera liter)*/
int getAndCheckIfCorrect(int lengthToCheck);

int getProposition();

#endif
