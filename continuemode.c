#include "gol.h"

void	continueMode(char tab1[MAP_SIZE][MAP_SIZE], char tab2[MAP_SIZE][MAP_SIZE])
{
	struct timespec tim, tim2;
	tim.tv_sec  = 0;
	tim.tv_nsec = 62500000L;
	int life = 1;
	int gen;
	int i = 0;

	printf("Continue mode\n\n\nHere is your starting world !\n\nGeneration n°%d\n\n", life);
	displayWorld(tab1);
	gen = printfAndScanf("\nPlease enter the number of generations you want to show : ");
	life += 1;
	while (life <= gen)
	{
		if (i % 2 == 0)
		{
			system(CLEAR);
			newGeneration(tab1,tab2);
			printf("\nGeneration n°%d\n\n",life);
			displayWorld(tab2);
			life += 1;
			i += 1;
		}
		else
		{
			system(CLEAR);
			newGeneration(tab2,tab1);
			printf("\nGeneration n°%d\n\n",life);
			displayWorld(tab1);
			life += 1;
			i += 1;
		}
		#ifdef _WIN32
		Sleep(250);
		#else
		nanosleep(&tim , &tim2);
		#endif
	}
	printf("\n\n\n\nGood Bye.\n");
}