#ifndef FILESUPPORT_H
#define FILESUPPORT_H

/* funkcje odpowiadajace za operacje na plikach */
/* --- ---- ---- ---- */

/* funkcja zapisujaca wyniki poszczegolnej rundy gry do pliku */
void saveToFile(float time, const char* name, int goodPosition, int wrongPosition, int numberOfTries, unsigned int finalResult, unsigned int choosedLevel);

/* funkcja odczytujaca z pliku wyniki rozegranych rund i wyswietla je na ekranie */
void showResultsFromFile(int switchOfType);

/* funkcja zliczajca ilosc linii w pliku */
int countLinesInFile();

#endif