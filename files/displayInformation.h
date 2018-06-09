#ifndef DISPLAYINFORMATION_H
#define DISPLAYINFORMATION_H

/* funkcje umozliwiajace wysiwetlanie informacji na ekranie */
/* wykorzystuja dodatkowa bilbioteke (rlutil.h), dzieki ktorej mozliwa jest zmiana koloru poszczegolnych znakow */

/* --- ---- ---- ---- */

/* funkcja wyswietlajaca finalne wyniki */
void displayFinalResults(int los[], int lk_dw, int lk_dz, int lk_pr, int propozycjaTabKopia[], float time);

/* funkcja wyswietlajaca wyniki poszczegolnej rundy */
void displayResultsOfRound(int goodPosition, int wrongPosition, int copyOfPropositionArray[], int correctIndex[]);

/* funkcja zmieniajaca kolor tekstu na czerwony i umozliwiajaca wyswietlanie w "ramce" */
void showRed(int show);

/* funkcja zmieniajaca kolor tekstu na zielony i umozliwiajaca wyswietlanie w "ramce" */
void showGreen(int show);

/* funkcja wyswietlajaca komunikat o wyborze poziomu trudnosci gry */
void showDifficultyMenuText();

/* funkcja wyswietlajaca komunikat ostatnim mozliwym ruchu */
void displayWarning(int numberOfTries);

/* funkcja wyswietlajaca naglowek tabeli wynikow */
void displayTableHeader();

/* funkcja wyswietlajaca logo po uruchomieniu programu */
void showGreeting();

/* funkcja wyswietlajaca pozegnanie po zakonczeniu programu */
void endOfProgram(const char* name);

/* funkcja wyswietlajaca komunikat o wyborze akcji w menu wyswietlania rezultatow */
void showStatisticsMenuText();

/* funkcja wyswietlajaca komunikat o wyborze akcji w glownym menu */
void showMainMenuText();

/* funkcja wyswietlajaca komunikat o wyborze akcji w menu po zakonczeniu gry */
void showMenuAfterGameText();

#endif