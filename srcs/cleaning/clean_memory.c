/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:22:48 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:22:49 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clean_map(t_map *map)
{
	if (map->path_north)
		free(map->path_north);
	if (map->path_south)
		free(map->path_south);
	if (map->path_east)
		free(map->path_east);
	if (map->path_west)
		free(map->path_west);
	if (map->map)
		ft_free_strs(map->map);
}

static void	destroy_window(t_display *display)
{
	mlx_destroy_image(display->mlx, display->img);
	mlx_destroy_window(display->mlx, display->win);
	mlx_destroy_display(display->mlx);
	free(display->mlx);
}

void	destroy_images(t_display *display, t_map *map, const int ind)
{
	mlx_destroy_image(display->mlx, map->textures[0].img);
	map->textures[0].img = NULL;
	if (ind >= 1)
		mlx_destroy_image(display->mlx, map->textures[1].img);
	if (ind >= 2)
		mlx_destroy_image(display->mlx, map->textures[2].img);
	if (ind >= 3)
		mlx_destroy_image(display->mlx, map->textures[3].img);
}

void	clean_memory(t_vars *vars)
{
	clean_map(vars->map);
	if (vars->map->textures[0].img != NULL)
		destroy_images(vars->display, vars->map, 3);
	if (vars->display->img)
		destroy_window(vars->display);
	ft_free_strs(vars->file_content);
}
