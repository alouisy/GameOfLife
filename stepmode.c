#include "gol.h"

void stepMode(char tab1[MAP_SIZE][MAP_SIZE], char tab2[MAP_SIZE][MAP_SIZE])
{
	int i = 0;
	int gen = 0;
	int answer = 1;

	while (answer != 0)
	{
		if(gen == 0)
		{
			printf("Step-By-Step mode\n\n\nHere is your starting world !\n\n");
			printf("\nGeneration n°%d\n\n",gen);
			displayWorld(tab1);
			gen +=1;
			answer = printfAndScanf("\nDo you want to go to next generation or quit the game ?\nPress ( 1 ) to continue or type ( 0 ) to quit ! ");
			while (answer != 1 && answer != 0)
				answer = printfAndScanf("\nWrong input ! Please retry : ");
		}
		else
		{
			system(CLEAR);
			if(i % 2 == 0)
			{
				newGeneration(tab1,tab2);
				printf("\nGeneration n°%d\n\n",gen);
				displayWorld(tab2);
				gen += 1;
				i += 1;
			} 
			else
			{
				newGeneration(tab2,tab1);
				printf("\nGeneration n°%d\n\n",gen);
				displayWorld(tab1);
				gen += 1;
				i += 1;
			}
			answer = printfAndScanf("\nDo you want to go to next generation or quit the game ?\nPress ( 1 ) to continue or type ( 0 ) to quit ! ");
			while (answer != 1 && answer != 0)
				answer = printfAndScanf("\nWrong input ! Please retry : "); 
		}
	}
}