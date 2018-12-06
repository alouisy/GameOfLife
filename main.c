//
//  main.c
//  GameOfLife
//
//  Created by Axel LOUISY-LOUIS on 17/03/2015.
//  Copyright (c) 2015 Axel LOUISY-LOUIS. All rights reserved.
//

#include "gol.h"

void	init_cell(t_cell cell[MAP_SIZE * MAP_SIZE], t_world *map)
{
	srand(time(NULL));
	char *stat = "-0";
	int x, y, z, n;

	x = y = z = n = -1;
	while (++y < MAP_SIZE)
	{
		while (++x < MAP_SIZE)
		{
			n = rand() % 2;
			cell[z].y = y;
			cell[z].x = x;
			cell[z].state = stat[n];
			map->world[y][x] = cell[z].state;
			z += 1;
		}
		x = -1;
	}
}

int main(int argc, char **argv)
{
	int rep;
	t_world map1;
	t_world map2;
	t_cell cell[MAP_SIZE * MAP_SIZE];

	(void)argc;
	(void)argv;
	system(CLEAR);
	init_cell(cell, &map1);
	copy_map(map1.world, map2.world);
	rep = printfAndScanf("Welcome in The Game Of Life C Version !\n\n\nStep-By-Step mode press ( 1 )\nContinue mode press ( 2 )\n\n\nWhich mode do you want to play ? ");
	while (rep != 1 && rep != 2)
		rep = printfAndScanf("\nWrong input ! Please retry : ");
	system(CLEAR);
	if (rep == 1)
		stepMode(map1.world,map2.world);
	else
		continueMode(map1.world,map2.world);
	return (0);
}