#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

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

# define ON_KEYDOWN 2
# define ON_MOUSEDOWN 4
# define ON_DESTROY 17
# define NO_MASK 0L
# define KEYPRESS_MASK 1L
# define BUTTONPRESS_MASK 4L
# define CURSOR_RADIUS 10

/*
	The map contains the '\n' at the end of the lines
*/
enum e_directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct s_point
{
	int			x;
	int			y;
	int			color;
}				t_point;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_camera
{
	t_vector	*direction;
	t_vector	*plane;
	float		delta_x;
	float		delta_y;
	float		angle;
}				t_camera;

/*
	Show a view line, then compute delta x and delta y that needs to be added
	to the player coordinates in order to make it advance (currecntly, going
	forward means going up, but in reality going forward should be going in
	the direction the player is looking to)
*/

typedef struct s_player
{
	int				x;
	int				y;
	int				square_x;
	int				square_y;
	int				speed;
	int				fov;
	int				direction;
	int				rotate_speed;
	float			angle;
	float			delta_x;
	float			delta_y;
}					t_player;

typedef struct s_map
{
	unsigned char	ceiling_color[3];
	unsigned char	floor_color[3];
	char			*path_north;
	char			*path_south;
	char			*path_east;
	char			*path_west;
	int				param_number;
	int				param_lines[6];
	int				height;
	int				width;
	int				first_line;
	int				start_coords[2];
	char			start_direction;
	int				islands;
	char			**map;
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
	int				square_length;
	bool			refresh;
}					t_display;

typedef struct s_vars
{
	char			**file_content;
	t_map			*map;
	t_display		*display;
	t_player		*player;
	t_camera		*camera;
}					t_vars;

/******************************************************************************/
/*                                                                            */
/*                                 Parsing                                    */
/*                                                                            */
/******************************************************************************/
bool	parsing(char *file_name, t_vars *vars, t_map *map);
bool	get_textures_info(t_vars *vars, t_map *map);
bool	map_size(t_vars *vars, t_map *map);
bool	map_correct(t_map *map);
bool	create_map(t_vars *vars, t_map *map);
void	format_map(t_map *map);
bool	count_islands(t_map *map);

/******************************************************************************/
/*                                                                            */
/*                                 Cleaning                                   */
/*                                                                            */
/******************************************************************************/
void	error_str(char *str);
void	clean_memory(t_vars *vars);

/******************************************************************************/
/*                                                                            */
/*                                  Display                                   */
/*                                                                            */
/******************************************************************************/
bool	start_display(t_display *display, t_vars *vars);
int		on_destroy(t_vars *vars);
int		on_keydown(int keycode, t_vars *vars);
void	mlx_spp(t_display *display, int x, int y, int color);
void	draw_line(t_display *display, t_point p1, t_point p2);

/******************************************************************************/
/*                                                                            */
/*                                   Utils                                    */
/*                                                                            */
/******************************************************************************/
int		biggest(int a, int b);
int		smallest(int a, int b);
bool	is_line_empty(const char *line);
double	deg_to_rad(int deg);
int		quadrant_of_angle(int deg);
void	set_vector(t_vector *vector, double x, double y);

/******************************************************************************/
/*                                                                            */
/*                                   Tests                                    */
/*                                                                            */
/******************************************************************************/
void	show_file(t_vars *vars);
void	show_texture_info(t_map *map);
void	show_map_info(t_map *map);
void	show_map(t_map *map);
void	draw_2d(t_display *display, t_map *map);
void	basic_up(t_vars *vars);
void	basic_down(t_vars *vars);
void	basic_left(t_vars *vars);
void	basic_right(t_vars *vars);
void	init_2d(t_display *display, t_map *map, t_player *player);
bool	colliding(int direction,
			t_map *map, t_player *player, t_display *display);
void	draw_player(t_display *display, t_player *player);
void	show_display_info(t_display *display, t_map *map);
void	draw_fov(t_display *display, t_player *player, t_map *map);
void	rotate_left(t_vars *vars);
void	rotate_right(t_vars *vars);
void	move_player(t_vars *vars);


#endif
