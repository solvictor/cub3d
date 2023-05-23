#include "cub3d.h"

/*
	TODO Cap rotate speed
*/

void	rotate_left(t_vars *vars)
{
	t_player	*player;
	int			direction;

	vars->display->refresh = true;
	player = vars->player;
	direction = vars->player->direction;
	if (direction + player->rotate_speed <= player->rotate_speed)
		player->direction = direction - player->rotate_speed + 360;
	else
		player->direction = direction - player->rotate_speed;
}

void	rotate_right(t_vars *vars)
{
	t_player	*player;
	int			direction;

	vars->display->refresh = true;
	player = vars->player;
	direction = vars->player->direction;
	if (direction + player->rotate_speed >= 359 + player->rotate_speed)
		player->direction = direction + player->rotate_speed - 360;
	else
		player->direction = direction + player->rotate_speed;
}
