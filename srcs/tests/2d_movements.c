#include "cub3d.h"

void	basic_up(t_vars *vars)
{
	t_player	*player;
	t_display	*display;

	if (colliding(UP, vars->map, vars->player, vars->display))
		return ;
	vars->display->refresh = true;
	vars->player->y -= 1 * vars->player->speed;
	player = vars->player;
	display = vars->display;
	player->square_x = player->x / display->square_length;
	player->square_y = player->y / display->square_length;
	return ;
}

void	basic_down(t_vars *vars)
{
	t_player	*player;
	t_display	*display;

	if (colliding(DOWN, vars->map, vars->player, vars->display))
		return ;
	vars->display->refresh = true;
	vars->player->y += 1 * vars->player->speed;
	player = vars->player;
	display = vars->display;
	player->square_x = player->x / display->square_length;
	player->square_y = player->y / display->square_length;
	return ;
}

void	basic_left(t_vars *vars)
{
	t_player	*player;
	t_display	*display;

	if (colliding(LEFT, vars->map, vars->player, vars->display))
		return ;
	vars->display->refresh = true;
	vars->player->x -= 1 * vars->player->speed;
	player = vars->player;
	display = vars->display;
	player->square_x = player->x / display->square_length;
	player->square_y = player->y / display->square_length;
	return ;
}

void	basic_right(t_vars *vars)
{
	t_player	*player;
	t_display	*display;

	if (colliding(RIGHT, vars->map, vars->player, vars->display))
		return ;
	vars->display->refresh = true;
	vars->player->x += 1 * vars->player->speed;
	player = vars->player;
	display = vars->display;
	player->square_x = player->x / display->square_length;
	player->square_y = player->y / display->square_length;
	return ;
}
