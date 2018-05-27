#include "fileSupport.h"

#include <stdio.h>
#include <string.h>

void saveToFile(float time, const char* name, int lk_dw, int lk_dz, int lk_pr, unsigned int finalResult, unsigned int choosedLevel)
{
	FILE *fp;
	int i;

	char levelInfo;

	if ((fp = fopen("data.txt", "a")) == NULL)
	{
		perror("ERROR");
		exit(1);
	}
	else
	{
		if (finalResult == 1)
		{
			if (choosedLevel == 0)
				fprintf(fp, "VICTORY | EASY | name: %10s | time: %4.1f | tries: %2d \n", name, time, lk_pr);
			else if (choosedLevel == 1)
				fprintf(fp, "VICTORY | HARD | name: %10s | time: %4.1f | tries: %2d \n", name, time, lk_pr);
		}
		else if (finalResult == 0)
		{
			if (choosedLevel == 0)
				fprintf(fp, "LOSS    | EASY | name: %10s | time: %4.1f | tries: %2d | correct positions: %d | incorrect positions: %d\n", name, time, lk_pr, lk_dw, lk_dz);
			else if (choosedLevel == 1)
				fprintf(fp, "LOSS    | HARD | name: %10s | time: %4.1f | tries: %2d  | correct positions: %d | incorrect positions: %d\n", name, time, lk_pr, lk_dw, lk_dz);
		}
	}
}