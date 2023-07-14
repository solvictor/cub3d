#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <float.h>
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

# define PI 3.1415926535
# define P2 1.5707963268
# define P3 4.7123889803
# define DR 0.0174533 //1 deg to rad

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
bool		parsing(char *file_name, t_vars *vars, t_map *map);
bool		get_textures_info(t_vars *vars, t_map *map);
bool		map_size(t_vars *vars, t_map *map);
bool		map_correct(t_map *map);
bool		create_map(t_vars *vars, t_map *map);
void		format_map(t_map *map);
bool		count_islands(t_map *map);

/******************************************************************************/
/*                                                                            */
/*                                 Cleaning                                   */
/*                                                                            */
/******************************************************************************/
void		error_str(char *str);
void		clean_memory(t_vars *vars);

/******************************************************************************/
/*                                                                            */
/*                                  Display                                   */
/*                                                                            */
/******************************************************************************/
bool		start_display(t_display *display, t_vars *vars);
int			on_destroy(t_vars *vars);
int			on_keydown(int keycode, t_vars *vars);
void		mlx_spp(t_display *display, int x, int y, int color);
void		draw_vertical_line(int x, int y_start, int y_end,
				t_display *display);
void		draw_line(t_display *display, t_point p1, t_point p2);
void		clear_image(t_display *display);

/******************************************************************************/
/*                                                                            */
/*                                   Caster                                   */
/*                                                                            */
/******************************************************************************/
void	caster(t_display *display, t_map *map, t_camera *camera);

/******************************************************************************/
/*                                                                            */
/*                                   Utils                                    */
/*                                                                            */
/******************************************************************************/
int			biggest(int a, int b);
int			smallest(int a, int b);
bool		is_line_empty(const char *line);
double		deg_to_rad(int deg);
int			quadrant_of_angle(int deg);
float		hyp_v(t_vector v1, t_vector v2);
float		hyp(float x1, float y1, float x2, float y2);
void		correct_angle(float *angle);
void		set_vector(t_vector *vector, double x, double y);
t_vector	addition(t_vector v_a, t_vector v_b);
void		set_point(t_point *point, int x, int y, int color);

/******************************************************************************/
/*                                                                            */
/*                                   Tests                                    */
/*                                                                            */
/******************************************************************************/
void		show_file(t_vars *vars);
void		show_texture_info(t_map *map);
void		show_map_info(t_map *map);
void		show_map(t_map *map);
void		draw_2d(t_display *display, t_map *map);
void		basic_up(t_vars *vars);
void		basic_down(t_vars *vars);
void		basic_left(t_vars *vars);
void		basic_right(t_vars *vars);
void		rotate_left(t_vars *vars);
void		rotate_right(t_vars *vars);
void		move_player(t_vars *vars);


#endif
