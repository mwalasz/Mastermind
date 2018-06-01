#ifndef DISPLAYINFORMATION_H
#define DISPLAYINFORMATION_H

void displayFinalResults(int los[], int lk_dw, int lk_dz, int lk_pr, int propozycjaTabKopia[], float time);

void displayResultsOfRound(int goodPosition, int wrongPosition, int copyOfPropositionArray[], int correctIndex[]);

void showRed(int show);

void showGreen(int show);

void chooseDificulty();

void displayWarning(int numberOfTries);

void displayTableHeader();

#endif