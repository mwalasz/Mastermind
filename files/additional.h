#ifndef ADDITIONAL_H
#define ADDITIONAL_H

/* dodatkowe funkcje */

/* funkcja konwertujaca liczbe typu int na tablice zawierajaca poszczegolne cyfry */
int * convertNumberToArray(unsigned int number);

/* funkcja umozliwiajaca powrot do menu z jakiegos punktu programu */
void returnToMenu();

/* funkcja wyswietlajaca pomoc */
void showHelp();

void takeParameter(int argc, char* argv[]);

#endif
