#include "cub3d.h"

/*
	TODO actualise squares, check for collisions
	can be simplified
*/

// static void	first_quadrant(t_player *player)
// {
// 	player->x += player->speed;
// 	player->y -= round(tan(deg_to_rad(player->direction)));
// }

// static void	second_quadrant(t_player *player)
// {
// 	player->x -= player->speed;
// 	player->y -= round(tan(deg_to_rad(player->direction)));
// }

// static void	third_quadrant(t_player *player)
// {
// 	player->x -= player->speed;
// 	player->y += round(tan(deg_to_rad(player->direction)));
// }

// static void	fourth_quadrant(t_player *player)
// {
// 	player->x += player->speed;
// 	player->y += round(tan(deg_to_rad(player->direction)));
// }	

void	move_player(t_vars *vars)
{
	t_player	*player;
	int			quadrant;

	(void)player;
	(void)quadrant;
	// player = vars->player;
	// quadrant = quadrant_of_angle((player->direction + player->move) % 360);
	// if (quadrant == 1)
	// 	first_quadrant(player);
	// else if (quadrant == 2)
	// 	second_quadrant(player);
	// else if (quadrant == 3)
	// 	third_quadrant(player);
	// else
	// 	fourth_quadrant(player);
	// player->move = 0;
	vars->display->refresh = true;

}
