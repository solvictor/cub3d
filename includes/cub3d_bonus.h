/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:23:59 by tgernez           #+#    #+#             */
/*   Updated: 2023/08/02 18:13:40 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <float.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include "mlx.h"
# include "mlx_int.h"

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"

# define SPACES " \f\n\r\t\v"
# define PLAYER "NSEW"
# define FREE "0NSEW23"
# define COLLIDE "12"
# define MAP_CHARS "0NSEW123"
# define WALL_TYPES "0123"
# define DOOR "23"

# define ON_KEYPRESS 2
# define ON_KEYRELEASE 3
# define ON_MOUSEPRESS 4
# define ON_MOUSERELEASE 5
# define ON_DESTROY 17
# define NO_MASK 0L
# define KEYPRESS_MASK 1L
# define KEYRELEASE_MASK 2L
# define MOUSEPRESS_MASK 4L
# define MOUSERELEASE_MASK 8L

# define PI 3.14159265359

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define TILE_SIZE 10
# define PLAYER_RADIUS 3
# define INTERACTION_MESSAGE "Press E to interact with the door"
# define PARAMETER_NUMBER 7
# define TOTAL_WALL_TEXTURES 5

enum e_directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum e_cardinals
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST
};

/*
	Format for spites in file:
		S path-to-texture.xpm;x-coordinate(float),y-coordinate(float);
		x-coordinate(float),y-coordinate(float) (no \n, but line too long)
*/

typedef struct s_column
{
	int				draw_start;
	int				draw_end;
	unsigned int	color;
	int				texture_number;
	double			wall_x;
	int				texture_x;
	int				texture_y;
	double			texture_pos;
	double			step;
}					t_column;
typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_texture
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				height;
	int				width;
	int				bpp;
	int				size_line;
	int				endian;
}					t_texture;

typedef struct s_map
{
	int				ceiling_color;
	int				floor_color;
	char			*path_north;
	char			*path_south;
	char			*path_east;
	char			*path_west;
	char			*path_door_closed;
	int				total_parameters;
	int				param_lines[PARAMETER_NUMBER];
	int				height;
	int				width;
	int				first_line_map;
	int				start_coords[2];
	char			start_direction;
	int				islands;
	char			**map;
	t_texture		textures[5];
}					t_map;

typedef struct s_display
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				height;
	int				width;
	int				bpp;
	int				size_line;
	int				endian;
	bool			refresh;
	unsigned int	minimap_colors[4];
}					t_display;

typedef struct s_camera
{
	double			camera_x;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				side;
	t_vector		pos;
	t_vector		dir;
	t_vector		plane;
	t_vector		ray_dir;
	t_vector		side_dist;
	t_vector		delta_dist;
	double			move_speed;
	double			rot_speed;
	bool			w;
	bool			a;
	bool			s;
	bool			d;
	bool			l_key;
	bool			r_key;
	int				hit;
	float			angle;
}					t_camera;

typedef struct s_vars
{
	char			**file_content;
	t_map			*map;
	t_display		*display;
	t_camera		*camera;
}					t_vars;

/******************************************************************************/
/*                                                                            */
/*                                 Parsing                                    */
/*                                                                            */
/******************************************************************************/
bool			parsing(char *file_name, t_vars *vars, t_map *map);
bool			get_textures_info(t_vars *vars, t_map *map);
bool			map_size(t_vars *vars, t_map *map);
bool			map_correct(t_map *map);
bool			create_map(t_vars *vars, t_map *map);
void			format_map(t_map *map);
bool			do_textures_exist(t_map *map);
bool			find_extra_parameter(t_map *map, t_vars *vars);
bool			check_file_format(t_map *map);

/******************************************************************************/
/*                                                                            */
/*                                 Cleaning                                   */
/*                                                                            */
/******************************************************************************/
void			error_str(char *str);
void			clean_memory(t_vars *vars);
void			destroy_wall_images(t_display *display, t_map *map,
					const int ind);
void			destroy_sprite_images(t_display *display, t_map *map,
					const int ind);
void			destroy_window(t_display *display);
void			clean_map_variables(t_map *map);

/******************************************************************************/
/*                                                                            */
/*                                  Display                                   */
/*                                                                            */
/******************************************************************************/
bool			start_display(t_display *display, t_vars *vars);
bool			get_textures_walls(t_display *display, t_map *map);
bool			get_textures_sprites(t_display *display, t_map *map);
void			minimap(t_display *display, t_map *map, t_camera *camera);
int				on_destroy(t_vars *vars);
int				on_keypress(int keycode, t_vars *vars);
int				on_keyrelease(int keycode, t_vars *vars);
int				on_mousepress(int button, int x, int y, t_vars *vars);
int				on_mouserelease(int button, int x, int y, t_vars *vars);

/******************************************************************************/
/*                                                                            */
/*                                   Caster                                   */
/*                                                                            */
/******************************************************************************/
void			caster(t_display *display, t_map *map, t_camera *camera);
unsigned int	get_color(t_map *map, int id, int texture_x, int texture_y);
int				select_texture_wall(t_camera *camera);
void			draw_3d_walls(t_display *display, t_map *map, t_camera *camera,
					int x);
void			movement_selector(t_display *display, t_camera *camera,
					t_map *map);
void			mlx_spp(t_display *display, int x, int y, int color);
bool			door(t_map *map, t_camera *camera);
void			door_action(t_display *display, t_map *map, t_camera *camera);
void			r_key(t_display *display, t_camera *camera);
void			l_key(t_display *display, t_camera *camera);

/******************************************************************************/
/*                                                                            */
/*                                   Init                                     */
/*                                                                            */
/******************************************************************************/
void			init_position(t_camera *camera, char start_dir);
void			set_to_zero_camera(t_vars *vars, t_camera *camera);
bool			init_display(t_display *display);
void			set_to_zero_display(t_vars *vars, t_display *display);
void			set_to_zero_map(t_vars *vars, t_map *map);

/******************************************************************************/
/*                                                                            */
/*                                   Utils                                    */
/*                                                                            */
/******************************************************************************/
void			set_vector(t_vector *vector, double x, double y);
bool			is_line_empty(const char *line);
double			ft_atof(const char *str, bool *success);

#endif
