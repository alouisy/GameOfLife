#include "gol.h"

int		check_diagonal(int x, int y, char tab1[MAP_SIZE][MAP_SIZE])
{
	int		alive = 0;

	if (y-1 >= 0 && x-1 >= 0)
	{
		if(tab1[y-1][x-1] == '0' || tab1[y-1][x-1] == '+')
			alive += 1;
	}
	if (y+1 < MAP_SIZE && x+1 < MAP_SIZE)
	{
		if(tab1[y+1][x+1] == '0' || tab1[y+1][x+1] == '+')
			alive += 1;
	}
	if (y+1 < MAP_SIZE && x-1 >= 0)
	{
		if(tab1[y+1][x-1] == '0' || tab1[y+1][x-1] == '+')
			alive += 1;
	}
	if (y-1 >= 0 && x+1 < MAP_SIZE)
	{
		if(tab1[y-1][x+1] == '0' || tab1[y-1][x+1] == '+')
			alive += 1;
	}
	return (alive);
}

int		check_updownleftright(int x, int y, char tab1[MAP_SIZE][MAP_SIZE])
{
	int		alive = 0;

	if (y-1 >= 0)
	{
		if(tab1[y-1][x] == '0' || tab1[y-1][x] == '+')
			alive += 1;
	}
	if (y+1 < MAP_SIZE)
	{
		if(tab1[y+1][x] == '0' || tab1[y+1][x] == '+')
			alive += 1;
	}
	if (x-1 >= 0)
	{
		if(tab1[y][x-1] == '0' || tab1[y][x-1] == '+')
			alive += 1;
	}
	if (x+1 < MAP_SIZE)
	{
		if(tab1[y][x+1] == '0' || tab1[y][x+1] == '+')
			alive += 1;
	}
	return (alive);
}

void	copy_map(char map1[MAP_SIZE][MAP_SIZE], char map2[MAP_SIZE][MAP_SIZE])
{
	int		x, y;

	x = y = -1; 
	while (++y < MAP_SIZE)
	{
		while (++x < MAP_SIZE)
			map2[y][x] = map1[y][x];
		x = -1;
	}
}

void	newGeneration(char tab1[MAP_SIZE][MAP_SIZE], char tab2[MAP_SIZE][MAP_SIZE])
{
	int alive, x, y;

	x = y = -1;
	while (++y < MAP_SIZE)
	{
		while (++x < MAP_SIZE)
		{
			alive = 0;
			alive += check_updownleftright(x, y, tab1);
			alive += check_diagonal(x, y, tab1);
			if (alive < 2)
				tab2[y][x] = '-';
			else if (alive > 3)
				tab2[y][x] = '-';
			else if (alive == 3)
			{
				if (tab1[y][x] == '-')
					tab2[y][x] = '0';
				else
					tab2[y][x] = '+';
			}
			else if (alive == 2)
			{
				if (tab1[y][x] == '-')
					tab2[y][x] = '-';
				else
					tab2[y][x] = '+';
			}
		}
		x = -1;
	}
	copy_map(tab2, tab1);
}