#ifndef DRAWLOTS_H
#define DRAWLOTS_H

/* funkcje losujace liczbe, ktora ma zostac odgadnieta */
/* --- ---- ---- ---- */

/* funkcja odpowiedzialna za wybor typu losowania: powtarzajacego sie, czy nie powtarzajacego sie */
void randomizeNumber(int draw[], unsigned int switchOfFunction);

/* funkcja losujaca cyfry powtarzajace sie */
void randomRepeatable(int draw[]);

/* funkcja losujaca cyfry nie powtarzajace sie */
void randomNonRepeatable(int draw[]);

#endif