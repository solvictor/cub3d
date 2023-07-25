#include "cub3d_bonus.h"

static void	aux_init_sprite_vars(t_sprite_vars *sprite_vars, t_map *map,
	t_camera *camera, t_display *display)
{
	// printf("Start Aux Init Sprite Vars\n");
	sprite_vars->draw_start_x = -sprite_vars->sprite_width / 2
		+ sprite_vars->sprite_screen_x;
	if (sprite_vars->draw_start_x < 0)
		sprite_vars->draw_start_x = 0;
	sprite_vars->draw_end_x = sprite_vars->sprite_width / 2
		+ sprite_vars->sprite_screen_x;
	if (sprite_vars->draw_end_x > display->width)
		sprite_vars->draw_end_x = display->width;
	// printf("End Aux Init Sprite Vars\n");
}

static void	init_sprite_vars(t_sprite_vars *sprite_vars, t_map *map,
	t_camera *camera, t_display *display)
{
	// printf("Start Init Sprite Vars\n");
	sprite_vars->inv_det = 1.0 / (camera->plane.x * camera->dir.y
			- camera->dir.x * camera->plane.y);
	sprite_vars->transform.x = sprite_vars->inv_det * (camera->dir.y
			* sprite_vars->sprite_coords.x - camera->dir.x
			* sprite_vars->sprite_coords.y);
	sprite_vars->transform.y = sprite_vars->inv_det * (-camera->plane.y
			* sprite_vars->sprite_coords.x + camera->plane.x
			* sprite_vars->sprite_coords.y);
	sprite_vars->v_move_screen = (int)(VMOVE / sprite_vars->transform.y);
	sprite_vars->sprite_screen_x = (int)((display->width / 2) * (1
				+ sprite_vars->transform.x / sprite_vars->transform.y));
	sprite_vars->sprite_height = abs((int)(display->height
				/ sprite_vars->transform.y)) / VDIV;
	sprite_vars->draw_start_y = -sprite_vars->sprite_height
		/ 2 + display->height / 2 + sprite_vars->v_move_screen;
	if (sprite_vars->draw_start_y < 0)
		sprite_vars->draw_start_y = 0;
	sprite_vars->draw_end_y = sprite_vars->sprite_height
		/ 2 + display->height / 2 + sprite_vars->v_move_screen;
	if (sprite_vars->draw_end_y >= display->height)
		sprite_vars->draw_end_y = display->height - 1;
	sprite_vars->sprite_width = abs((int)(display->height
				/ sprite_vars->transform.y)) / UDIV;
	aux_init_sprite_vars(sprite_vars, map, camera, display);
	// printf("End Init Sprite Vars\n");
}

static void	init_draw(t_sprite_vars *s_v, int stripe, t_camera *camera,
	t_display *display, t_map *map, int i, int x)
{
	unsigned int	color;
	int				y;
	int				d;

	// printf("Start Init Draw\n");
	s_v->tex_x = (int)
		(256 * (stripe - (-s_v->sprite_width / 2 + s_v->sprite_screen_x))
			* TEXTURE_WIDTH / s_v->sprite_width) / 256;
	if (s_v->transform.y > 0 && s_v->transform.y < camera->z_buffer[stripe])
	{
		y = s_v->draw_start_y;
		while (y > s_v->draw_end_y)
		{
			d = (y - s_v->v_move_screen) * 256 - display->height * 128
				+ s_v->sprite_height * 128;
			s_v->tex_y = ((d * TEXTURE_HEIGHT) / s_v->sprite_height) / 256;
			// color = ((unsigned int *)map->sprite_textures[map->sprites
			// 	[camera->sprite_order[i]].nb_texture].addr)[TEXTURE_WIDTH
			// 	* s_v->tex_y + s_v->tex_x];
			color = ((unsigned int *)map->textures[0].addr)[0];
			printf("End Init Draw\n");
			if ((color & 0x00FFFFFF) != 0)
				mlx_spp(display, stripe, y, color);
			++y;
		}
	}
}

static void	init_sprites(t_display *display, t_map *map, t_camera *camera,
	int x)
{
	t_sprite_vars	sprite_vars;
	int				i;
	int				stripe;

	i = 0;
	// printf("Start Init Sprite\n");
	while (i < map->total_sprites)
	{
		sprite_vars.sprite_coords.x = map->sprites[camera->sprite_order[i]].x
			- camera->pos.x;
		sprite_vars.sprite_coords.y = map->sprites[camera->sprite_order[i]].y
			- camera->pos.y;
		init_sprite_vars(&sprite_vars, map, camera, display);
		stripe = sprite_vars.draw_start_x;
		while (stripe < sprite_vars.draw_end_x)
			init_draw(&sprite_vars, stripe++, camera, display, map, i, x);
		++i;
	}
	// printf("End Init Sprite\n");
}

void	sprite_casting(t_display *display, t_map *map, t_camera *camera, int x)
{
	// printf("Start Sprite Casting\n");
	sort_sprites(camera->sprite_order, camera->sprite_distance,
		map->total_sprites);
	init_sprites(display, map, camera, x);
	// printf("End Sprite Casting\n");
}
