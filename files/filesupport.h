#ifndef FILESUPPORT_H
#define FILESUPPORT_H

void saveToFile(float time, const char* name, int goodPosition, int wrongPosition, int numberOfTries, unsigned int finalResult, unsigned int choosedLevel);

void showResultsFromFile(int switchOfType);

#endif
