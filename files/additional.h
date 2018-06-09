#ifndef ADDITIONAL_H
#define ADDITIONAL_H

/* dodatkowe funkcje */
/* --- ---- ---- ---- */

/* funkcja konwertujaca liczbe typu int na tablice zawierajaca poszczegolne cyfry */
int * convertNumberToArray(unsigned int number);

/* funkcja umozliwiajaca powrot do program z jakiegos punktu programu */
void returnToMenu();

/* funkcja pobierajaca parrametr w trakcie uruchamiania programu */
void takeParameter(int argc, char* argv[]);

/* funkcja pobierajaca imie gracza i alokujaca ja dynamicznie*/
char * enterName();

/* funkcja zwracajaca poprawna wartosc dla instrukcji warunkowej switch */
unsigned int returnCheckedCorrectSwitchVariable(unsigned int variableToCheck);

#endif