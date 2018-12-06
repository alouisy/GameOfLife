#include "gol.h"

void displayWorld(char tab1[MAP_SIZE][MAP_SIZE])
{
	int		x, y;

	x = y = -1;
	while (++y < MAP_SIZE)
	{
		while (++x < MAP_SIZE)
			printf("%c ", tab1[y][x]);
		x = -1;
		printf("\n");
	}
}

int		printfAndScanf(char *str)
{
	int		input;

	printf("%s", str);
	scanf("%d", &input);
	fflush(stdin);
	return (input);
}