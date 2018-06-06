#ifndef ADDITIONAL_H
#define ADDITIONAL_H

/* dodatkowe funkcje */

/* funkcja konwertujaca liczbe typu int na tablice zawierajaca poszczegolne cyfry */
int * convertNumberToArray(unsigned int number);

/* funkcja umozliwiajaca powrot do menu z jakiegos punktu programu */
void returnToMenu();

/* funkcja wyswietlajaca logo po uruchomieniu programu */
void showGreeting();

/* funkcja wyswietlajaca pozegnanie po zakonczeniu programu */
void endOfProgram(const char* name);

#endif
