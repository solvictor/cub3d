/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:23:53 by tgernez           #+#    #+#             */
/*   Updated: 2023/08/02 17:25:13 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
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
# define FREE "0NSEW"
# define COLLIDE "1"
# define MAP_CHARS "0NSEW1"
# define WALL_TYPES "01"

# define ON_KEYPRESS 2
# define ON_KEYRELEASE 3
# define ON_MOUSEPRESS 4
# define ON_DESTROY 17
# define NO_MASK 0L
# define KEYPRESS_MASK 1L
# define KEYRELEASE_MASK 2L
# define BUTTONPRESS_MASK 4L
# define CURSOR_RADIUS 10

# define PI 3.14159265359

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

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
	double		x;
	double		y;
}				t_vector;

typedef struct s_texture
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			height;
	int			width;
	int			bpp;
	int			size_line;
	int			endian;
}				t_texture;

typedef struct s_map
{
	int			ceiling_color;
	int			floor_color;
	char		*path_north;
	char		*path_south;
	char		*path_east;
	char		*path_west;
	int			total_parameters;
	int			param_lines[6];
	int			height;
	int			width;
	int			first_line_map;
	int			start_coords[2];
	char		start_direction;
	int			islands;
	char		**map;
	t_texture	textures[4];
}				t_map;

typedef struct s_display
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			height;
	int			width;
	int			bpp;
	int			size_line;
	int			endian;
	bool		refresh;
}				t_display;

typedef struct s_camera
{
	double		camera_x;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			side;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_vector	ray_dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		move_speed;
	double		rot_speed;
	bool		w;
	bool		a;
	bool		s;
	bool		d;
	bool		l_key;
	bool		r_key;
}				t_camera;

typedef struct s_vars
{
	char		**file_content;
	t_map		*map;
	t_display	*display;
	t_camera	*camera;
}				t_vars;

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

/******************************************************************************/
/*                                                                            */
/*                                 Cleaning                                   */
/*                                                                            */
/******************************************************************************/
void			error_str(char *str);
void			clean_memory(t_vars *vars);
void			destroy_images(t_display *display, t_map *map, const int ind);

/******************************************************************************/
/*                                                                            */
/*                                  Display                                   */
/*                                                                            */
/******************************************************************************/
bool			start_display(t_display *display, t_vars *vars);
int				on_destroy(t_vars *vars);
int				on_keypress(int keycode, t_vars *vars);
int				on_keyrelease(int keycode, t_vars *vars);

/******************************************************************************/
/*                                                                            */
/*                                   Caster                                   */
/*                                                                            */
/******************************************************************************/
void			caster(t_display *display, t_map *map, t_camera *camera);
bool			get_textures(t_display *display, t_map *map);
unsigned int	get_color(t_map *map, int id, int texture_x, int texture_y);
int				select_texture(t_camera *camera);
void			draw_3d_walls(t_display *display, t_map *map, t_camera *camera,
					int x);
void			movement_selector(t_display *display, t_camera *camera,
					t_map *map);
void			r_key(t_display *display, t_camera *camera);
void			l_key(t_display *display, t_camera *camera);

/******************************************************************************/
/*                                                                            */
/*                                   Utils                                    */
/*                                                                            */
/******************************************************************************/
void			set_vector(t_vector *vector, double x, double y);
bool			is_line_empty(const char *line);

#endif
