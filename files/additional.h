#ifndef ADDITIONAL_H
#define ADDITIONAL_H

/* dodatkowe funkcje */

/* funkcja konwertujaca liczbe typu int na tablice zawierajaca poszczegolne cyfry */
int * convertNumberToArray(unsigned int number);

/* funkcja umozliwiajaca powrot do program z jakiegos punktu programu */
void returnToMenu();

/* funkcja wyswietlajaca pomoc */
void showHelp();

/* funkcja pobierajaca parrametr w trakcie uruchamiania programu */
void takeParameter(int argc, char* argv[]);

/* funkcja pobierajaca imie gracza i alokujaca ja dynamicznie*/
char * enterName();

int returnCheckedCorrectSwitchVariable(int variableToCheck);

/* funkcja wyswietlajaca komunikat o nowej grze */
void newGameComunicate();

#endif