#include "cub3d.h"

void	basic_up(t_vars *vars)
{
	if (colliding(UP, vars->map, vars->player, vars->display))
		return ;
	vars->display->refresh = true;
	vars->player->y -= 1 * vars->player->speed;
	return ;
}

void	basic_down(t_vars *vars)
{
	if (colliding(DOWN, vars->map, vars->player, vars->display))
		return ;
	vars->display->refresh = true;
	vars->player->y += 1 * vars->player->speed;
	return ;
}

void	basic_left(t_vars *vars)
{
	if (colliding(LEFT, vars->map, vars->player, vars->display))
		return ;
	vars->display->refresh = true;
	vars->player->x -= 1 * vars->player->speed;
	return ;
}

/*
	Add a variable to refresh, put to 1 if changed
*/

void	basic_right(t_vars *vars)
{
	if (colliding(RIGHT, vars->map, vars->player, vars->display))
		return ;
	vars->display->refresh = true;
	vars->player->x += 1 * vars->player->speed;
	return ;
}
