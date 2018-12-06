#ifndef GOL_H
# define GOL_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# ifdef _WIN32
#  define CLEAR "cls"
# else
#  define CLEAR "clear"
# endif

# define MAP_SIZE	40

typedef struct	world
{
	char		world[MAP_SIZE][MAP_SIZE];
}				t_world;

typedef struct	cell
{
	int			y;
	int			x;
	char		state;
}				t_cell;

void			init_cell(t_cell cell[MAP_SIZE * MAP_SIZE], t_world *map);
void			copy_map(char map1[MAP_SIZE][MAP_SIZE], char map2[MAP_SIZE][MAP_SIZE]);
void			displayWorld(char tab1[MAP_SIZE][MAP_SIZE]);
int				printfAndScanf(char *str);
void			newGeneration(char tab1[MAP_SIZE][MAP_SIZE], char tab2[MAP_SIZE][MAP_SIZE]);
int				check_updownleftright(int x, int y, char tab1[MAP_SIZE][MAP_SIZE]);
int				check_diagonal(int x, int y, char tab1[MAP_SIZE][MAP_SIZE]);
void			continueMode(char tab1[MAP_SIZE][MAP_SIZE], char tab2[MAP_SIZE][MAP_SIZE]);
void			stepMode(char tab1[MAP_SIZE][MAP_SIZE], char tab2[MAP_SIZE][MAP_SIZE]);

#endif